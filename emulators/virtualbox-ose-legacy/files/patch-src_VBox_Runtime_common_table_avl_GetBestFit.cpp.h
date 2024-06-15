--- src/VBox/Runtime/common/table/avl_GetBestFit.cpp.h.orig	2020-07-10 02:57:33.000000000 +1000
+++ src/VBox/Runtime/common/table/avl_GetBestFit.cpp.h	2024-06-15 09:02:16.000000000 +1000
@@ -43,7 +43,7 @@
  */
 KAVL_DECL(PKAVLNODECORE) KAVL_FN(GetBestFit)(PPKAVLNODECORE ppTree, KAVLKEY Key, bool fAbove)
 {
-    register PKAVLNODECORE  pNode = KAVL_GET_POINTER_NULL(ppTree);
+    PKAVLNODECORE  pNode = KAVL_GET_POINTER_NULL(ppTree);
     if (pNode)
     {
         PKAVLNODECORE           pNodeLast = NULL;
