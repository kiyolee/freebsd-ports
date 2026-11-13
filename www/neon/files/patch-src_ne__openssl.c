--- src/ne_openssl.c.orig	2026-11-13 10:21:44.123315000 +1100
+++ src/ne_openssl.c	2026-11-13 10:54:17.029944000 +1100
@@ -36,9 +36,11 @@
 #include <openssl/rand.h>
 #include <openssl/opensslv.h>
 #include <openssl/evp.h>
+#include <openssl/asn1.h>
 
 #if OPENSSL_VERSION_NUMBER >= 0x10100000L
 #define HAVE_OPENSSL110
+#define HAVE_ASN1_TIME_TO_TM 1
 #endif
 
 #if defined(NE_HAVE_TS_SSL) && !defined(HAVE_OPENSSL110)
@@ -110,19 +112,28 @@
 {
     unsigned char *tmp = (unsigned char *)""; /* initialize to workaround 0.9.6 bug */
     int len;
+#if OPENSSL_VERSION_NUMBER >= 0x40100000L
+    const int str_type = ASN1_STRING_type(str);
+    const const char* str_data = (const char*)ASN1_STRING_get0_data(str);
+    const size_t str_length = ASN1_STRING_length(str);
+#else
+    const int str_type = str->type;
+    const const char* str_data = (const char*)str->data;
+    const size_t str_length = str->length;
+#endif
 
-    switch (str->type) {
+    switch (str_type) {
     case V_ASN1_IA5STRING: /* definitely ASCII */
     case V_ASN1_VISIBLESTRING: /* probably ASCII */
     case V_ASN1_PRINTABLESTRING: /* subset of ASCII */
-        ne_buffer_qappend(buf, str->data, str->length);
+        ne_buffer_qappend(buf, str_data, str_length);
         break;
     case V_ASN1_UTF8STRING:
         /* Fail for embedded NUL bytes. */
-        if (strlen((char *)str->data) != (size_t)str->length) {
+        if (strlen(str_data) != str_length) {
             return -1;
         }
-        ne_buffer_append(buf, (char *)str->data, str->length);
+        ne_buffer_append(buf, str_data, str_length);
         break;
     case V_ASN1_UNIVERSALSTRING:
     case V_ASN1_T61STRING: /* let OpenSSL convert it as ISO-8859-1 */
@@ -146,7 +157,7 @@
         break;
     default:
         NE_DEBUG(NE_DBG_SSL, "Could not convert DirectoryString type %d\n",
-                 str->type);
+                 str_type);
         return -1;
     }
     return 0;
@@ -156,7 +167,11 @@
  * safety. */
 static char *dup_ia5string(const ASN1_IA5STRING *as)
 {
+#if OPENSSL_VERSION_NUMBER >= 0x40100000L
+    return ne_strnqdup(ASN1_STRING_get0_data(as), ASN1_STRING_length(as));
+#else
     return ne_strnqdup(as->data, as->length);
+#endif
 }
 
 char *ne_ssl_readable_dname(const ne_ssl_dname *name)
@@ -208,8 +223,12 @@
 static time_t asn1time_to_timet(const ASN1_TIME *atm)
 {
     struct tm tm = {0};
-    int i = atm->length;
     
+#ifdef HAVE_ASN1_TIME_TO_TM
+    if (ASN1_TIME_to_tm(atm, &tm) != 1)
+        return (time_t)-1;
+#else
+    int i = atm->length;
     if (i < 10)
         return (time_t )-1;
 
@@ -224,8 +243,9 @@
     tm.tm_hour = (atm->data[6]-'0') * 10 + (atm->data[7]-'0');
     tm.tm_min = (atm->data[8]-'0') * 10 + (atm->data[9]-'0');
     tm.tm_sec = (atm->data[10]-'0') * 10 + (atm->data[11]-'0');
+#endif
 
-#ifdef HAVE_TIMEZONE
+#if defined(HAVE_TIMEZONE) && !defined(HAVE_ASN1_TIME_TO_TM)
     /* ANSI C time handling is... interesting. */
     return mktime(&tm) - timezone;
 #else
@@ -280,10 +300,17 @@
             else if (nm->type == GEN_IPADD && server && server->literal) {
                 /* compare IP addfress with server literal IP address. */
                 ne_inet_addr *ia;
+#if OPENSSL_VERSION_NUMBER >= 0x40100000L
+                if (ASN1_STRING_length(nm->d.ip) == 4)
+                    ia = ne_iaddr_make(ne_iaddr_ipv4, ASN1_STRING_get0_data(nm->d.ip));
+                else if (ASN1_STRING_length(nm->d.ip) == 16)
+                    ia = ne_iaddr_make(ne_iaddr_ipv6, ASN1_STRING_get0_data(nm->d.ip));
+#else
                 if (nm->d.ip->length == 4)
                     ia = ne_iaddr_make(ne_iaddr_ipv4, nm->d.ip->data);
                 else if (nm->d.ip->length == 16)
                     ia = ne_iaddr_make(ne_iaddr_ipv6, nm->d.ip->data);
+#endif
                 else
                     ia = NULL;
                 /* ne_iaddr_make returns NULL if address type is unsupported */
@@ -294,7 +321,12 @@
                 } else {
                     NE_DEBUG(NE_DBG_SSL, "iPAddress name with unsupported "
                              "address type (length %d), skipped.\n",
-                             nm->d.ip->length);
+#if OPENSSL_VERSION_NUMBER >= 0x40100000L
+                             ASN1_STRING_get0_data(nm->d.ip)
+#else
+                             nm->d.ip->length
+#endif
+                             );
                 }
             }
         }
@@ -305,8 +337,12 @@
     /* Check against the commonName if no DNS alt. names were found,
      * as per RFC3280. */
     if (!found) {
+#if OPENSSL_VERSION_NUMBER >= 0x40000000L
+	const X509_NAME *subj = X509_get_subject_name(cert);
+#else
 	X509_NAME *subj = X509_get_subject_name(cert);
-	X509_NAME_ENTRY *entry;
+#endif
+	const X509_NAME_ENTRY *entry;
 	ne_buffer *cname = ne_buffer_ncreate(30);
 	int idx = -1, lastidx;
 
