
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __javax_swing_AbstractButton$3__
#define __javax_swing_AbstractButton$3__

#pragma interface

#include <java/lang/Object.h>
extern "Java"
{
  namespace java
  {
    namespace awt
    {
      namespace event
      {
          class ItemEvent;
      }
    }
  }
  namespace javax
  {
    namespace swing
    {
        class AbstractButton;
        class AbstractButton$3;
    }
  }
}

class javax::swing::AbstractButton$3 : public ::java::lang::Object
{

public: // actually package-private
  AbstractButton$3(::javax::swing::AbstractButton *);
public:
  void itemStateChanged(::java::awt::event::ItemEvent *);
public: // actually package-private
  ::javax::swing::AbstractButton * __attribute__((aligned(__alignof__( ::java::lang::Object)))) this$0;
public:
  static ::java::lang::Class class$;
};

#endif // __javax_swing_AbstractButton$3__
