--- src/VBox/Runtime/common/table/avl_Get.cpp.h.orig	2020-07-10 02:57:33.000000000 +1000
+++ src/VBox/Runtime/common/table/avl_Get.cpp.h	2024-06-15 09:00:10.000000000 +1000
@@ -37,7 +37,7 @@
  */
 KAVL_DECL(PKAVLNODECORE) KAVL_FN(Get)(PPKAVLNODECORE ppTree, KAVLKEY Key)
 {
-    register PKAVLNODECORE  pNode = KAVL_GET_POINTER_NULL(ppTree);
+    PKAVLNODECORE  pNode = KAVL_GET_POINTER_NULL(ppTree);
 
     if (pNode)
     {
