--- Utilities/cmcurl/lib/vtls/openssl.c.orig	2026-11-12 17:51:33.323133000 +1100
+++ Utilities/cmcurl/lib/vtls/openssl.c	2026-11-12 17:56:58.428647000 +1100
@@ -474,10 +474,19 @@
       break;
 
     num = X509_get_serialNumber(x);
+#if OPENSSL_VERSION_NUMBER >= 0x40100000L
+    if(ASN1_STRING_type(num) == V_ASN1_NEG_INTEGER)
+#else
     if(num->type == V_ASN1_NEG_INTEGER)
+#endif
       BIO_puts(mem, "-");
+#if OPENSSL_VERSION_NUMBER >= 0x40100000L
+    for(j = 0; j < ASN1_STRING_get_length(num); j++)
+      BIO_printf(mem, "%02x", ASN1_STRING_get0_data(num)[j]);
+#else
     for(j = 0; j < num->length; j++)
       BIO_printf(mem, "%02x", num->data[j]);
+#endif
     result = push_certinfo(data, mem, "Serial Number", i);
     if(result)
       break;
@@ -675,8 +684,13 @@
     }
 
     if(!result && psig) {
+#if OPENSSL_VERSION_NUMBER >= 0x40100000L
+      for(j = 0; j < ASN1_STRING_get_length(psig); j++)
+        BIO_printf(mem, "%02x:", ASN1_STRING_get0_data(psig)[j]);
+#else
       for(j = 0; j < psig->length; j++)
         BIO_printf(mem, "%02x:", psig->data[j]);
+#endif
       result = push_certinfo(data, mem, "Signature", i);
     }
 
