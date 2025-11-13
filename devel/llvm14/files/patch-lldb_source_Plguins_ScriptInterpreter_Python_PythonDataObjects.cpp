--- lldb/source/Plugins/ScriptInterpreter/Python/PythonDataObjects.cpp.orig	2022-06-23 02:46:24.000000000 +1000
+++ lldb/source/Plugins/ScriptInterpreter/Python/PythonDataObjects.cpp	2025-11-13 22:23:38.293612000 +1100
@@ -72,6 +72,8 @@
 static bool python_is_finalizing() {
 #if PY_MAJOR_VERSION == 2
   return false;
+#elif (PY_MAJOR_VERSION == 3 && PY_MINOR_VERSION >= 13) || (PY_MAJOR_VERSION > 3)
+  return Py_IsFinalizing();
 #elif PY_MAJOR_VERSION == 3 && PY_MINOR_VERSION < 7
   return _Py_Finalizing != nullptr;
 #else
