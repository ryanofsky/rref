
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_io_ObjectInputStream$2__
#define __java_io_ObjectInputStream$2__

#pragma interface

#include <java/io/ObjectInputStream$GetField.h>
#include <gcj/array.h>


class java::io::ObjectInputStream$2 : public ::java::io::ObjectInputStream$GetField
{

public: // actually package-private
  ObjectInputStream$2(::java::io::ObjectInputStream *, ::java::io::ObjectStreamClass *, JArray< jbyte > *, JArray< ::java::lang::Object * > *);
public:
  ::java::io::ObjectStreamClass * getObjectStreamClass();
  jboolean defaulted(::java::lang::String *);
  jboolean get(::java::lang::String *, jboolean);
  jchar get(::java::lang::String *, jchar);
  jbyte get(::java::lang::String *, jbyte);
  jshort get(::java::lang::String *, jshort);
  jint get(::java::lang::String *, jint);
  jlong get(::java::lang::String *, jlong);
  jfloat get(::java::lang::String *, jfloat);
  jdouble get(::java::lang::String *, jdouble);
  ::java::lang::Object * get(::java::lang::String *, ::java::lang::Object *);
private:
  ::java::io::ObjectStreamField * getField(::java::lang::String *, ::java::lang::Class *);
public: // actually package-private
  ::java::io::ObjectInputStream * __attribute__((aligned(__alignof__( ::java::io::ObjectInputStream$GetField)))) this$0;
private:
  ::java::io::ObjectStreamClass * val$clazz;
  JArray< jbyte > * val$prim_field_data;
  JArray< ::java::lang::Object * > * val$objs;
public:
  static ::java::lang::Class class$;
};

#endif // __java_io_ObjectInputStream$2__