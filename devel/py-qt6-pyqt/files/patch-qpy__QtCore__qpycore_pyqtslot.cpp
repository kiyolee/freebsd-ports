--- qpy/QtCore/qpycore_pyqtslot.cpp.orig	2026-03-25 04:25:28.741840800 +1100
+++ qpy/QtCore/qpycore_pyqtslot.cpp	2026-10-17 15:20:49.065072000 +1100
@@ -207,7 +207,11 @@
 {
     // Use the weak reference if possible.
     if (mself_wr)
-        return PyWeakref_GetObject(mself_wr);
+    {
+        PyObject *pobj;
+        if (PyWeakref_GetRef(mself_wr, &pobj) == 1)
+            return pobj;
+    }
 
     return mself;
 }
