--- src/VBox/Runtime/common/table/avl_Range.cpp.h.orig	2020-07-10 02:57:33.000000000 +1000
+++ src/VBox/Runtime/common/table/avl_Range.cpp.h	2024-06-15 09:02:41.000000000 +1000
@@ -35,9 +35,9 @@
  * @param     ppTree  Pointer to Pointer to the tree root node.
  * @param     Key     The Key to find matching range for.
  */
-KAVL_DECL(PKAVLNODECORE) KAVL_FN(RangeGet)(PPKAVLNODECORE ppTree, register KAVLKEY Key)
+KAVL_DECL(PKAVLNODECORE) KAVL_FN(RangeGet)(PPKAVLNODECORE ppTree, KAVLKEY Key)
 {
-    register PKAVLNODECORE  pNode = KAVL_GET_POINTER_NULL(ppTree);
+    PKAVLNODECORE  pNode = KAVL_GET_POINTER_NULL(ppTree);
     if (pNode)
     {
         for (;;)
