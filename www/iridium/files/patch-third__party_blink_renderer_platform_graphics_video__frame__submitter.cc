--- third_party/blink/renderer/platform/graphics/video_frame_submitter.cc.orig	2025-05-07 06:48:23 UTC
+++ third_party/blink/renderer/platform/graphics/video_frame_submitter.cc
@@ -421,7 +421,7 @@ void VideoFrameSubmitter::OnBeginFrame(
     auto& details = timing_details.find(frame_token)->value;
     auto& feedback = details.presentation_feedback;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // TODO: On Linux failure flag is unreliable, and perfectly rendered frames
     // are reported as failures all the time.
     bool presentation_failure = false;
