
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_awt_geom_CubicCurve2D$1__
#define __java_awt_geom_CubicCurve2D$1__

#pragma interface

#include <java/lang/Object.h>
#include <gcj/array.h>

extern "Java"
{
  namespace java
  {
    namespace awt
    {
      namespace geom
      {
          class AffineTransform;
          class CubicCurve2D;
          class CubicCurve2D$1;
      }
    }
  }
}

class java::awt::geom::CubicCurve2D$1 : public ::java::lang::Object
{

public: // actually package-private
  CubicCurve2D$1(::java::awt::geom::CubicCurve2D *, ::java::awt::geom::AffineTransform *);
public:
  jint getWindingRule();
  jboolean isDone();
  void next();
  jint currentSegment(JArray< jfloat > *);
  jint currentSegment(JArray< jdouble > *);
private:
  jint __attribute__((aligned(__alignof__( ::java::lang::Object)))) current;
public: // actually package-private
  ::java::awt::geom::CubicCurve2D * this$0;
private:
  ::java::awt::geom::AffineTransform * val$at;
public:
  static ::java::lang::Class class$;
};

#endif // __java_awt_geom_CubicCurve2D$1__
