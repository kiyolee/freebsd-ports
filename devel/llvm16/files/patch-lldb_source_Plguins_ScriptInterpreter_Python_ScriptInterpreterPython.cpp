--- lldb/source/Plugins/ScriptInterpreter/Python/ScriptInterpreterPython.cpp.orig	2023-06-11 08:58:16.000000000 +1000
+++ lldb/source/Plugins/ScriptInterpreter/Python/ScriptInterpreterPython.cpp	2025-11-13 23:21:31.048963000 +1100
@@ -177,18 +177,26 @@
       return;
 #endif
 
+#if (PY_MAJOR_VERSION == 3 && PY_MINOR_VERSION < 9) || (PY_MAJOR_VERSION < 3)
     if (PyEval_ThreadsInitialized()) {
+#else
+    if (true) {
+#endif
       Log *log = GetLog(LLDBLog::Script);
 
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
