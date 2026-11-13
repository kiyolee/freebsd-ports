--- src/tspi/tspi_asn1.c.orig	2026-11-12 17:12:01.205827000 +1100
+++ src/tspi/tspi_asn1.c	2026-11-12 17:13:29.591697000 +1100
@@ -237,7 +237,11 @@
 
 	if (*rawBlobSize != 0) {
 		if (decBlobSize <= *rawBlobSize) {
+#if OPENSSL_VERSION_NUMBER >= 0x40100000L
+			memcpy(rawBlob, ASN1_STRING_get0_data(tssBlob->blob), decBlobSize);
+#else
 			memcpy(rawBlob, tssBlob->blob->data, decBlobSize);
+#endif
 		}
 		else {
 			TSS_BLOB_free(tssBlob);
