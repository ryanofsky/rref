
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_util_EnumSet$1__
#define __java_util_EnumSet$1__

#pragma interface

#include <java/lang/Object.h>

class java::util::EnumSet$1 : public ::java::lang::Object
{

public: // actually package-private
  EnumSet$1(::java::util::EnumSet *);
public:
  jboolean hasNext();
  ::java::lang::Enum * target$next();
  void remove();
  ::java::lang::Object * next();
public: // actually package-private
  jint __attribute__((aligned(__alignof__( ::java::lang::Object)))) next__;
  jint count;
  ::java::util::EnumSet * this$0;
public:
  static ::java::lang::Class class$;
};

#endif // __java_util_EnumSet$1__
