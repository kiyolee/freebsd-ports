--- Library/src/SSL/HTSSL.c.orig	2017-06-24 15:51:38.000000000 +1000
+++ Library/src/SSL/HTSSL.c	2026-11-13 12:04:51.154714000 +1100
@@ -98,6 +98,7 @@
 PRIVATE int verify_callback (int ok, X509_STORE_CTX * ctx)
 {
     char buf[256];
+    int ctx_error;
     X509 * err_cert = X509_STORE_CTX_get_current_cert(ctx);
     int err = X509_STORE_CTX_get_error(ctx);
     int depth = X509_STORE_CTX_get_error_depth(ctx);
@@ -115,24 +116,28 @@
 	    verify_error=X509_V_ERR_CERT_CHAIN_TOO_LONG;
 	}
     }
-    switch (ctx->error) {
+    switch (ctx_error = X509_STORE_CTX_get_error(ctx)) {
 
     case X509_V_ERR_UNABLE_TO_GET_ISSUER_CERT:
+#if OPENSSL_VERSION_NUMBER >= 0x10100000
+	X509_NAME_oneline(X509_get_issuer_name(X509_STORE_CTX_get0_cert(ctx)), buf, 256);
+#else
 	X509_NAME_oneline(X509_get_issuer_name(ctx->current_cert), buf, 256);
+#endif
 	HTTRACE(PROT_TRACE, "issuer= %s\n" _ buf);
 	break;
 
     case X509_V_ERR_CERT_NOT_YET_VALID:
     case X509_V_ERR_ERROR_IN_CERT_NOT_BEFORE_FIELD:
 	HTTRACE(PROT_TRACE, "notBefore=");
-//	ASN1_TIME_print(bio_err,X509_get_notBefore(ctx->current_cert));
+//	ASN1_TIME_print(bio_err,X509_get_notBefore(X509_STORE_CTX_get0_cert(ctx)));
 	HTTRACE(PROT_TRACE, "\n");
 	break;
 
     case X509_V_ERR_CERT_HAS_EXPIRED:
     case X509_V_ERR_ERROR_IN_CERT_NOT_AFTER_FIELD:
 	HTTRACE(PROT_TRACE, "notAfter=");
-//	ASN1_TIME_print(bio_err,X509_get_notAfter(ctx->current_cert));
+//	ASN1_TIME_print(bio_err,X509_get_notAfter(X509_STORE_CTX_get0_cert(ctx)));
 	HTTRACE(PROT_TRACE, "\n");
 	break;
     }
@@ -207,19 +212,20 @@
     RAND_load_file(rnd_filename, -1);
     
     if (!app_ctx) {
+#if OPENSSL_VERSION_NUMBER >= 0x40100000L
+	const SSL_METHOD * meth = NULL;
+#else
 	SSL_METHOD * meth = NULL;
+#endif
         SSLeay_add_ssl_algorithms();
 	/* Seems to provide English error messages */
         SSL_load_error_strings();
 
 	/* select the protocol method */
+#if OPENSSL_VERSION_NUMBER >= 0x40100000L
+	meth = TLS_client_method();
+#else
 	switch (ssl_prot_method) {
-	case HTSSL_V2:
-	  meth = SSLv2_client_method();
-	  break;
-	case HTSSL_V3:
-	  meth = SSLv3_client_method();
-	  break;
 	case HTSSL_V23:
 	  meth = SSLv23_client_method();
 	  break;
@@ -228,6 +234,7 @@
 	  meth = TLSv1_client_method();
 	  break;
 	}
+#endif
 
         /* set up the application context */
 	if ((app_ctx = SSL_CTX_new(meth)) == NULL) {
