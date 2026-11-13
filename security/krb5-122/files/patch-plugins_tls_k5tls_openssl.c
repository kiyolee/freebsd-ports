--- plugins/tls/k5tls/openssl.c.orig	2026-11-07 10:01:49.000000000 +1100
+++ plugins/tls/k5tls/openssl.c	2026-11-12 17:34:08.659276000 +1100
@@ -162,7 +162,11 @@
 get_cert_sans(const X509 *x)
 {
     int ext;
+#if OPENSSL_VERSION_NUMBER >= 0x40100000L
+    const X509_EXTENSION *san_ext;
+#else
     X509_EXTENSION *san_ext;
+#endif
 
     ext = X509_get_ext_by_NID(x, NID_subject_alt_name, -1);
     if (ext < 0)
@@ -178,7 +182,11 @@
 static int
 get_cert_cn(const X509 *x, char *buf, size_t bufsize)
 {
+#if OPENSSL_VERSION_NUMBER >= 0x40100000L
+    const X509_NAME *name;
+#else
     X509_NAME *name;
+#endif
 
     name = X509_get_subject_name(x);
     if (name == NULL)
