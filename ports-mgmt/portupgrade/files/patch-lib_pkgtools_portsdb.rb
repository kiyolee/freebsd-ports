--- lib/pkgtools/portsdb.rb.orig	2024-06-23 20:18:39.858835000 +1000
+++ lib/pkgtools/portsdb.rb	2024-06-23 20:18:51.148731000 +1000
@@ -329,7 +329,7 @@
   end
 
   def subdirs(dir)
-    %x"fgrep SUBDIR #{dir}/Makefile | sed -e 's/SUBDIR +=//'
+    %x"/usr/bin/fgrep SUBDIR #{dir}/Makefile | sed -e 's/SUBDIR +=//'
        2> /dev/null".split.select { |i|
       File.directory?(File.join(dir, i))
     }.sort
