--- SSLeay.xs.orig	2026-03-21 11:37:38.000000000 +1100
+++ SSLeay.xs	2026-11-12 16:42:03.015192000 +1100
@@ -2194,35 +2194,42 @@
 
 time_t ASN1_TIME_timet(ASN1_TIME *asn1t, time_t *gmtoff) {
     struct tm t;
-    const char *p = (const char*) asn1t->data;
+#if (OPENSSL_VERSION_NUMBER >= 0x1010000f && !defined(LIBRESSL_VERSION_NUMBER)) || (LIBRESSL_VERSION_NUMBER >= 0x2070000fL)
+    const char *p = (const char*) ASN1_STRING_get0_data(asn1t);
+    size_t asn1t_length = ASN1_STRING_get_length(asn1t);
+#else
+    const char *p = (const char*) ASN1_STRING_data(asn1t);
+    size_t asn1t_length = ASN1_STRING_length(asn1t);
+#endif
+    int asn1t_type = ASN1_STRING_type(asn1t);
     size_t msec = 0, tz = 0, i, l;
     time_t result;
     int adj = 0;
 
-    if (asn1t->type == V_ASN1_UTCTIME) {
-	if (asn1t->length<12 || asn1t->length>17) return 0;
-	if (asn1t->length>12) tz = 12;
+    if (asn1t_type == V_ASN1_UTCTIME) {
+	if (asn1t_length<12 || asn1t_length>17) return 0;
+	if (asn1t_length>12) tz = 12;
     } else {
-	if (asn1t->length<14) return 0;
-	if (asn1t->length>14) {
+	if (asn1t_length<14) return 0;
+	if (asn1t_length>14) {
 	    if (p[14] == '.') {
 		msec = 14;
-		for(i=msec+1;i<asn1t->length && p[i]>='0' && p[i]<='9';i++) ;
-		if (i<asn1t->length) tz = i;
+		for(i=msec+1;i<asn1t_length && p[i]>='0' && p[i]<='9';i++) ;
+		if (i<asn1t_length) tz = i;
 	    } else {
 		tz = 14;
 	    }
 	}
     }
 
-    l = msec ? msec : tz ? tz : asn1t->length;
+    l = msec ? msec : tz ? tz : asn1t_length;
     for(i=0;i<l;i++) {
 	if (p[i]<'0' || p[i]>'9') return 0;
     }
 
     /* extract data and time */
     OPENSSL_cleanse(&t, sizeof(t));
-    if (asn1t->type == V_ASN1_UTCTIME) { /* YY - two digit year */
+    if (asn1t_type == V_ASN1_UTCTIME) { /* YY - two digit year */
 	t.tm_year = (p[0]-'0')*10 + (p[1]-'0');
 	if (t.tm_year < 70) t.tm_year += 100;
 	i=2;
@@ -2242,11 +2249,11 @@
     if (tz) {
 	/* TZ is 'Z' or [+-]DDDD and after TZ the string must stop*/
 	if (p[tz] == 'Z') {
-	    if (asn1t->length>tz+1 ) return 0;
-	} else if (asn1t->length<tz+5 || (p[tz]!='-' && p[tz]!='+')) {
+	    if (asn1t_length>tz+1 ) return 0;
+	} else if (asn1t_length<tz+5 || (p[tz]!='-' && p[tz]!='+')) {
 	    return 0;
 	} else {
-	    if (asn1t->length>tz+5 ) return 0;
+	    if (asn1t_length>tz+5 ) return 0;
 	    for(i=tz+1;i<tz+5;i++) {
 		if (p[i]<'0' || p[i]>'9') return 0;
 	    }
@@ -2454,7 +2461,7 @@
 
 #endif
 #endif
-#ifndef OPENSSL_NO_SSL3
+#if !defined(OPENSSL_NO_SSL3) && OPENSSL_VERSION_NUMBER < 0x40000000L
 
 SSL_CTX *
 SSL_CTX_v3_new()
@@ -2472,7 +2479,7 @@
      OUTPUT:
      RETVAL
 
-#if !defined(OPENSSL_NO_TLS1_METHOD)
+#if !defined(OPENSSL_NO_TLS1_METHOD) && OPENSSL_VERSION_NUMBER < 0x40000000L
 
 SSL_CTX *
 SSL_CTX_tlsv1_new()
@@ -2481,10 +2488,25 @@
      OUTPUT:
      RETVAL
 
-#endif
+#else
+#if (OPENSSL_VERSION_NUMBER >= 0x40000000L)
 
-#if (OPENSSL_VERSION_NUMBER >= 0x10001001L && !defined(OPENSSL_NO_TLS1_1_METHOD)) /* OpenSSL 1.0.1-beta1 */
+SSL_CTX *
+SSL_CTX_tlsv1_new()
+     CODE:
+     RETVAL = SSL_CTX_new(TLS_method());
+     if (RETVAL) {
+          SSL_CTX_set_min_proto_version(RETVAL, TLS1_VERSION);
+          SSL_CTX_set_max_proto_version(RETVAL, TLS1_VERSION);
+     }
+     OUTPUT:
+     RETVAL
 
+#endif
+#endif
+
+#if (OPENSSL_VERSION_NUMBER >= 0x10001001L && OPENSSL_VERSION_NUMBER < 0x40000000L && !defined(OPENSSL_NO_TLS1_1_METHOD)) /* OpenSSL 1.0.1-beta1 */
+
 SSL_CTX *
 SSL_CTX_tlsv1_1_new()
      CODE:
@@ -2492,18 +2514,48 @@
      OUTPUT:
      RETVAL
 
+#else
+#if (OPENSSL_VERSION_NUMBER >= 0x40000000L)
+
+SSL_CTX *
+SSL_CTX_tlsv1_1_new()
+     CODE:
+     RETVAL = SSL_CTX_new(TLS_method());
+     if (RETVAL) {
+          SSL_CTX_set_min_proto_version(RETVAL, TLS1_1_VERSION);
+          SSL_CTX_set_max_proto_version(RETVAL, TLS1_1_VERSION);
+     }
+     OUTPUT:
+     RETVAL
+
 #endif
+#endif
 
-#if (OPENSSL_VERSION_NUMBER >= 0x10001001L && !defined(OPENSSL_NO_TLS1_2_METHOD)) /* OpenSSL 1.0.1-beta1 */
+#if (OPENSSL_VERSION_NUMBER >= 0x10001001L && OPENSSL_VERSION_NUMBER < 0x40000000L && !defined(OPENSSL_NO_TLS1_2_METHOD)) /* OpenSSL 1.0.1-beta1 */
 
 SSL_CTX *
 SSL_CTX_tlsv1_2_new()
      CODE:
      RETVAL = SSL_CTX_new (TLSv1_2_method());
+     OUTPUT:
+     RETVAL
+
+#else
+#if (OPENSSL_VERSION_NUMBER >= 0x40000000L)
+
+SSL_CTX *
+SSL_CTX_tlsv1_2_new()
+     CODE:
+     RETVAL = SSL_CTX_new(TLS_method());
+     if (RETVAL) {
+          SSL_CTX_set_min_proto_version(RETVAL, TLS1_2_VERSION);
+          SSL_CTX_set_max_proto_version(RETVAL, TLS1_2_VERSION);
+     }
      OUTPUT:
      RETVAL
 
 #endif
+#endif
 
 SSL_CTX *
 SSL_CTX_new_with_method(meth)
@@ -4483,8 +4535,7 @@
                 if (override) continue; /* don't override existing extension */
                 /* Delete all extensions of same type */
                 do {
-                    tmpext = X509_get_ext(x509, idx);
-                    X509_delete_ext(x509, idx);
+                    tmpext = X509_delete_ext(x509, idx);
                     X509_EXTENSION_free(tmpext);
                     idx = X509_get_ext_by_OBJ(x509, obj, -1);
                 } while (idx != -1);
@@ -4651,7 +4702,13 @@
                          EXTEND(SP, 2);
                          count++;
                          PUSHs(sv_2mortal(newSViv(subjAltNameDN->type)));
-                         PUSHs(sv_2mortal(newSVpv((const char*)subjAltNameDN->d.ip->data, subjAltNameDN->d.ip->length)));
+#if OPENSSL_VERSION_NUMBER >= 0x40100000L && !defined(LIBRESSL_VERSION_NUMBER)
+                         PUSHs(sv_2mortal(newSVpv((const char*)ASN1_STRING_get0_data(subjAltNameDN->d.ip), ASN1_STRING_get_length(subjAltNameDN->d.ip))));
+#elif (OPENSSL_VERSION_NUMBER >= 0x1010000f && !defined(LIBRESSL_VERSION_NUMBER)) || (LIBRESSL_VERSION_NUMBER >= 0x2070000fL)
+                         PUSHs(sv_2mortal(newSVpv((const char*)ASN1_STRING_get0_data(subjAltNameDN->d.ip), ASN1_STRING_length(subjAltNameDN->d.ip))));
+#else
+                         PUSHs(sv_2mortal(newSVpv((const char*)ASN1_STRING_data(subjAltNameDN->d.ip), ASN1_STRING_length(subjAltNameDN->d.ip))));
+#endif
                          break;
 
                      }
@@ -5190,15 +5247,20 @@
      ASN1_TIME_to_generalizedtime(tm,&tmp);
      if (tmp) {
        if (ASN1_GENERALIZEDTIME_check(tmp)) {
-         if (strlen((char*)tmp->data)>=14 && strlen((char*)tmp->data)<200) {
+#if (OPENSSL_VERSION_NUMBER >= 0x1010000f && !defined(LIBRESSL_VERSION_NUMBER)) || (LIBRESSL_VERSION_NUMBER >= 0x2070000fL)
+         const char *tmp_data = (const char*)ASN1_STRING_get0_data(tmp);
+#else
+         const char *tmp_data = (const char*)ASN1_STRING_data(tmp);
+#endif
+         if (strlen(tmp_data)>=14 && strlen(tmp_data)<200) {
            strcpy (buf,"yyyy-mm-ddThh:mm:ss");
-           strncpy(buf,   (char*)tmp->data,   4);
-           strncpy(buf+5, (char*)tmp->data+4, 2);
-           strncpy(buf+8, (char*)tmp->data+6, 2);
-           strncpy(buf+11,(char*)tmp->data+8, 2);
-           strncpy(buf+14,(char*)tmp->data+10,2);
-           strncpy(buf+17,(char*)tmp->data+12,2);
-           if (strlen((char*)tmp->data)>14) strcat(buf+19,(char*)tmp->data+14);
+           strncpy(buf,   tmp_data,   4);
+           strncpy(buf+5, tmp_data+4, 2);
+           strncpy(buf+8, tmp_data+6, 2);
+           strncpy(buf+11,tmp_data+8, 2);
+           strncpy(buf+14,tmp_data+10,2);
+           strncpy(buf+17,tmp_data+12,2);
+           if (strlen(tmp_data)>14) strcat(buf+19,tmp_data+14);
          }
        }
        ASN1_GENERALIZEDTIME_free(tmp);
@@ -5211,7 +5273,6 @@
      ASN1_TIME *tm
      const char *str
      PREINIT:
-     ASN1_TIME t;
      char buf[256];
      int i,rv;
      CODE:
@@ -5233,22 +5294,27 @@
      buf[14] = '\0';
      if (strlen(str)>19 && strlen(str)<200) strcat(buf,str+19);
 
-     /* WORKAROUND: ASN1_TIME_set_string() not available in 0.9.8 !!!*/
-     /* in 1.0.0 we would simply: rv = ASN1_TIME_set_string(tm,buf); */
-     t.length = strlen(buf);
-     t.data = (unsigned char *)buf;
-     t.flags = 0;
-     t.type = V_ASN1_UTCTIME;
-     if (!ASN1_TIME_check(&t)) {
-        t.type = V_ASN1_GENERALIZEDTIME;
-        if (!ASN1_TIME_check(&t)) XSRETURN_UNDEF;
+     /* ASN1_TIME_set_string() not available in 0.9.8 */
+#if OPENSSL_VERSION_NUMBER >= 0x10000000L
+     rv = ASN1_TIME_set_string(tm, buf);
+     if (!rv) XSRETURN_UNDEF;
+#else
+     {
+        ASN1_TIME t;
+        t.length = strlen(buf);
+        t.data = (unsigned char *)buf;
+        t.flags = 0;
+        t.type = V_ASN1_UTCTIME;
+        if (!ASN1_TIME_check(&t)) {
+           t.type = V_ASN1_GENERALIZEDTIME;
+           if (!ASN1_TIME_check(&t)) XSRETURN_UNDEF;
+        }
+        tm->type = t.type;
+        tm->flags = t.flags;
+        if (!ASN1_STRING_set(tm,t.data,t.length)) XSRETURN_UNDEF;
+        rv = 1;
      }
-     tm->type = t.type;
-     tm->flags = t.flags;
-     if (!ASN1_STRING_set(tm,t.data,t.length)) XSRETURN_UNDEF;
-     rv = 1;
-
-     /* end of ASN1_TIME_set_string() reimplementation */
+#endif
 
      ST(0) = sv_newmortal();
      sv_setiv(ST(0), rv); /* 1 = success, undef = failure */
@@ -5600,7 +5666,7 @@
 #endif
 #endif
 
-#ifndef OPENSSL_NO_SSL3
+#if !defined(OPENSSL_NO_SSL3) && OPENSSL_VERSION_NUMBER < 0x40000000L
 
 const SSL_METHOD *
 SSLv3_method()
@@ -5616,7 +5682,7 @@
 const SSL_METHOD *
 SSLv23_client_method()
 
-#if !defined(OPENSSL_NO_TLS1_METHOD)
+#if !defined(OPENSSL_NO_TLS1_METHOD) && OPENSSL_VERSION_NUMBER < 0x40000000L
 
 const SSL_METHOD *
 TLSv1_method()
@@ -5629,7 +5695,7 @@
 
 #endif
 
-#if (OPENSSL_VERSION_NUMBER >= 0x10001001L && !defined(OPENSSL_NO_TLS1_1_METHOD)) /* OpenSSL 1.0.1-beta1 */
+#if (OPENSSL_VERSION_NUMBER >= 0x10001001L && OPENSSL_VERSION_NUMBER < 0x40000000L && !defined(OPENSSL_NO_TLS1_1_METHOD)) /* OpenSSL 1.0.1-beta1 */
 
 const SSL_METHOD *
 TLSv1_1_method()
@@ -5642,7 +5708,7 @@
 
 #endif
 
-#if (OPENSSL_VERSION_NUMBER >= 0x10001001L && !defined(OPENSSL_NO_TLS1_2_METHOD)) /* OpenSSL 1.0.1-beta1 */
+#if (OPENSSL_VERSION_NUMBER >= 0x10001001L && OPENSSL_VERSION_NUMBER < 0x40000000L && !defined(OPENSSL_NO_TLS1_2_METHOD)) /* OpenSSL 1.0.1-beta1 */
 
 const SSL_METHOD *
 TLSv1_2_method()
