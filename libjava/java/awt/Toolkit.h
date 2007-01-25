
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_awt_Toolkit__
#define __java_awt_Toolkit__

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
        namespace peer
        {
            class GLightweightPeer;
        }
      }
    }
  }
  namespace java
  {
    namespace awt
    {
        class AWTEvent;
        class Button;
        class Canvas;
        class Checkbox;
        class CheckboxMenuItem;
        class Choice;
        class Component;
        class Container;
        class Cursor;
        class Dialog;
        class Dimension;
        class EventQueue;
        class FileDialog;
        class Font;
        class FontMetrics;
        class Frame;
        class GraphicsConfiguration;
        class Image;
        class Insets;
        class JobAttributes;
        class Label;
        class List;
        class Menu;
        class MenuBar;
        class MenuItem;
        class PageAttributes;
        class Panel;
        class Point;
        class PopupMenu;
        class PrintJob;
        class ScrollPane;
        class Scrollbar;
        class TextArea;
        class TextField;
        class Toolkit;
        class Window;
      namespace datatransfer
      {
          class Clipboard;
      }
      namespace dnd
      {
          class DragGestureEvent;
          class DragGestureListener;
          class DragGestureRecognizer;
          class DragSource;
        namespace peer
        {
            class DragSourceContextPeer;
        }
      }
      namespace event
      {
          class AWTEventListener;
          class AWTEventListenerProxy;
      }
      namespace im
      {
          class InputMethodHighlight;
      }
      namespace image
      {
          class ColorModel;
          class ImageObserver;
          class ImageProducer;
      }
      namespace peer
      {
          class ButtonPeer;
          class CanvasPeer;
          class CheckboxMenuItemPeer;
          class CheckboxPeer;
          class ChoicePeer;
          class DialogPeer;
          class FileDialogPeer;
          class FontPeer;
          class FramePeer;
          class LabelPeer;
          class LightweightPeer;
          class ListPeer;
          class MenuBarPeer;
          class MenuItemPeer;
          class MenuPeer;
          class MouseInfoPeer;
          class PanelPeer;
          class PopupMenuPeer;
          class ScrollPanePeer;
          class ScrollbarPeer;
          class TextAreaPeer;
          class TextFieldPeer;
          class WindowPeer;
      }
    }
    namespace beans
    {
        class PropertyChangeListener;
        class PropertyChangeSupport;
    }
    namespace net
    {
        class URL;
    }
  }
}

