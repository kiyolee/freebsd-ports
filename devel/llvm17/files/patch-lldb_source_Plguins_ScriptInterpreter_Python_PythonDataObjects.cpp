--- lldb/source/Plugins/ScriptInterpreter/Python/PythonDataObjects.cpp.orig	2023-11-28 19:52:28.000000000 +1100
+++ lldb/source/Plugins/ScriptInterpreter/Python/PythonDataObjects.cpp	2025-11-13 23:37:54.480472000 +1100
@@ -71,7 +71,9 @@
 }
 
 static bool python_is_finalizing() {
-#if PY_MAJOR_VERSION == 3 && PY_MINOR_VERSION < 7
+#if (PY_MAJOR_VERSION == 3 && PY_MINOR_VERSION >= 13) || (PY_MAJOR_VERSION > 3)
+  return Py_IsFinalizing();
+#elif PY_MAJOR_VERSION == 3 && PY_MINOR_VERSION < 7
   return _Py_Finalizing != nullptr;
 #else
   return _Py_IsFinalizing();
