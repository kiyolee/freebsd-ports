--- sphinx/pycode/parser.py.orig	2023-04-24 05:57:27.420852700 +1000
+++ sphinx/pycode/parser.py	2025-12-21 17:27:04.642971000 +1100
@@ -44,7 +44,7 @@
         self_id = self.arg
 
     node_name = node.__class__.__name__
-    if node_name in ('Index', 'Num', 'Slice', 'Str', 'Subscript'):
+    if node_name in ('Constant', 'Index', 'Slice', 'Subscript'):
         raise TypeError('%r does not create new variable' % node)
     if node_name == 'Name':
         if self is None or node.id == self_id:  # type: ignore
@@ -400,15 +400,15 @@
     def visit_Expr(self, node: ast.Expr) -> None:
         """Handles Expr node and pick up a comment if string."""
         if (isinstance(self.previous, (ast.Assign, ast.AnnAssign)) and
-                isinstance(node.value, ast.Str)):
+                isinstance(node.value, ast.Constant) and isinstance(node.value.value, str)):
             try:
                 targets = get_assign_targets(self.previous)
                 varnames = get_lvar_names(targets[0], self.get_self())
                 for varname in varnames:
-                    if isinstance(node.value.s, str):
-                        docstring = node.value.s
+                    if isinstance(node.value.value, str):
+                        docstring = node.value.value
                     else:
-                        docstring = node.value.s.decode(self.encoding or 'utf-8')
+                        docstring = node.value.value.decode(self.encoding or 'utf-8')
 
                     self.add_variable_comment(varname, dedent_docstring(docstring))
                     self.add_entry(varname)
