--- lldb/source/Plugins/ScriptInterpreter/Python/ScriptInterpreterPython.cpp.orig	2022-06-23 02:46:24.000000000 +1000
+++ lldb/source/Plugins/ScriptInterpreter/Python/ScriptInterpreterPython.cpp	2025-11-13 22:30:31.690497000 +1100
@@ -200,18 +200,26 @@
       return;
 #endif
 
+#if (PY_MAJOR_VERSION == 3 && PY_MINOR_VERSION < 9) || (PY_MAJOR_VERSION < 3)
     if (PyEval_ThreadsInitialized()) {
+#else
+    if (true) {
+#endif
       Log *log(lldb_private::GetLogIfAllCategoriesSet(LIBLLDB_LOG_SCRIPT));
 
       m_was_already_initialized = true;
       m_gil_state = PyGILState_Ensure();
       LLDB_LOGV(log, "Ensured PyGILState. Previous state = {0}locked\n",
                 m_gil_state == PyGILState_UNLOCKED ? "un" : "");
+#if (PY_MAJOR_VERSION == 3 && PY_MINOR_VERSION < 9) || (PY_MAJOR_VERSION < 3)
       return;
     }
 
     // InitThreads acquires the GIL if it hasn't been called before.
     PyEval_InitThreads();
+#else
+    }
+#endif
   }
 
   PyGILState_STATE m_gil_state = PyGILState_UNLOCKED;
