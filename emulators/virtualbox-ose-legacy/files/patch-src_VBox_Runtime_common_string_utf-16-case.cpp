--- src/VBox/Runtime/common/string/utf-16-case.cpp.orig	2020-07-10 02:57:33.000000000 +1000
+++ src/VBox/Runtime/common/string/utf-16-case.cpp	2024-06-15 09:01:13.000000000 +1000
@@ -39,7 +39,7 @@
 #include "internal/string.h"
 
 
-RTDECL(int) RTUtf16ICmp(register PCRTUTF16 pwsz1, register PCRTUTF16 pwsz2)
+RTDECL(int) RTUtf16ICmp(PCRTUTF16 pwsz1, PCRTUTF16 pwsz2)
 {
     if (pwsz1 == pwsz2)
         return 0;
@@ -51,9 +51,9 @@
     PCRTUTF16 pwsz1Start = pwsz1; /* keep it around in case we have to backtrack on a surrogate pair */
     for (;;)
     {
-        register RTUTF16  wc1 = *pwsz1;
-        register RTUTF16  wc2 = *pwsz2;
-        register int     iDiff = wc1 - wc2;
+        RTUTF16  wc1 = *pwsz1;
+        RTUTF16  wc2 = *pwsz2;
+        int     iDiff = wc1 - wc2;
         if (iDiff)
         {
             /* unless they are *both* surrogate pairs, there is no chance they'll be identical. */
@@ -106,7 +106,7 @@
 RT_EXPORT_SYMBOL(RTUtf16ICmp);
 
 
-RTDECL(int) RTUtf16BigICmp(register PCRTUTF16 pwsz1, register PCRTUTF16 pwsz2)
+RTDECL(int) RTUtf16BigICmp(PCRTUTF16 pwsz1, PCRTUTF16 pwsz2)
 {
     if (pwsz1 == pwsz2)
         return 0;
@@ -118,9 +118,9 @@
     PCRTUTF16 pwsz1Start = pwsz1; /* keep it around in case we have to backtrack on a surrogate pair */
     for (;;)
     {
-        register RTUTF16  wc1 = *pwsz1;
-        register RTUTF16  wc2 = *pwsz2;
-        register int     iDiff = wc1 - wc2;
+        RTUTF16  wc1 = *pwsz1;
+        RTUTF16  wc2 = *pwsz2;
+        int     iDiff = wc1 - wc2;
         if (iDiff)
         {
             /* unless they are *both* surrogate pairs, there is no chance they'll be identical. */
@@ -216,7 +216,7 @@
 RT_EXPORT_SYMBOL(RTUtf16CmpIUtf8);
 
 
-RTDECL(int) RTUtf16NICmp(register PCRTUTF16 pwsz1, register PCRTUTF16 pwsz2, size_t cwcMax)
+RTDECL(int) RTUtf16NICmp(PCRTUTF16 pwsz1, PCRTUTF16 pwsz2, size_t cwcMax)
 {
     if (pwsz1 == pwsz2)
         return 0;
@@ -228,9 +228,9 @@
     PCRTUTF16 pwsz1Start = pwsz1; /* keep it around in case we have to backtrack on a surrogate pair */
     while (cwcMax-- > 0)
     {
-        register RTUTF16  wc1 = *pwsz1;
-        register RTUTF16  wc2 = *pwsz2;
-        register int     iDiff = wc1 - wc2;
+        RTUTF16  wc1 = *pwsz1;
+        RTUTF16  wc2 = *pwsz2;
+        int     iDiff = wc1 - wc2;
         if (iDiff)
         {
             /* unless they are *both* surrogate pairs, there is no chance they'll be identical. */
@@ -289,7 +289,7 @@
 RT_EXPORT_SYMBOL(RTUtf16NICmp);
 
 
-RTDECL(int) RTUtf16BigNICmp(register PCRTUTF16 pwsz1, register PCRTUTF16 pwsz2, size_t cwcMax)
+RTDECL(int) RTUtf16BigNICmp(PCRTUTF16 pwsz1, PCRTUTF16 pwsz2, size_t cwcMax)
 {
     if (pwsz1 == pwsz2)
         return 0;
@@ -301,9 +301,9 @@
     PCRTUTF16 pwsz1Start = pwsz1; /* keep it around in case we have to backtrack on a surrogate pair */
     while (cwcMax-- > 0)
     {
-        register RTUTF16  wc1 = *pwsz1;
-        register RTUTF16  wc2 = *pwsz2;
-        register int     iDiff = wc1 - wc2;
+        RTUTF16  wc1 = *pwsz1;
+        RTUTF16  wc2 = *pwsz2;
+        int     iDiff = wc1 - wc2;
         if (iDiff)
         {
             /* unless they are *both* surrogate pairs, there is no chance they'll be identical. */
