--- src/VBox/Runtime/common/string/utf-16.cpp.orig	2020-07-10 02:57:33.000000000 +1000
+++ src/VBox/Runtime/common/string/utf-16.cpp	2024-06-15 09:01:43.000000000 +1000
@@ -194,7 +194,7 @@
 RT_EXPORT_SYMBOL(RTUtf16Len);
 
 
-RTDECL(int) RTUtf16Cmp(register PCRTUTF16 pwsz1, register PCRTUTF16 pwsz2)
+RTDECL(int) RTUtf16Cmp(PCRTUTF16 pwsz1, PCRTUTF16 pwsz2)
 {
     if (pwsz1 == pwsz2)
         return 0;
@@ -205,8 +205,8 @@
 
     for (;;)
     {
-        register RTUTF16  wcs = *pwsz1;
-        register int     iDiff = wcs - *pwsz2;
+        RTUTF16  wcs = *pwsz1;
+        int     iDiff = wcs - *pwsz2;
         if (iDiff || !wcs)
             return iDiff;
         pwsz1++;
