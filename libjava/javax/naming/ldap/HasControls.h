
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __javax_naming_ldap_HasControls__
#define __javax_naming_ldap_HasControls__

#pragma interface

#include <java/lang/Object.h>
#include <gcj/array.h>

extern "Java"
{
  namespace javax
  {
    namespace naming
    {
      namespace ldap
      {
          class Control;
          class HasControls;
      }
    }
  }
}

class javax::naming::ldap::HasControls : public ::java::lang::Object
{

public:
  virtual JArray< ::javax::naming::ldap::Control * > * getControls() = 0;
  static ::java::lang::Class class$;
} __attribute__ ((java_interface));

#endif // __javax_naming_ldap_HasControls__
