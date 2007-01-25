
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __javax_swing_SpinnerNumberModel__
#define __javax_swing_SpinnerNumberModel__

#pragma interface

#include <javax/swing/AbstractSpinnerModel.h>
extern "Java"
{
  namespace javax
  {
    namespace swing
    {
        class SpinnerNumberModel;
    }
  }
}

class javax::swing::SpinnerNumberModel : public ::javax::swing::AbstractSpinnerModel
{

public:
  SpinnerNumberModel();
  SpinnerNumberModel(jdouble, jdouble, jdouble, jdouble);
  SpinnerNumberModel(jint, jint, jint, jint);
  SpinnerNumberModel(::java::lang::Number *, ::java::lang::Comparable *, ::java::lang::Comparable *, ::java::lang::Number *);
  virtual void setValue(::java::lang::Object *);
  virtual ::java::lang::Object * getValue();
  virtual ::java::lang::Object * getNextValue();
  virtual ::java::lang::Object * getPreviousValue();
  virtual ::java::lang::Number * getNumber();
  virtual ::java::lang::Comparable * getMinimum();
  virtual void setMinimum(::java::lang::Comparable *);
  virtual ::java::lang::Comparable * getMaximum();
  virtual void setMaximum(::java::lang::Comparable *);
  virtual ::java::lang::Number * getStepSize();
  virtual void setStepSize(::java::lang::Number *);
private:
  static const jlong serialVersionUID = 7279176385485777821LL;
  ::java::lang::Number * __attribute__((aligned(__alignof__( ::javax::swing::AbstractSpinnerModel)))) value;
  ::java::lang::Comparable * minimum;
  ::java::lang::Comparable * maximum;
  ::java::lang::Number * stepSize;
public:
  static ::java::lang::Class class$;
};

#endif // __javax_swing_SpinnerNumberModel__
