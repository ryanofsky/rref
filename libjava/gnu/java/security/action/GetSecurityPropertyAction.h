
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_java_security_action_GetSecurityPropertyAction__
#define __gnu_java_security_action_GetSecurityPropertyAction__

#pragma interface

#include <java/lang/Object.h>
extern "Java"
{
  namespace gnu
  {
    namespace java
    {
      namespace security
      {
        namespace action
        {
            class GetSecurityPropertyAction;
        }
      }
    }
  }
}

class gnu::java::security::action::GetSecurityPropertyAction : public ::java::lang::Object
{

public:
  GetSecurityPropertyAction();
  GetSecurityPropertyAction(::java::lang::String *);
  GetSecurityPropertyAction(::java::lang::String *, ::java::lang::String *);
  virtual ::gnu::java::security::action::GetSecurityPropertyAction * setParameters(::java::lang::String *);
  virtual ::gnu::java::security::action::GetSecurityPropertyAction * setParameters(::java::lang::String *, ::java::lang::String *);
  virtual ::java::lang::String * target$run();
  virtual ::java::lang::Object * run();
private:
  ::java::lang::String * __attribute__((aligned(__alignof__( ::java::lang::Object)))) name;
  ::java::lang::String * value;
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_java_security_action_GetSecurityPropertyAction__
