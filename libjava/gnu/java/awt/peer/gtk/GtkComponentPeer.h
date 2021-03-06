
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_java_awt_peer_gtk_GtkComponentPeer__
#define __gnu_java_awt_peer_gtk_GtkComponentPeer__

#pragma interface

#include <gnu/java/awt/peer/gtk/GtkGenericPeer.h>
#include <gcj/array.h>

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
              class GtkComponentPeer;
              class GtkImage;
          }
        }
      }
    }
  }
  namespace java
  {
    namespace awt
    {
        class AWTEvent;
        class BufferCapabilities;
        class BufferCapabilities$FlipContents;
        class Color;
        class Component;
        class Cursor;
        class Dimension;
        class Font;
        class FontMetrics;
        class Graphics;
        class GraphicsConfiguration;
        class Image;
        class Insets;
        class Point;
        class Rectangle;
        class Toolkit;
        class Window;
      namespace event
      {
          class PaintEvent;
      }
      namespace image
      {
          class ColorModel;
          class ImageObserver;
          class ImageProducer;
          class VolatileImage;
      }
      namespace peer
      {
          class ComponentPeer;
          class ContainerPeer;
      }
    }
  }
}

class gnu::java::awt::peer::gtk::GtkComponentPeer : public ::gnu::java::awt::peer::gtk::GtkGenericPeer
{

public: // actually package-private
  virtual jboolean isEnabled();
  static jboolean modalHasGrab();
  virtual JArray< jint > * gtkWidgetGetForeground();
  virtual JArray< jint > * gtkWidgetGetBackground();
  virtual void gtkWidgetGetDimensions(JArray< jint > *);
  virtual void gtkWidgetGetPreferredDimensions(JArray< jint > *);
  virtual void gtkWindowGetLocationOnScreen(JArray< jint > *);
  virtual void gtkWidgetGetLocationOnScreen(JArray< jint > *);
  virtual void gtkWidgetSetCursor(jint, ::gnu::java::awt::peer::gtk::GtkImage *, jint, jint);
  virtual void gtkWidgetSetCursorUnlocked(jint, ::gnu::java::awt::peer::gtk::GtkImage *, jint, jint);
  virtual void gtkWidgetSetBackground(jint, jint, jint);
  virtual void gtkWidgetSetForeground(jint, jint, jint);
  virtual void gtkWidgetSetSensitive(jboolean);
  virtual void gtkWidgetSetParent(::java::awt::peer::ComponentPeer *);
  virtual void gtkWidgetRequestFocus();
  virtual void gtkWidgetDispatchKeyEvent(jint, jlong, jint, jint, jint);
  virtual jboolean gtkWidgetHasFocus();
  virtual jboolean gtkWidgetCanFocus();
  virtual void realize();
  virtual void setNativeEventMask();
  virtual void create();
  virtual void connectSignals();
public: // actually protected
  GtkComponentPeer(::java::awt::Component *);
public: // actually package-private
  virtual void setParentAndBounds();
  virtual void setParent();
  virtual void setComponentBounds();
  virtual void setVisibleAndEnabled();
public:
  virtual jint checkImage(::java::awt::Image *, jint, jint, ::java::awt::image::ImageObserver *);
  virtual ::java::awt::Image * createImage(::java::awt::image::ImageProducer *);
  virtual ::java::awt::Image * createImage(jint, jint);
  virtual void disable();
  virtual void enable();
  virtual ::java::awt::image::ColorModel * getColorModel();
  virtual ::java::awt::FontMetrics * getFontMetrics(::java::awt::Font *);
  virtual ::java::awt::Graphics * getGraphics();
  virtual ::java::awt::Point * getLocationOnScreen();
  virtual ::java::awt::Dimension * getMinimumSize();
  virtual ::java::awt::Dimension * getPreferredSize();
  virtual ::java::awt::Toolkit * getToolkit();
  virtual void handleEvent(::java::awt::AWTEvent *);
public: // actually protected
  virtual void paintComponent(::java::awt::event::PaintEvent *);
  virtual void updateComponent(::java::awt::event::PaintEvent *);
public:
  virtual jboolean isFocusTraversable();
  virtual ::java::awt::Dimension * minimumSize();
  virtual void paint(::java::awt::Graphics *);
  virtual ::java::awt::Dimension * preferredSize();
  virtual jboolean prepareImage(::java::awt::Image *, jint, jint, ::java::awt::image::ImageObserver *);
  virtual void print(::java::awt::Graphics *);
  virtual void repaint(jlong, jint, jint, jint, jint);
  virtual void requestFocus();
  virtual void reshape(jint, jint, jint, jint);
  virtual void setBackground(::java::awt::Color *);
public: // actually package-private
  virtual void setNativeBounds(jint, jint, jint, jint);
public:
  virtual void setBounds(jint, jint, jint, jint);
public: // actually package-private
  virtual void setCursor();
public:
  virtual void setCursor(::java::awt::Cursor *);
  virtual void setEnabled(jboolean);
  virtual void setFont(::java::awt::Font *);
  virtual void setForeground(::java::awt::Color *);
  virtual ::java::awt::Color * getForeground();
  virtual ::java::awt::Color * getBackground();
  virtual void setVisibleNative(jboolean);
  virtual void setVisibleNativeUnlocked(jboolean);
  virtual void setVisible(jboolean);
  virtual void hide();
  virtual void show();
public: // actually protected
  virtual void postMouseEvent(jint, jlong, jint, jint, jint, jint, jboolean);
  virtual void postMouseWheelEvent(jint, jlong, jint, jint, jint, jint, jboolean, jint, jint, jint);
  virtual void postExposeEvent(jint, jint, jint, jint);
  virtual void postKeyEvent(jint, jlong, jint, jint, jchar, jint);
  virtual void postFocusEvent(jint, jboolean);
  virtual void postItemEvent(::java::lang::Object *, jint);
  virtual void postTextEvent();
public:
  virtual ::java::awt::GraphicsConfiguration * getGraphicsConfiguration();
  virtual void setEventMask(jlong);
  virtual jboolean isFocusable();
  virtual jboolean requestFocus(::java::awt::Component *, jboolean, jboolean, jlong);
private:
  ::java::awt::Window * getWindowFor(::java::awt::Component *);
public: // actually protected
  virtual jboolean isLightweightDescendant(::java::awt::Component *);
public:
  virtual jboolean isObscured();
  virtual jboolean canDetermineObscurity();
  virtual void coalescePaintEvent(::java::awt::event::PaintEvent *);
  virtual void updateCursorImmediately();
  virtual jboolean handlesWheelScrolling();
  virtual ::java::awt::image::VolatileImage * createVolatileImage(jint, jint);
  virtual void createBuffers(jint, ::java::awt::BufferCapabilities *);
  virtual ::java::awt::Image * getBackBuffer();
  virtual void flip(::java::awt::BufferCapabilities$FlipContents *);
  virtual void destroyBuffers();
  virtual ::java::lang::String * toString();
  virtual ::java::awt::Rectangle * getBounds();
  virtual void reparent(::java::awt::peer::ContainerPeer *);
  virtual void setBounds(jint, jint, jint, jint, jint);
  virtual jboolean isReparentSupported();
  virtual void layout();
public: // actually package-private
  ::java::awt::image::VolatileImage * __attribute__((aligned(__alignof__( ::gnu::java::awt::peer::gtk::GtkGenericPeer)))) backBuffer;
  ::java::awt::BufferCapabilities * caps;
  ::java::awt::Component * awtComponent;
  ::java::awt::Insets * insets;
private:
  ::java::awt::Rectangle * currentPaintArea;
public: // actually package-private
  static jboolean $assertionsDisabled;
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_java_awt_peer_gtk_GtkComponentPeer__