class java::awt::Toolkit : public ::java::lang::Object
{

public:
  Toolkit();
public: // actually protected
  virtual ::java::awt::peer::ButtonPeer * createButton(::java::awt::Button *) = 0;
  virtual ::java::awt::peer::TextFieldPeer * createTextField(::java::awt::TextField *) = 0;
  virtual ::java::awt::peer::LabelPeer * createLabel(::java::awt::Label *) = 0;
  virtual ::java::awt::peer::ListPeer * createList(::java::awt::List *) = 0;
  virtual ::java::awt::peer::CheckboxPeer * createCheckbox(::java::awt::Checkbox *) = 0;
  virtual ::java::awt::peer::ScrollbarPeer * createScrollbar(::java::awt::Scrollbar *) = 0;
  virtual ::java::awt::peer::ScrollPanePeer * createScrollPane(::java::awt::ScrollPane *) = 0;
  virtual ::java::awt::peer::TextAreaPeer * createTextArea(::java::awt::TextArea *) = 0;
  virtual ::java::awt::peer::ChoicePeer * createChoice(::java::awt::Choice *) = 0;
  virtual ::java::awt::peer::FramePeer * createFrame(::java::awt::Frame *) = 0;
  virtual ::java::awt::peer::CanvasPeer * createCanvas(::java::awt::Canvas *) = 0;
  virtual ::java::awt::peer::PanelPeer * createPanel(::java::awt::Panel *) = 0;
  virtual ::java::awt::peer::WindowPeer * createWindow(::java::awt::Window *) = 0;
  virtual ::java::awt::peer::DialogPeer * createDialog(::java::awt::Dialog *) = 0;
  virtual ::java::awt::peer::MenuBarPeer * createMenuBar(::java::awt::MenuBar *) = 0;
  virtual ::java::awt::peer::MenuPeer * createMenu(::java::awt::Menu *) = 0;
  virtual ::java::awt::peer::PopupMenuPeer * createPopupMenu(::java::awt::PopupMenu *) = 0;
  virtual ::java::awt::peer::MenuItemPeer * createMenuItem(::java::awt::MenuItem *) = 0;
  virtual ::java::awt::peer::MouseInfoPeer * getMouseInfoPeer();
  virtual ::java::awt::peer::FileDialogPeer * createFileDialog(::java::awt::FileDialog *) = 0;
  virtual ::java::awt::peer::CheckboxMenuItemPeer * createCheckboxMenuItem(::java::awt::CheckboxMenuItem *) = 0;
  virtual ::java::awt::peer::LightweightPeer * createComponent(::java::awt::Component *);
  virtual ::java::awt::peer::FontPeer * getFontPeer(::java::lang::String *, jint) = 0;
  virtual void loadSystemColors(JArray< jint > *);
public:
  virtual void setDynamicLayout(jboolean);
public: // actually protected
  virtual jboolean isDynamicLayoutSet();
public:
  virtual jboolean isDynamicLayoutActive();
  virtual ::java::awt::Dimension * getScreenSize() = 0;
  virtual jint getScreenResolution() = 0;
  virtual ::java::awt::Insets * getScreenInsets(::java::awt::GraphicsConfiguration *);
  virtual ::java::awt::image::ColorModel * getColorModel() = 0;
  virtual JArray< ::java::lang::String * > * getFontList() = 0;
  virtual ::java::awt::FontMetrics * getFontMetrics(::java::awt::Font *) = 0;
  virtual void sync() = 0;
  static ::java::awt::Toolkit * getDefaultToolkit();
  virtual ::java::awt::Image * getImage(::java::lang::String *) = 0;
  virtual ::java::awt::Image * getImage(::java::net::URL *) = 0;
  virtual ::java::awt::Image * createImage(::java::lang::String *) = 0;
  virtual ::java::awt::Image * createImage(::java::net::URL *) = 0;
  virtual jboolean prepareImage(::java::awt::Image *, jint, jint, ::java::awt::image::ImageObserver *) = 0;
  virtual jint checkImage(::java::awt::Image *, jint, jint, ::java::awt::image::ImageObserver *) = 0;
  virtual ::java::awt::Image * createImage(::java::awt::image::ImageProducer *) = 0;
  virtual ::java::awt::Image * createImage(JArray< jbyte > *);
  virtual ::java::awt::Image * createImage(JArray< jbyte > *, jint, jint) = 0;
  virtual ::java::awt::PrintJob * getPrintJob(::java::awt::Frame *, ::java::lang::String *, ::java::util::Properties *) = 0;
  virtual ::java::awt::PrintJob * getPrintJob(::java::awt::Frame *, ::java::lang::String *, ::java::awt::JobAttributes *, ::java::awt::PageAttributes *);
  virtual void beep() = 0;
  virtual ::java::awt::datatransfer::Clipboard * getSystemClipboard() = 0;
  virtual ::java::awt::datatransfer::Clipboard * getSystemSelection();
  virtual jint getMenuShortcutKeyMask();
  virtual jboolean getLockingKeyState(jint);
  virtual void setLockingKeyState(jint, jboolean);
public: // actually protected
  static ::java::awt::Container * getNativeContainer(::java::awt::Component *);
public:
  virtual ::java::awt::Cursor * createCustomCursor(::java::awt::Image *, ::java::awt::Point *, ::java::lang::String *);
  virtual ::java::awt::Dimension * getBestCursorSize(jint, jint);
  virtual jint getMaximumCursorColors();
  virtual jboolean isFrameStateSupported(jint);
  static ::java::lang::String * getProperty(::java::lang::String *, ::java::lang::String *);
  virtual ::java::awt::EventQueue * getSystemEventQueue();
public: // actually protected
  virtual ::java::awt::EventQueue * getSystemEventQueueImpl() = 0;
public:
  virtual ::java::awt::dnd::peer::DragSourceContextPeer * createDragSourceContextPeer(::java::awt::dnd::DragGestureEvent *) = 0;
  virtual ::java::awt::dnd::DragGestureRecognizer * createDragGestureRecognizer(::java::lang::Class *, ::java::awt::dnd::DragSource *, ::java::awt::Component *, jint, ::java::awt::dnd::DragGestureListener *);
  virtual ::java::lang::Object * getDesktopProperty(::java::lang::String *);
public: // actually protected
  virtual void setDesktopProperty(::java::lang::String *, ::java::lang::Object *);
  virtual ::java::lang::Object * lazilyLoadDesktopProperty(::java::lang::String *);
  virtual void initializeDesktopProperties();
public:
  virtual void addPropertyChangeListener(::java::lang::String *, ::java::beans::PropertyChangeListener *);
  virtual void removePropertyChangeListener(::java::lang::String *, ::java::beans::PropertyChangeListener *);
  virtual JArray< ::java::beans::PropertyChangeListener * > * getPropertyChangeListeners();
  virtual JArray< ::java::beans::PropertyChangeListener * > * getPropertyChangeListeners(::java::lang::String *);
  virtual void addAWTEventListener(::java::awt::event::AWTEventListener *, jlong);
  virtual void removeAWTEventListener(::java::awt::event::AWTEventListener *);
  virtual JArray< ::java::awt::event::AWTEventListener * > * getAWTEventListeners();
  virtual JArray< ::java::awt::event::AWTEventListener * > * getAWTEventListeners(jlong);
public: // actually package-private
  virtual void globalDispatchEvent(::java::awt::AWTEvent *);
public:
  virtual ::java::util::Map * mapInputMethodHighlight(::java::awt::im::InputMethodHighlight *) = 0;
private:
  static void initAccessibility();
  static ::java::lang::String * default_toolkit_name;
  static ::java::awt::Toolkit * toolkit;
  static ::java::util::Properties * props;
public: // actually protected
  ::java::util::Map * __attribute__((aligned(__alignof__( ::java::lang::Object)))) desktopProperties;
  ::java::beans::PropertyChangeSupport * desktopPropsSupport;
public: // actually package-private
  JArray< ::java::awt::event::AWTEventListenerProxy * > * awtEventListeners;
private:
  ::gnu::java::awt::peer::GLightweightPeer * lightweightPeer;
public:
  static ::java::lang::Class class$;
};

#endif // __java_awt_Toolkit__
