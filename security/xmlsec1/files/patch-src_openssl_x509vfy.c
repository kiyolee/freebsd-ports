--- src/openssl/x509vfy.c.orig	2026-11-13 16:34:09.785010000 +1100
+++ src/openssl/x509vfy.c	2026-11-13 16:56:53.050172000 +1100
@@ -444,7 +444,11 @@
             }
             /* ret = 1: asn1_time is later than time */
             if (ret > 0) {
+#if OPENSSL_VERSION_NUMBER >= 0x40100000L
+                const X509_NAME *issuer;
+#else
                 X509_NAME *issuer;
+#endif
                 char issuer_name[256];
                 time_t ts;
 
@@ -497,7 +501,11 @@
         if(crl == NULL) {
             continue;
         }
+#if OPENSSL_VERSION_NUMBER >= 0x40100000L
+        crl_issuer = (X509_NAME*)X509_CRL_get_issuer(crl);
+#else
         crl_issuer = X509_CRL_get_issuer(crl);
+#endif
         if(crl_issuer == NULL) {
             continue;
         }
@@ -564,7 +572,11 @@
      * Try to retrieve a CRL corresponding to the issuer of
      * the current certificate
      */
+#if OPENSSL_VERSION_NUMBER >= 0x40100000L
+    cert_issuer = (X509_NAME*)X509_get_issuer_name(cert);
+#else
     cert_issuer = X509_get_issuer_name(cert);
+#endif
     if(cert_issuer == NULL) {
         xmlSecOpenSSLError("X509_get_issuer_name", NULL);
         return(-1);
@@ -1474,7 +1486,11 @@
         return(0);
     }
 
+#if OPENSSL_VERSION_NUMBER >= 0x40100000L
+    certSubjectName = (X509_NAME*)X509_get_subject_name(cert);
+#else
     certSubjectName = X509_get_subject_name(cert);
+#endif
     if(certSubjectName == NULL) {
         return(0);
     }
@@ -1500,11 +1516,19 @@
         return(0);
     }
 
+#if OPENSSL_VERSION_NUMBER >= 0x40100000L
+    certSerial = (ASN1_INTEGER*)X509_get_serialNumber(cert);
+#else
     certSerial = X509_get_serialNumber(cert);
+#endif
     if((certSerial == NULL) || (ASN1_INTEGER_cmp(certSerial, issuerSerial) != 0)) {
         return(0);
     }
+#if OPENSSL_VERSION_NUMBER >= 0x40100000L
+    certName = (X509_NAME*)X509_get_issuer_name(cert);
+#else
     certName = X509_get_issuer_name(cert);
+#endif
     if((certName == NULL) || (xmlSecOpenSSLX509NamesCompare(certName, issuerName) != 0)) {
         return(0);
     }
@@ -1529,7 +1553,11 @@
     if(index < 0) {
         return(0);
     }
+#if OPENSSL_VERSION_NUMBER >= 0x40100000L
+    ext = (X509_EXTENSION*)X509_get_ext(cert, index);
+#else
     ext = X509_get_ext(cert, index);
+#endif
     if(ext == NULL) {
         return(0);
     }
@@ -1537,7 +1565,11 @@
     if(keyId == NULL) {
         return(0);
     }
+#if OPENSSL_VERSION_NUMBER >= 0x40100000L
+    if((ASN1_STRING_length(keyId) != skiLen) || (memcmp(ASN1_STRING_get0_data(keyId), ski, (size_t)skiLen) != 0)) {
+#else
     if((keyId->length != skiLen) || (memcmp(keyId->data, ski, (size_t)skiLen) != 0)) {
+#endif
         ASN1_OCTET_STRING_free(keyId);
         return(0);
     }
@@ -1628,7 +1660,11 @@
 
     xmlSecAssert2(x != NULL, 0);
 
+#if OPENSSL_VERSION_NUMBER >= 0x40100000L
+    name = (X509_NAME*)X509_get_subject_name(x);
+#else
     name = X509_get_subject_name(x);
+#endif
     if(name == NULL) {
         xmlSecOpenSSLError("X509_get_subject_name", NULL);
         return(0);
@@ -1650,7 +1686,11 @@
 
     xmlSecAssert2(x != NULL, 0);
 
+#if OPENSSL_VERSION_NUMBER >= 0x40100000L
+    name = (X509_NAME*)X509_get_issuer_name(x);
+#else
     name = X509_get_issuer_name(x);
+#endif
     if(name == NULL) {
         xmlSecOpenSSLError("X509_get_issuer_name", NULL);
         return(0);
@@ -1894,7 +1934,11 @@
     }
 
     for (ii = X509_NAME_entry_count(a) - 1; ii >= 0; --ii) {
+#if OPENSSL_VERSION_NUMBER >= 0x40100000L
+        ret = sk_X509_NAME_ENTRY_push(res, (X509_NAME_ENTRY*)X509_NAME_get_entry(a, ii));
+#else
         ret = sk_X509_NAME_ENTRY_push(res, X509_NAME_get_entry(a, ii));
+#endif
         if(ret <= 0) {
             xmlSecOpenSSLError("sk_X509_NAME_ENTRY_push", NULL);
             return(NULL);
@@ -1999,8 +2043,13 @@
 
 
     /* first compare values */
+#if OPENSSL_VERSION_NUMBER >= 0x40100000L
+    a_value = (ASN1_STRING*)X509_NAME_ENTRY_get_data((X509_NAME_ENTRY*)(*a));
+    b_value = (ASN1_STRING*)X509_NAME_ENTRY_get_data((X509_NAME_ENTRY*)(*b));
+#else
     a_value = X509_NAME_ENTRY_get_data((X509_NAME_ENTRY*)(*a));
     b_value = X509_NAME_ENTRY_get_data((X509_NAME_ENTRY*)(*b));
+#endif
 
     if((a_value == NULL) && (b_value != NULL)) {
         return(-1);
@@ -2027,8 +2076,13 @@
     }
 
     /* next compare names */
+#if OPENSSL_VERSION_NUMBER >= 0x40100000L
+    a_name = (ASN1_OBJECT*)X509_NAME_ENTRY_get_object((X509_NAME_ENTRY*)(*a));
+    b_name = (ASN1_OBJECT*)X509_NAME_ENTRY_get_object((X509_NAME_ENTRY*)(*b));
+#else
     a_name = X509_NAME_ENTRY_get_object((X509_NAME_ENTRY*)(*a));
     b_name = X509_NAME_ENTRY_get_object((X509_NAME_ENTRY*)(*b));
+#endif
 
     if((a_name == NULL) && (b_name != NULL)) {
         return(-1);
