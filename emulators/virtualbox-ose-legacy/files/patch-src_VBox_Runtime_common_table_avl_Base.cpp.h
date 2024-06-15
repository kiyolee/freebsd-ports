--- src/VBox/Runtime/common/table/avl_Base.cpp.h.orig	2020-07-10 02:57:33.000000000 +1000
+++ src/VBox/Runtime/common/table/avl_Base.cpp.h	2024-06-15 08:59:39.000000000 +1000
@@ -266,7 +266,7 @@
         }
         else
         {
-            register unsigned char uchHeight = (unsigned char)(KMAX(uchLeftHeight, uchRightHeight) + 1);
+            unsigned char uchHeight = (unsigned char)(KMAX(uchLeftHeight, uchRightHeight) + 1);
             if (uchHeight == pNode->uchHeight)
                 break;
             pNode->uchHeight = uchHeight;
@@ -300,10 +300,10 @@
 {
     KAVLSTACK               AVLStack;
     PPKAVLNODECORE          ppCurNode = ppTree;
-    register PKAVLNODECORE  pCurNode;
-    register KAVLKEY        Key = pNode->Key; NOREF(Key);
+    PKAVLNODECORE  pCurNode;
+    KAVLKEY        Key = pNode->Key; NOREF(Key);
 #ifdef KAVL_RANGE
-    register KAVLKEY        KeyLast = pNode->KeyLast; NOREF(KeyLast);
+    KAVLKEY        KeyLast = pNode->KeyLast; NOREF(KeyLast);
 #endif
 
     AVLStack.cEntries = 0;
@@ -400,7 +400,7 @@
 {
     KAVLSTACK                AVLStack;
     PPKAVLNODECORE           ppDeleteNode = ppTree;
-    register PKAVLNODECORE   pDeleteNode;
+    PKAVLNODECORE   pDeleteNode;
 
     AVLStack.cEntries = 0;
 
@@ -427,7 +427,7 @@
         /* find the rightmost node in the left tree. */
         const unsigned          iStackEntry = AVLStack.cEntries;
         PPKAVLNODECORE          ppLeftLeast = &pDeleteNode->pLeft;
-        register PKAVLNODECORE  pLeftLeast = KAVL_GET_POINTER(ppLeftLeast);
+        PKAVLNODECORE  pLeftLeast = KAVL_GET_POINTER(ppLeftLeast);
 
         while (pLeftLeast->pRight != KAVL_NULL)
         {
