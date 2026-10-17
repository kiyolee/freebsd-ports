--- qpy/QtCore/qpycore_qobject_helpers.cpp.orig	2026-03-25 04:25:28.751430500 +1100
+++ qpy/QtCore/qpycore_qobject_helpers.cpp	2026-10-17 15:20:49.080207000 +1100
@@ -50,7 +50,7 @@
 const QMetaObject *qpycore_qobject_metaobject(sipSimpleWrapper *pySelf,
         sipTypeDef *base)
 {
-    sipWrapperType *wt = (pySelf ? (sipWrapperType *)Py_TYPE(pySelf) : 0);
+    sipWrapperType *wt = (pySelf ? (sipWrapperType *)Py_TYPE((PyObject *)pySelf) : 0);
 
     return qpycore_get_qmetaobject(wt, base);
 }
@@ -64,7 +64,7 @@
     if (!pySelf)
         return -1;
 
-    return qt_metacall_worker(pySelf, Py_TYPE(pySelf), base, _c, _id, _a);
+    return qt_metacall_worker(pySelf, Py_TYPE((PyObject *)pySelf), base, _c, _id, _a);
 }
 
 
@@ -220,9 +220,9 @@
 
     // We only need to look at the MRO if the object is a wrapped type (rather
     // than a user sub-class).
-    if (base_pytype != Py_TYPE(pySelf))
+    if (base_pytype != Py_TYPE((PyObject *)pySelf))
     {
-        PyObject *mro = PyObject_GetAttr((PyObject *)Py_TYPE(pySelf),
+        PyObject *mro = PyObject_GetAttr((PyObject *)Py_TYPE((PyObject *)pySelf),
                 qpycore_dunder_mro);
         Q_ASSERT(mro);
 
