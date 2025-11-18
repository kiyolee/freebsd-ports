--- buildscripts/moduleconfig.py.orig	2025-07-08 09:12:17.000000000 +1000
+++ buildscripts/moduleconfig.py	2025-11-18 00:15:24.658783000 +1100
@@ -27,7 +27,7 @@
 __all__ = ('discover_modules', 'discover_module_directories', 'configure_modules',
            'register_module_test')  # pylint: disable=undefined-all-variable
 
-import imp
+import importlib.util
 import inspect
 import os
 
@@ -68,16 +68,14 @@
 
         try:
             print("adding module: %s" % (name))
-            fp = open(build_py, "r")
-            try:
-                module = imp.load_module("module_" + name, fp, build_py,
-                                         (".py", "r", imp.PY_SOURCE))
+            spec = importlib.util.spec_from_file_location("module_" + name, build_py)
+            if spec and spec.loader:
+                module = importlib.util.module_from_spec(spec)
+                spec.loader.exec_module(module)
                 if getattr(module, "name", None) is None:
                     module.name = name
                 found_modules.append(module)
                 found_module_names.append(name)
-            finally:
-                fp.close()
         except (FileNotFoundError, IOError):
             pass
 
