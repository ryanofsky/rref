
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_util_VMTimeZone__
#define __java_util_VMTimeZone__

#pragma interface

#include <java/lang/Object.h>

class java::util::VMTimeZone : public ::java::lang::Object
{

public: // actually package-private
  VMTimeZone();
  static ::java::util::TimeZone * getDefaultTimeZoneId();
private:
  static ::java::lang::String * readTimeZoneFile(::java::lang::String *);
  static ::java::lang::String * readtzFile(::java::lang::String *);
  static void skipFully(::java::io::InputStream *, jlong);
  static ::java::lang::String * getSystemTimeZoneId();
public:
  static ::java::lang::Class class$;
};

#endif // __java_util_VMTimeZone__