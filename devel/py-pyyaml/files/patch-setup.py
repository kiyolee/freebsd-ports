--- setup.py.orig	2025-08-09 00:33:00.912430000 +1000
+++ setup.py	2025-08-09 00:33:26.194244000 +1000
@@ -82,7 +82,7 @@
     with_cython = True
 try:
     from Cython.Distutils.extension import Extension as _Extension
-    from Cython.Distutils import build_ext as _build_ext
+    from Cython.Distutils.old_build_ext import old_build_ext as _build_ext
     with_cython = True
 except ImportError:
     if with_cython:
