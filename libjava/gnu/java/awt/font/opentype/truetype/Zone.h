
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_java_awt_font_opentype_truetype_Zone__
#define __gnu_java_awt_font_opentype_truetype_Zone__

#pragma interface

#include <java/lang/Object.h>
#include <gcj/array.h>

extern "Java"
{
  namespace gnu
  {
    namespace java
    {
      namespace awt
      {
        namespace font
        {
          namespace opentype
          {
            namespace truetype
            {
                class Zone;
            }
          }
        }
      }
    }
  }
  namespace java
  {
    namespace awt
    {
      namespace geom
      {
          class AffineTransform;
          class GeneralPath;
          class PathIterator;
      }
    }
  }
}

class gnu::java::awt::font::opentype::truetype::Zone : public ::java::lang::Object
{

public:
  Zone(jint);
  jint getCapacity();
  jint getSize();
  jint getX(jint);
  void setX(jint, jint, jboolean);
  void setY(jint, jint, jboolean);
  jint getY(jint);
  jint getOriginalX(jint);
  jint getOriginalY(jint);
  void setOriginalX(jint, jint);
  void setOriginalY(jint, jint);
  void setNumPoints(jint);
  jboolean isOnCurve(jint);
  void setOnCurve(jint, jboolean);
  jboolean isContourEnd(jint);
  void setContourEnd(jint, jboolean);
public: // actually package-private
  void transform(jdouble, ::java::awt::geom::AffineTransform *, jint, jint, jint);
  void combineWithSubGlyph(::gnu::java::awt::font::opentype::truetype::Zone *, jint);
private:
  void dump();
public:
  ::java::awt::geom::PathIterator * getPathIterator();
  ::java::awt::geom::GeneralPath * getPath();
private:
  JArray< jint > * __attribute__((aligned(__alignof__( ::java::lang::Object)))) pos;
  JArray< jint > * origPos;
  JArray< jbyte > * flags;
  jint numPoints;
  static const jint FLAG_TOUCHED_X = 1;
  static const jint FLAG_TOUCHED_Y = 2;
  static const jint FLAG_ON_CURVE = 4;
  static const jint FLAG_CONTOUR_END = 8;
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_java_awt_font_opentype_truetype_Zone__
