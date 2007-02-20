
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_lang_Thread__
#define __java_lang_Thread__

#pragma interface

#include <java/lang/Object.h>
#include <gcj/array.h>

extern "Java"
{
  namespace gnu
  {
    namespace gcj
    {
        class RawData;
        class RawDataManaged;
    }
    namespace java
    {
      namespace util
      {
          class WeakIdentityHashMap;
      }
    }
  }
}

class _Jv_JNIEnv;
#define _JV_NOT_OWNER 1
#define _JV_INTERRUPTED 2
_Jv_JNIEnv * _Jv_GetCurrentJNIEnv ();
void _Jv_SetCurrentJNIEnv (_Jv_JNIEnv *env);
void _Jv_ThreadRun (java::lang::Thread* thread);
jint _Jv_AttachCurrentThread(java::lang::Thread* thread);
java::lang::Thread* _Jv_AttachCurrentThread (jstring name, java::lang::ThreadGroup* group);
java::lang::Thread* _Jv_AttachCurrentThreadAsDaemon (jstring name, java::lang::ThreadGroup* group);
jint _Jv_DetachCurrentThread ();
struct _Jv_Thread_t;
_Jv_Thread_t* _Jv_ThreadGetData (java::lang::Thread* thread);

class java::lang::Thread : public ::java::lang::Object
{

public:
  Thread();
  Thread(::java::lang::Runnable *);
  Thread(::java::lang::String *);
  Thread(::java::lang::ThreadGroup *, ::java::lang::Runnable *);
  Thread(::java::lang::ThreadGroup *, ::java::lang::String *);
  Thread(::java::lang::Runnable *, ::java::lang::String *);
  Thread(::java::lang::ThreadGroup *, ::java::lang::Runnable *, ::java::lang::String *);
  Thread(::java::lang::ThreadGroup *, ::java::lang::Runnable *, ::java::lang::String *, jlong);
public: // actually package-private
  Thread(::java::lang::String *, jboolean);
private:
  Thread(::java::lang::Thread *, ::java::lang::ThreadGroup *, ::java::lang::Runnable *, ::java::lang::String *, jboolean);
public:
  static jint activeCount();
  virtual void checkAccess();
  virtual jint countStackFrames();
  static ::java::lang::Thread * currentThread();
  virtual void destroy();
  static void dumpStack();
  static jint enumerate(JArray< ::java::lang::Thread * > *);
  virtual ::java::lang::String * getName();
  virtual jint getPriority();
  virtual ::java::lang::ThreadGroup * getThreadGroup();
  static jboolean holdsLock(::java::lang::Object *);
  virtual void interrupt();
  static jboolean interrupted();
  virtual jboolean isInterrupted();
  virtual jboolean isAlive();
  virtual jboolean isDaemon();
  virtual void join();
  virtual void join(jlong);
  virtual void join(jlong, jint);
  virtual void resume();
private:
  void finish_();
  jboolean isInterrupted(jboolean);
public:
  virtual void run();
  virtual void setDaemon(jboolean);
  virtual ::java::lang::ClassLoader * getContextClassLoader();
  virtual void setContextClassLoader(::java::lang::ClassLoader *);
  virtual void setName(::java::lang::String *);
  static void yield();
  static void sleep(jlong);
  static void sleep(jlong, jint);
  virtual void start();
  virtual void stop();
  virtual void stop(::java::lang::Throwable *);
  virtual void suspend();
  virtual void setPriority(jint);
  virtual ::java::lang::String * toString();
private:
  void initialize_native();
  static ::java::lang::String * gen_name();
public: // actually package-private
  static ::java::util::Map * getThreadLocals();
public:
  virtual void setUncaughtExceptionHandler(::java::lang::Thread$UncaughtExceptionHandler *);
  virtual ::java::lang::Thread$UncaughtExceptionHandler * getUncaughtExceptionHandler();
  static void setDefaultUncaughtExceptionHandler(::java::lang::Thread$UncaughtExceptionHandler *);
  static ::java::lang::Thread$UncaughtExceptionHandler * getDefaultUncaughtExceptionHandler();
  virtual jlong getId();
  virtual ::java::lang::Thread$State * getState();
  static ::java::util::Map * getAllStackTraces();
  virtual JArray< ::java::lang::StackTraceElement * > * getStackTrace();
  static const jint MIN_PRIORITY = 1;
  static const jint NORM_PRIORITY = 5;
  static const jint MAX_PRIORITY = 10;
public: // actually package-private
  ::java::lang::ThreadGroup * __attribute__((aligned(__alignof__( ::java::lang::Object)))) group;
private:
  ::java::lang::Runnable * runnable;
public: // actually package-private
  ::java::lang::String * name;
private:
  jboolean daemon;
  jint priority;
public: // actually package-private
  jboolean interrupt_flag;
private:
  static const jbyte THREAD_DEAD = 0;
  static const jbyte THREAD_ALIVE = 1;
  static const jbyte THREAD_SIGNALED = 2;
  jboolean startable_flag;
  ::java::lang::ClassLoader * contextClassLoader;
  jlong threadId;
  static jlong nextThreadId;
  static jlong totalThreadsCreated;
  static ::java::lang::Thread$UncaughtExceptionHandler * defaultHandler;
public: // actually package-private
  ::gnu::java::util::WeakIdentityHashMap * locals;
  ::java::lang::Thread$UncaughtExceptionHandler * exceptionHandler;
private:
  ::java::lang::Object * parkBlocker;
public: // actually package-private
  static const jbyte THREAD_PARK_RUNNING = 0;
  static const jbyte THREAD_PARK_PERMIT = 1;
  static const jbyte THREAD_PARK_PARKED = 2;
  static const jbyte THREAD_PARK_DEAD = 3;
  ::java::lang::Object * accessControlState;
  ::gnu::gcj::RawData * interp_frame;
  ::gnu::gcj::RawData * frame;
  volatile jint state;
  ::gnu::gcj::RawDataManaged * data;
public:
  static ::java::lang::Class class$;

  friend _Jv_JNIEnv * ::_Jv_GetCurrentJNIEnv ();
  friend void ::_Jv_SetCurrentJNIEnv (_Jv_JNIEnv *env);
  friend void ::_Jv_ThreadRun (java::lang::Thread* thread);
  friend jint (::_Jv_AttachCurrentThread) (java::lang::Thread* thread);
  friend java::lang::Thread* ::_Jv_AttachCurrentThread (jstring name, java::lang::ThreadGroup* group);
  friend java::lang::Thread* ::_Jv_AttachCurrentThreadAsDaemon (jstring name, java::lang::ThreadGroup* group);
  friend jint (::_Jv_DetachCurrentThread) ();
};

#endif // __java_lang_Thread__
