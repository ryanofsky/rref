
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __org_omg_IOP_MultipleComponentProfileHelper__
#define __org_omg_IOP_MultipleComponentProfileHelper__

#pragma interface

#include <java/lang/Object.h>
#include <gcj/array.h>

extern "Java"
{
  namespace org
  {
    namespace omg
    {
      namespace CORBA
      {
          class Any;
          class TypeCode;
        namespace portable
        {
            class InputStream;
            class OutputStream;
        }
      }
      namespace IOP
      {
          class MultipleComponentProfileHelper;
          class TaggedComponent;
      }
    }
  }
}

class org::omg::IOP::MultipleComponentProfileHelper : public ::java::lang::Object
{

public:
  MultipleComponentProfileHelper();
  static ::org::omg::CORBA::TypeCode * type();
  static void insert(::org::omg::CORBA::Any *, JArray< ::org::omg::IOP::TaggedComponent * > *);
  static JArray< ::org::omg::IOP::TaggedComponent * > * extract(::org::omg::CORBA::Any *);
  static ::java::lang::String * id();
  static JArray< ::org::omg::IOP::TaggedComponent * > * read(::org::omg::CORBA::portable::InputStream *);
  static void write(::org::omg::CORBA::portable::OutputStream *, JArray< ::org::omg::IOP::TaggedComponent * > *);
  static ::java::lang::Class class$;
};

#endif // __org_omg_IOP_MultipleComponentProfileHelper__
