--- src/VBox/Runtime/common/log/logcom.cpp.orig	2020-07-10 02:57:28.000000000 +1000
+++ src/VBox/Runtime/common/log/logcom.cpp	2024-06-15 08:58:29.000000000 +1000
@@ -120,8 +120,8 @@
     const uint8_t *pu8;
     for (pu8 = (const uint8_t *)pach; cb-- > 0; pu8++)
     {
-        register unsigned cMaxWait;
-        register uint8_t  u8;
+        unsigned cMaxWait;
+        uint8_t  u8;
 
         /* expand \n -> \r\n */
         if (*pu8 == '\n')
