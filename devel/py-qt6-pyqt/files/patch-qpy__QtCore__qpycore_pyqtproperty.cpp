--- qpy/QtCore/qpycore_pyqtproperty.cpp.orig	2026-03-25 04:25:28.732108000 +1100
+++ qpy/QtCore/qpycore_pyqtproperty.cpp	2026-10-17 15:20:49.049941000 +1100
@@ -511,7 +511,7 @@
 static qpycore_pyqtProperty *clone(qpycore_pyqtProperty *orig)
 {
     qpycore_pyqtProperty *pp = (qpycore_pyqtProperty *)PyType_GenericNew(
-            Py_TYPE(orig), 0, 0);
+            Py_TYPE((PyObject *)orig), 0, 0);
 
     if (pp)
     {
