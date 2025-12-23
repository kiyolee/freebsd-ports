--- src/vulkan/utils_gen.py.orig	2025-05-17 03:17:52.000000000 +1000
+++ src/vulkan/utils_gen.py	2025-12-23 15:22:21.609709000 +1100
@@ -202,7 +202,8 @@
     if not xmlfile or xmlfile == '':
         xmlfile = find_registry_xml(datadir)
 
-    registry = VkXML(ET.parse(xmlfile))
+    tree = ET.parse(xmlfile)
+    registry = VkXML(tree.getroot())
     with open(outfile, 'w') as f:
         f.write(TEMPLATE.render(
             vkresults = get_vkenum(registry, 'VkResult'),
