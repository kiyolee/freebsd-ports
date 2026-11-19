--- Modules/_ssl.c.orig	2026-11-14 05:28:52.270550000 +1100
+++ Modules/_ssl.c	2026-11-14 05:35:47.053432000 +1100
@@ -124,7 +124,9 @@
 
 /* Include generated data (error codes) */
 /* See make_ssl_data.h for notes on adding a new version. */
-#if (OPENSSL_VERSION_NUMBER >= 0x30401000L)
+#if (OPENSSL_VERSION_NUMBER >= 0x40000000L)
+#include "_ssl_data_40.h"
+#elif (OPENSSL_VERSION_NUMBER >= 0x30401000L)
 #include "_ssl_data_35.h"
 #elif (OPENSSL_VERSION_NUMBER >= 0x30100000L)
 #include "_ssl_data_340.h"
@@ -136,6 +138,17 @@
 #error Unsupported OpenSSL version
 #endif
 
+#if (OPENSSL_VERSION_NUMBER >= 0x40000000L)
+#  define OPENSSL_NO_SSL3
+#  define OPENSSL_NO_TLS1
+#  define OPENSSL_NO_TLS1_1
+#  define OPENSSL_NO_TLS1_2
+#  define OPENSSL_NO_SSL3_METHOD
+#  define OPENSSL_NO_TLS1_METHOD
+#  define OPENSSL_NO_TLS1_1_METHOD
+#  define OPENSSL_NO_TLS1_2_METHOD
+#endif
+
 /* OpenSSL API 1.1.0+ does not include version methods */
 #ifndef OPENSSL_NO_SSL3_METHOD
 extern const SSL_METHOD *SSLv3_method(void);
