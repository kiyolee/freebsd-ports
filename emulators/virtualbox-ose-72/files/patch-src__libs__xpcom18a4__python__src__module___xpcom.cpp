--- src/libs/xpcom18a4/python/src/module/_xpcom.cpp.orig	2026-09-22 18:19:44.000000000 +1000
+++ src/libs/xpcom18a4/python/src/module/_xpcom.cpp	2026-10-21 04:06:52.932860000 +1100
@@ -79,11 +79,31 @@
 #  define MANGLE_MODULE_INIT(a_Name)    RT_CONCAT(a_Name, MODULE_NAME_SUFFIX)
 # endif
 # if defined(VBOX_PYXPCOM_VERSIONED) && !defined(VBOX_PYXPCOM_MAJOR_VERSIONED)
-#  if   PY_VERSION_HEX >= 0x030a0000 && PY_VERSION_HEX < 0x030b0000
+#  if   PY_VERSION_HEX >= 0x030f0000 && PY_VERSION_HEX < 0x03100000
+#   define MODULE_NAME    MANGLE_MODULE_NAME("VBoxPython3_15")
+#   define initVBoxPython MANGLE_MODULE_INIT(PyInit_VBoxPython3_15)
+
+#  elif PY_VERSION_HEX >= 0x030e0000 && PY_VERSION_HEX < 0x030f0000
+#   define MODULE_NAME    MANGLE_MODULE_NAME("VBoxPython3_14")
+#   define initVBoxPython MANGLE_MODULE_INIT(PyInit_VBoxPython3_14)
+
+#  elif PY_VERSION_HEX >= 0x030d0000 && PY_VERSION_HEX < 0x030e0000
+#   define MODULE_NAME    MANGLE_MODULE_NAME("VBoxPython3_13")
+#   define initVBoxPython MANGLE_MODULE_INIT(PyInit_VBoxPython3_13)
+
+#  elif PY_VERSION_HEX >= 0x030c0000 && PY_VERSION_HEX < 0x030d0000
+#   define MODULE_NAME    MANGLE_MODULE_NAME("VBoxPython3_12")
+#   define initVBoxPython MANGLE_MODULE_INIT(PyInit_VBoxPython3_12)
+
+#  elif PY_VERSION_HEX >= 0x030b0000 && PY_VERSION_HEX < 0x030c0000
+#   define MODULE_NAME    MANGLE_MODULE_NAME("VBoxPython3_11")
+#   define initVBoxPython MANGLE_MODULE_INIT(PyInit_VBoxPython3_11)
+
+#  elif PY_VERSION_HEX >= 0x030a0000 && PY_VERSION_HEX < 0x030b0000
 #   define MODULE_NAME    MANGLE_MODULE_NAME("VBoxPython3_10")
 #   define initVBoxPython MANGLE_MODULE_INIT(PyInit_VBoxPython3_10)
 
-#  elif   PY_VERSION_HEX >= 0x03090000 && PY_VERSION_HEX < 0x030a0000
+#  elif PY_VERSION_HEX >= 0x03090000 && PY_VERSION_HEX < 0x030a0000
 #   define MODULE_NAME    MANGLE_MODULE_NAME("VBoxPython3_9")
 #   define initVBoxPython MANGLE_MODULE_INIT(PyInit_VBoxPython3_9)
 
