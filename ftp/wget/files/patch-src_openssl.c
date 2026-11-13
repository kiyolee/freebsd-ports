--- src/openssl.c.orig	2026-11-12 17:41:48.583979000 +1100
+++ src/openssl.c	2026-11-12 17:43:24.132105000 +1100
@@ -226,7 +226,7 @@
       break;
 
     case secure_protocol_sslv3:
-#ifndef OPENSSL_NO_SSL3_METHOD
+#if !defined OPENSSL_NO_SSL3_METHOD && OPENSSL_VERSION_NUMBER < 0x40100000L
       meth = SSLv3_client_method ();
 #endif
       break;
