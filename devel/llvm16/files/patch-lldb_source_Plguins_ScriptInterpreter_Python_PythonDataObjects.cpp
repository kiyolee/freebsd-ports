--- lldb/source/Plugins/ScriptInterpreter/Python/PythonDataObjects.cpp.orig	2023-06-11 08:58:16.000000000 +1000
+++ lldb/source/Plugins/ScriptInterpreter/Python/PythonDataObjects.cpp	2025-11-13 23:21:30.994822000 +1100
@@ -70,7 +70,9 @@
 }
 
 static bool python_is_finalizing() {
-#if PY_MAJOR_VERSION == 3 && PY_MINOR_VERSION < 7
+#if (PY_MAJOR_VERSION == 3 && PY_MINOR_VERSION >= 13) || (PY_MAJOR_VERSION > 3)
+  return Py_IsFinalizing();
+#elif PY_MAJOR_VERSION == 3 && PY_MINOR_VERSION < 7
   return _Py_Finalizing != nullptr;
 #else
   return _Py_IsFinalizing();
