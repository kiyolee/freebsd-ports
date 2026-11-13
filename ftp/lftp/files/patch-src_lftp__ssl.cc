--- src/lftp_ssl.cc.orig	2026-11-13 16:22:41.659184000 +1100
+++ src/lftp_ssl.cc	2026-11-13 16:26:04.904014000 +1100
@@ -988,8 +988,13 @@
 int lftp_ssl_openssl::verify_crl(X509_STORE_CTX *ctx)
 {
     X509_OBJECT *obj=0;
+#if OPENSSL_VERSION_NUMBER >= 0x40100000L
+    const X509_NAME *subject=0;
+    const X509_NAME *issuer=0;
+#else
     X509_NAME *subject=0;
     X509_NAME *issuer=0;
+#endif
     X509 *xs=0;
     X509_CRL *crl=0;
     X509_REVOKED *revoked=0;
@@ -1402,7 +1407,11 @@
     unsigned char *nulstr = (unsigned char *)"";
     unsigned char *peer_CN = nulstr;
 
+#if OPENSSL_VERSION_NUMBER >= 0x40100000L
+    const X509_NAME *name = X509_get_subject_name(server_cert) ;
+#else
     X509_NAME *name = X509_get_subject_name(server_cert) ;
+#endif
     if(name)
       while((j = X509_NAME_get_index_by_NID(name, NID_commonName, i))>=0)
         i=j;
@@ -1412,7 +1421,11 @@
        UTF8 etc. */
 
     if(i>=0) {
+#if OPENSSL_VERSION_NUMBER >= 0x40100000L
+      const ASN1_STRING *tmp = X509_NAME_ENTRY_get_data(X509_NAME_get_entry(name,i));
+#else
       ASN1_STRING *tmp = X509_NAME_ENTRY_get_data(X509_NAME_get_entry(name,i));
+#endif
 
       /* In OpenSSL 0.9.7d and earlier, ASN1_STRING_to_UTF8 fails if the input
          is already UTF-8 encoded. We check for this case and copy the raw
@@ -1488,8 +1501,13 @@
    if(cert!=prev_cert)
    {
       int depth          = X509_STORE_CTX_get_error_depth(ctx);
+#if OPENSSL_VERSION_NUMBER >= 0x40100000L
+      const X509_NAME *subject = X509_get_subject_name(cert);
+      const X509_NAME *issuer  = X509_get_issuer_name(cert);
+#else
       X509_NAME *subject = X509_get_subject_name(cert);
       X509_NAME *issuer  = X509_get_issuer_name(cert);
+#endif
       char *subject_line = X509_NAME_oneline(subject, NULL, 0);
       char *issuer_line  = X509_NAME_oneline(issuer, NULL, 0);
       Log::global->Format(3,"Certificate depth: %d; subject: %s; issuer: %s\n",
