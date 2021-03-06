
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_gcj_jvmti_Breakpoint__
#define __gnu_gcj_jvmti_Breakpoint__

#pragma interface

#include <java/lang/Object.h>
extern "Java"
{
  namespace gnu
  {
    namespace gcj
    {
        class RawDataManaged;
      namespace jvmti
      {
          class Breakpoint;
      }
    }
  }
}

#ifdef DIRECT_THREADED
void _Jv_RewriteBreakpointInsn (jmethodID, jlocation, pc_t);
#endif

class gnu::gcj::jvmti::Breakpoint : public ::java::lang::Object
{

#ifdef DIRECT_THREADED
friend void (::_Jv_RewriteBreakpointInsn (jmethodID, jlocation, pc_t));
#endif

public:
  Breakpoint(jlong, jlong);
private:
  void initialize_native();
public:
  virtual void install();
  virtual void remove();
  virtual ::gnu::gcj::RawDataManaged * getInsn();
private:
  jlong __attribute__((aligned(__alignof__( ::java::lang::Object)))) method;
  jlong location;
  ::gnu::gcj::RawDataManaged * data;
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_gcj_jvmti_Breakpoint__
