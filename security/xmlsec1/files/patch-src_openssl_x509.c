--- src/openssl/x509.c.orig	2026-11-13 16:43:39.398361000 +1100
+++ src/openssl/x509.c	2026-11-13 16:46:57.507936000 +1100
@@ -1015,7 +1015,11 @@
         goto done;
     }
 
+#if OPENSSL_VERSION_NUMBER >= 0x40100000L
+    ext = (X509_EXTENSION*)X509_get_ext(cert, index);
+#else
     ext = X509_get_ext(cert, index);
+#endif
     if (ext == NULL) {
         xmlSecOpenSSLError("X509_get_ext", NULL);
         goto done;
@@ -1300,7 +1304,11 @@
         if (XMLSEC_X509DATA_HAS_EMPTY_NODE(content, XMLSEC_X509DATA_SUBJECTNAME_NODE)) {
             xmlSecAssert2(x509Value->subject == NULL, -1);
 
+#if OPENSSL_VERSION_NUMBER >= 0x40100000L
+            x509Value->subject = xmlSecOpenSSLX509NameWrite((X509_NAME*)X509_get_subject_name(cert));
+#else
             x509Value->subject = xmlSecOpenSSLX509NameWrite(X509_get_subject_name(cert));
+#endif
             if(x509Value->subject == NULL) {
                 xmlSecInternalError2("xmlSecOpenSSLX509NameWrite(X509_get_subject_name)",
                     xmlSecKeyDataGetName(data),
@@ -1312,7 +1320,11 @@
             xmlSecAssert2(x509Value->issuerName == NULL, -1);
             xmlSecAssert2(x509Value->issuerSerial == NULL, -1);
 
+#if OPENSSL_VERSION_NUMBER >= 0x40100000L
+            x509Value->issuerName = xmlSecOpenSSLX509NameWrite((X509_NAME*)X509_get_issuer_name(cert));
+#else
             x509Value->issuerName = xmlSecOpenSSLX509NameWrite(X509_get_issuer_name(cert));
+#endif
             if(x509Value->issuerName == NULL) {
                 xmlSecInternalError2("xmlSecOpenSSLX509NameWrite(X509_get_issuer_name)",
                     xmlSecKeyDataGetName(data),
