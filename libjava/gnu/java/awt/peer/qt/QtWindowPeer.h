
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_java_awt_peer_qt_QtWindowPeer__
#define __gnu_java_awt_peer_qt_QtWindowPeer__

#pragma interface

#include <gnu/java/awt/peer/qt/QtContainerPeer.h>
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
          namespace qt
          {
              class QtToolkit;
              class QtWindowPeer;
          }
        }
      }
    }
  }
  namespace java
  {
    namespace awt
    {
        class Component;
    }
  }
}

class gnu::java::awt::peer::qt::QtWindowPeer : public ::gnu::java::awt::peer::qt::QtContainerPeer
{

public:
  QtWindowPeer(::gnu::java::awt::peer::qt::QtToolkit *, ::java::awt::Component *);
public: // actually protected
  virtual void init();
  virtual void setup();
public:
  virtual void toBack();
  virtual void toFront();
  virtual void setTitle(::java::lang::String *);
  virtual void updateAlwaysOnTop();
  virtual jboolean requestWindowFocus();
  static ::java::lang::Class class$;
};

#endif // __gnu_java_awt_peer_qt_QtWindowPeer__
