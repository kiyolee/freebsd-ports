--- completions-core/tar.bash.orig	2026-07-05 18:06:41.000000000 +1000
+++ completions-core/tar.bash	2026-07-12 15:48:27.151844000 +1000
@@ -509,7 +509,7 @@
 
 _comp_cmd_tar__detect_ext()
 {
-    local tars='@(@(tar|spkg)?(.@(Z|[bgx]z|bz2|lz?(ma|o)|zst))|t@([abglx]z|b?(z)2|zst)|cbt|gem|xbps)'
+    local tars='@(@(tar|spkg)?(.@(Z|[bgx]z|bz2|lz?(ma|o)|zst))|t@([abglx]z|b?(z)2|zst)|cbt|gem|xbps|pkg)'
     if _comp_cmd_tar__is_bsdtar; then
         # https://github.com/libarchive/libarchive/wiki/LibarchiveFormats
         tars=${tars/%\)/|pax|cpio|iso|zip|apk|ipa|hap|@(j|x)ar|mtree|a|7z|warc}
@@ -554,7 +554,7 @@
                 ext='@(t?(ar.)bz?(2)|spkg|tb2)'
                 ;;
             *J*f:none | *:xz)
-                ext='@(@(tar|spkg).@(lzma|xz)|t[lx]z)'
+                ext='@(@(tar|spkg).@(lzma|xz|zst)|t[lx]z|pkg)'
                 ;;
             *:zstd)
                 ext='t?(ar.)zst'
