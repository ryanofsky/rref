
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_java_awt_peer_gtk_GThreadMutex__
#define __gnu_java_awt_peer_gtk_GThreadMutex__

#pragma interface

#include <java/lang/Object.h>
extern "Java"
{
  namespace gnu
  {
    namespace java
    {
      namespace awt
      {
        namespace peer
        {
          namespace gtk
          {
              class GThreadMutex;
          }
        }
      }
    }
  }
}

class gnu::java::awt::peer::gtk::GThreadMutex : public ::java::lang::Object
{

public: // actually package-private
  GThreadMutex();
  jint volatile __attribute__((aligned(__alignof__( ::java::lang::Object)))) potentialLockers;
  ::java::lang::Object * lockForPotentialLockers;
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_java_awt_peer_gtk_GThreadMutex__
