
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_java_nio_EpollSelectionKeyImpl__
#define __gnu_java_nio_EpollSelectionKeyImpl__

#pragma interface

#include <java/nio/channels/spi/AbstractSelectionKey.h>
extern "Java"
{
  namespace gnu
  {
    namespace java
    {
      namespace nio
      {
          class EpollSelectionKeyImpl;
          class EpollSelectorImpl;
      }
    }
  }
  namespace java
  {
    namespace nio
    {
      namespace channels
      {
          class SelectableChannel;
          class SelectionKey;
          class Selector;
      }
    }
  }
}

class gnu::java::nio::EpollSelectionKeyImpl : public ::java::nio::channels::spi::AbstractSelectionKey
{

public: // actually package-private
  EpollSelectionKeyImpl(::gnu::java::nio::EpollSelectorImpl *, ::java::nio::channels::SelectableChannel *, jint);
public:
  virtual ::java::nio::channels::SelectableChannel * channel();
  virtual jint interestOps();
  virtual ::java::nio::channels::SelectionKey * interestOps(jint);
  virtual jint readyOps();
  virtual ::java::nio::channels::Selector * selector();
public: // actually package-private
  jint __attribute__((aligned(__alignof__( ::java::nio::channels::spi::AbstractSelectionKey)))) fd;
private:
  ::gnu::java::nio::EpollSelectorImpl * selector__;
  ::java::nio::channels::SelectableChannel * channel__;
public: // actually package-private
  jint interestOps__;
  jint selectedOps;
  jint key;
  jboolean valid;
  jboolean cancelled;
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_java_nio_EpollSelectionKeyImpl__
