--- setup.py.orig	2026-08-11 21:35:55.769072800 +1000
+++ setup.py	2026-11-28 02:51:09.722135000 +1100
@@ -12,9 +12,9 @@
 import sysconfig
 import tempfile
 
-if not ssl.HAS_TLSv1_2:
+if not ssl.HAS_TLSv1_2 and not ssl.HAS_TLSv1_3:
     error = """
-The `ssl` module does not advertise support for TLS 1.2.
+The `ssl` module does not advertise support for TLS 1.2 or TLS 1.3.
 Please make sure that your Python installation was compiled against an OpenSSL
 version enabling these features (likely this requires the OpenSSL version to
 be at least 1.0.1).
@@ -401,7 +401,7 @@
                 )
 
             for rustext in ruststandalones:
-                rustext.build('' if self.editable_mode else self.build_lib)
+                rustext.build(self.build_lib)
 
         return build_ext.build_extensions(self)
 
@@ -495,12 +495,8 @@
             ]
         )
 
-        if self.editable_mode:
-            here = os.path.dirname(__file__)
-            basepath = os.path.join(here, 'mercurial')
-        else:
-            basepath = os.path.join(self.build_lib, 'mercurial')
-            self.mkpath(basepath)
+        basepath = os.path.join(self.build_lib, 'mercurial')
+        self.mkpath(basepath)
 
         write_if_changed(os.path.join(basepath, '__modulepolicy__.py'), content)
 
