--- buckets/ssl_buckets.c.orig	2023-05-18 19:33:55.000000000 +1000
+++ buckets/ssl_buckets.c	2026-11-12 17:02:12.580938000 +1100
@@ -567,12 +567,23 @@
             switch (nm->type) {
                 case GEN_DNS:
                     if (copy_action == ErrorOnNul &&
-                        strlen(nm->d.ia5->data) != nm->d.ia5->length)
+#if OPENSSL_VERSION_NUMBER >= 0x40100000L
+                        strlen(ASN1_STRING_get0_data(nm->d.ia5)) != ASN1_STRING_get_length(nm->d.ia5)
+#else
+                        strlen(nm->d.ia5->data) != nm->d.ia5->length
+#endif
+                       )
                         return SERF_ERROR_SSL_CERT_FAILED;
                     if (san_arr && *san_arr)
+#if OPENSSL_VERSION_NUMBER >= 0x40100000L
+                        p = pstrdup_escape_nul_bytes((const char *)ASN1_STRING_get0_data(nm->d.ia5),
+                                                     ASN1_STRING_get_length(nm->d.ia5),
+                                                     pool);
+#else
                         p = pstrdup_escape_nul_bytes((const char *)nm->d.ia5->data,
                                                      nm->d.ia5->length,
                                                      pool);
+#endif
                     break;
                 default:
                     /* Don't know what to do - skip. */
@@ -1186,7 +1197,7 @@
         }
 #endif
 
-#ifdef USE_OPENSSL_1_1_API
+#if defined(USE_OPENSSL_1_1_API) && !defined(LIBRESSL_VERSION_NUMBER)
         OPENSSL_malloc_init();
 #else
         CRYPTO_malloc_init();
