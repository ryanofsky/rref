
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_java_awt_peer_swing_SwingWindowPeer__
#define __gnu_java_awt_peer_swing_SwingWindowPeer__

#pragma interface

#include <gnu/java/awt/peer/swing/SwingContainerPeer.h>
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
          namespace swing
          {
              class SwingWindowPeer;
          }
        }
      }
    }
  }
  namespace java
  {
    namespace awt
    {
        class Window;
    }
  }
}

class gnu::java::awt::peer::swing::SwingWindowPeer : public ::gnu::java::awt::peer::swing::SwingContainerPeer
{

public:
  SwingWindowPeer(::java::awt::Window *);
  virtual void toBack() = 0;
  virtual void toFront() = 0;
  virtual void updateAlwaysOnTop() = 0;
  virtual jboolean requestWindowFocus() = 0;
  static ::java::lang::Class class$;
};

#endif // __gnu_java_awt_peer_swing_SwingWindowPeer__
