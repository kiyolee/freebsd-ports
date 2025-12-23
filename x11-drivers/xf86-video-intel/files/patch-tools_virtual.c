--- tools/virtual.c.orig	2025-12-24 00:30:28.824116000 +1100
+++ tools/virtual.c	2025-12-24 00:34:25.075901000 +1100
@@ -68,6 +68,10 @@
 #include <unistd.h>
 #include <fcntl.h>
 #include <assert.h>
+
+#ifndef ETIME
+#define ETIME 9935
+#endif
 
 #define FORCE_FULL_REDRAW 0
 #define FORCE_16BIT_XFER 0
