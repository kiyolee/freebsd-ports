--- xio-openssl.c.orig	2026-11-13 13:46:28.765336000 +1100
+++ xio-openssl.c	2026-11-13 13:47:48.932136000 +1100
@@ -1898,8 +1898,13 @@
 		  case GEN_IPADD:
 		     {
 			/* binary address format */
+#if OPENSSL_VERSION_NUMBER >= 0x40100000L
+			const unsigned char *data = ASN1_STRING_get0_data(pName->d.iPAddress);
+			size_t len = ASN1_STRING_length(pName->d.iPAddress);
+#else
 			const unsigned char *data = pName->d.iPAddress->data;
 			size_t len = pName->d.iPAddress->length;
+#endif
 			char aBuffer[INET6_ADDRSTRLEN]; 	/* canonical peername */
 			struct in6_addr ip6bin;
 
