--- SSLeay.xs.orig	2014-04-24 08:36:24.000000000 +1000
+++ SSLeay.xs	2026-11-13 11:43:31.539651000 +1100
@@ -144,22 +144,30 @@
              */
             RAND_seed(buf, CRYPT_SSLEAY_RAND_BUFSIZE);
         }
-
+#if OPENSSL_VERSION_NUMBER >= 0x40100000L
+        ctx = SSL_CTX_new(SSLv23_client_method());
+#else
         if(ssl_version == 23) {
             ctx = SSL_CTX_new(SSLv23_client_method());
         }
+#ifndef OPENSSL_NO_SSL3
         else if(ssl_version == 3) {
             ctx = SSL_CTX_new(SSLv3_client_method());
         }
+#endif
         else {
 #ifndef OPENSSL_NO_SSL2
             /* v2 is the default */
             ctx = SSL_CTX_new(SSLv2_client_method());
-#else
+#elif !defined(OPENSSL_NO_SSL3)
             /* v3 is the default */
             ctx = SSL_CTX_new(SSLv3_client_method());
+#else
+            /* v23 is the default */
+            ctx = SSL_CTX_new(SSLv23_client_method());
 #endif
         }
+#endif
 
         SSL_CTX_set_options(ctx,SSL_OP_ALL|0);
         SSL_CTX_set_default_verify_paths(ctx);
@@ -513,7 +521,11 @@
 get_notBeforeString(cert)
          X509* cert
          CODE:
+#if OPENSSL_VERSION_NUMBER >= 0x40100000L
+            RETVAL = (char *)ASN1_STRING_get0_data(X509_get_notBefore(cert));
+#else
             RETVAL = (char *)X509_get_notBefore(cert)->data;
+#endif
          OUTPUT:
             RETVAL
 
@@ -521,7 +533,11 @@
 get_notAfterString(cert)
          X509* cert
          CODE:
+#if OPENSSL_VERSION_NUMBER >= 0x40100000L
+            RETVAL = (char *)ASN1_STRING_get0_data(X509_get_notAfter(cert));
+#else
             RETVAL = (char *)X509_get_notAfter(cert)->data;
+#endif
          OUTPUT:
             RETVAL
 
