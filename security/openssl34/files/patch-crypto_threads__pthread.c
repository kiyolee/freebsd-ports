--- crypto/threads_pthread.c.orig	2022-11-01 14:14:36 UTC
+++ crypto/threads_pthread.c
@@ -29,6 +29,10 @@
 #define BROKEN_CLANG_ATOMICS
 #endif
 
+#if defined(__FreeBSD__) && defined(__i386__)
+#define BROKEN_CLANG_ATOMICS
+#endif
+
 #if defined(OPENSSL_THREADS) && !defined(CRYPTO_TDEBUG) && !defined(OPENSSL_SYS_WINDOWS)
 
 # if defined(OPENSSL_SYS_UNIX)
@@ -186,7 +190,7 @@
         return ret;                                                                   \
     }
 
-IMPL_fallback_atomic_exchange_n(uint64_t)
+IMPL_fallback_atomic_compare_exchange_n(uint64_t)
 
 #  define ATOMIC_COMPARE_EXCHANGE_N(t, p, e, d, s, f) fallback_atomic_compare_exchange_n_##t(p, e, d, s, f)
 
