
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_nio_MappedByteBuffer__
#define __java_nio_MappedByteBuffer__

#pragma interface

#include <java/nio/ByteBuffer.h>
extern "Java"
{
  namespace java
  {
    namespace nio
    {
        class MappedByteBuffer;
    }
  }
}

class java::nio::MappedByteBuffer : public ::java::nio::ByteBuffer
{

public: // actually package-private
  MappedByteBuffer(jint, jint, jint, jint);
  virtual void forceImpl();
public:
  virtual ::java::nio::MappedByteBuffer * force();
public: // actually package-private
  virtual jboolean isLoadedImpl();
public:
  virtual jboolean isLoaded();
public: // actually package-private
  virtual void loadImpl();
public:
  virtual ::java::nio::MappedByteBuffer * load();
public: // actually package-private
  virtual void unmapImpl();
public: // actually protected
  virtual void finalize();
public:
  static ::java::lang::Class class$;
};

#endif // __java_nio_MappedByteBuffer__
