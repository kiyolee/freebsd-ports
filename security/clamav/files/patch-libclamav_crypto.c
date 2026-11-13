--- libclamav/crypto.c.orig	2026-08-07 09:55:20.000000000 +1000
+++ libclamav/crypto.c	2026-11-13 18:50:41.585362000 +1100
@@ -1766,10 +1766,18 @@
     struct tm localtm;
 #endif
 
+#if OPENSSL_VERSION_NUMBER >= 0x40100000L
+    if (!(timeobj) || !(ASN1_STRING_get0_data(timeobj)))
+#else
     if (!(timeobj) || !(timeobj->data))
+#endif
         return NULL;
 
+#if OPENSSL_VERSION_NUMBER >= 0x40100000L
+    str = (char *)(ASN1_STRING_get0_data(timeobj));
+#else
     str = (char *)(timeobj->data);
+#endif
     if (strlen(str) < 12)
         return NULL;
 
@@ -1777,7 +1785,11 @@
     if (!(t))
         return NULL;
 
+#if OPENSSL_VERSION_NUMBER >= 0x40100000L
+    if (ASN1_STRING_type(timeobj) == V_ASN1_UTCTIME) {
+#else
     if (timeobj->type == V_ASN1_UTCTIME) {
+#endif
         /* two digit year */
         fmt = "%y%m%d%H%M%S";
         if (str[3] == '0') {
@@ -1786,7 +1798,11 @@
         } else {
             str[3]--;
         }
+#if OPENSSL_VERSION_NUMBER >= 0x40100000L
+    } else if (ASN1_STRING_type(timeobj) == V_ASN1_GENERALIZEDTIME) {
+#else
     } else if (timeobj->type == V_ASN1_GENERALIZEDTIME) {
+#endif
         /* four digit year */
         fmt = "%Y%m%d%H%M%S";
         if (str[5] == '0') {
