--- libavutil/hwcontext_vulkan.c.orig	2024-10-12 16:15:19.574878000 +1100
+++ libavutil/hwcontext_vulkan.c	2024-10-12 16:15:34.915127000 +1100
@@ -862,7 +862,7 @@
 
     av_freep(&cmd->queues);
     av_freep(&cmd->bufs);
-    cmd->pool = NULL;
+    cmd->pool = VK_NULL_HANDLE;
 }
 
 static VkCommandBuffer get_buf_exec_ctx(AVHWFramesContext *hwfc, VulkanExecCtx *cmd)
