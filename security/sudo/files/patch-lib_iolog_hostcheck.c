--- lib/iolog/hostcheck.c.orig	2024-12-30 04:11:14.000000000 +1100
+++ lib/iolog/hostcheck.c	2026-11-12 10:51:40.291827000 +1100
@@ -131,10 +131,18 @@
  *          MatchNotFound
  */
 static HostnameValidationResult
+#if OPENSSL_VERSION_NUMBER >= 0x40100000L
+validate_name(const char *hostname, const ASN1_STRING *certname_asn1)
+#else
 validate_name(const char *hostname, ASN1_STRING *certname_asn1)
+#endif
 {
     char *certname_s = (char *)ASN1_STRING_get0_data(certname_asn1);
+#if OPENSSL_VERSION_NUMBER >= 0x40100000L
+    size_t certname_len = ASN1_STRING_get_length(certname_asn1);
+#else
     size_t certname_len = (size_t)ASN1_STRING_length(certname_asn1);
+#endif
     size_t hostname_len = strlen(hostname);
     debug_decl(validate_name, SUDO_DEBUG_UTIL);
 
@@ -188,8 +196,13 @@
 static HostnameValidationResult
 matches_common_name(const char *hostname, const char *ipaddr, const X509 *cert, int resolve)
 {
+#if OPENSSL_VERSION_NUMBER >= 0x40100000L
+	const X509_NAME_ENTRY *common_name_entry = NULL;
+	const ASN1_STRING *common_name_asn1 = NULL;
+#else
 	X509_NAME_ENTRY *common_name_entry = NULL;
 	ASN1_STRING *common_name_asn1 = NULL;
+#endif
  	int common_name_loc;
 	debug_decl(matches_common_name, SUDO_DEBUG_UTIL);
 
@@ -211,7 +224,11 @@
 		debug_return_int(Error);
 	}			
 	const unsigned char *common_name_str = ASN1_STRING_get0_data(common_name_asn1);
+#if OPENSSL_VERSION_NUMBER >= 0x40100000L
+	const size_t common_name_length = ASN1_STRING_get_length(common_name_asn1);
+#else
 	const size_t common_name_length = (size_t)ASN1_STRING_length(common_name_asn1);
+#endif
 
 	/* Make sure there isn't an embedded NUL character in the CN */
 	if (memchr(common_name_str, '\0', common_name_length) != NULL) {
@@ -286,7 +303,11 @@
 
         if (current_name->type == GEN_DNS) {
             const unsigned char *dns_name = ASN1_STRING_get0_data(current_name->d.dNSName);
+#if OPENSSL_VERSION_NUMBER >= 0x40100000L
+	    const size_t dns_name_length = ASN1_STRING_get_length(current_name->d.dNSName);
+#else
 	    const size_t dns_name_length = (size_t)ASN1_STRING_length(current_name->d.dNSName);
+#endif
 
             /* Make sure there isn't an embedded NUL character in the DNS name */
             if (memchr(dns_name, '\0', dns_name_length) != NULL) {
@@ -323,14 +344,22 @@
 #endif
 
             /* IPV4 address */
+#if OPENSSL_VERSION_NUMBER >= 0x40100000L
+            if(ASN1_STRING_get_length(current_name->d.iPAddress) == 4) {
+#else
             if(current_name->d.iPAddress->length == 4) {
+#endif
                 if (inet_ntop(AF_INET, san_ip, san_ip_str, INET_ADDRSTRLEN) == NULL) {
                     result = MalformedCertificate;
                     break;
                 }
 #if defined(HAVE_STRUCT_IN6_ADDR)
             /* IPV6 address */
+#if OPENSSL_VERSION_NUMBER >= 0x40100000L
+            } else if (ASN1_STRING_get_length(current_name->d.iPAddress) == 16) {
+#else
             } else if (current_name->d.iPAddress->length == 16) {
+#endif
                 if (inet_ntop(AF_INET6, san_ip, san_ip_str, INET6_ADDRSTRLEN) == NULL) {
                     result = MalformedCertificate;
                     break;
