/* DO NOT EDIT THIS FILE - it is machine generated */

#ifndef __gnu_java_net_local_LocalSocketImpl__
#define __gnu_java_net_local_LocalSocketImpl__

#include <jni.h>

#ifdef __cplusplus
extern "C"
{
#endif

JNIEXPORT void JNICALL Java_gnu_java_net_local_LocalSocketImpl_create (JNIEnv *env, jobject, jboolean);
JNIEXPORT void JNICALL Java_gnu_java_net_local_LocalSocketImpl_listen (JNIEnv *env, jobject, jint);
JNIEXPORT void JNICALL Java_gnu_java_net_local_LocalSocketImpl_accept (JNIEnv *env, jobject, jobject);
JNIEXPORT jint JNICALL Java_gnu_java_net_local_LocalSocketImpl_available (JNIEnv *env, jobject, jint);
JNIEXPORT void JNICALL Java_gnu_java_net_local_LocalSocketImpl_close (JNIEnv *env, jobject);
JNIEXPORT void JNICALL Java_gnu_java_net_local_LocalSocketImpl_sendUrgentData (JNIEnv *env, jobject, jint);
JNIEXPORT void JNICALL Java_gnu_java_net_local_LocalSocketImpl_shutdownInput (JNIEnv *env, jobject);
JNIEXPORT void JNICALL Java_gnu_java_net_local_LocalSocketImpl_shutdownOutput (JNIEnv *env, jobject);
JNIEXPORT void JNICALL Java_gnu_java_net_local_LocalSocketImpl_unlink (JNIEnv *env, jobject);
JNIEXPORT void JNICALL Java_gnu_java_net_local_LocalSocketImpl_localBind (JNIEnv *env, jobject, jobject);
JNIEXPORT void JNICALL Java_gnu_java_net_local_LocalSocketImpl_localConnect (JNIEnv *env, jobject, jobject);
JNIEXPORT jint JNICALL Java_gnu_java_net_local_LocalSocketImpl_read (JNIEnv *env, jobject, jint, jbyteArray, jint, jint);
JNIEXPORT void JNICALL Java_gnu_java_net_local_LocalSocketImpl_write (JNIEnv *env, jobject, jint, jbyteArray, jint, jint);

#ifdef __cplusplus
}
#endif

#endif /* __gnu_java_net_local_LocalSocketImpl__ */
