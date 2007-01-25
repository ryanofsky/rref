
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __javax_swing_plaf_basic_BasicSplitPaneUI__
#define __javax_swing_plaf_basic_BasicSplitPaneUI__

#pragma interface

#include <javax/swing/plaf/SplitPaneUI.h>
extern "Java"
{
  namespace java
  {
    namespace awt
    {
        class Component;
        class Dimension;
        class Graphics;
        class Insets;
      namespace event
      {
          class ActionListener;
          class FocusListener;
      }
    }
    namespace beans
    {
        class PropertyChangeListener;
    }
  }
  namespace javax
  {
    namespace swing
    {
        class ActionMap;
        class InputMap;
        class JComponent;
        class JSplitPane;
        class KeyStroke;
      namespace plaf
      {
          class ComponentUI;
        namespace basic
        {
            class BasicSplitPaneDivider;
            class BasicSplitPaneUI;
            class BasicSplitPaneUI$BasicHorizontalLayoutManager;
        }
      }
    }
  }
}

class javax::swing::plaf::basic::BasicSplitPaneUI : public ::javax::swing::plaf::SplitPaneUI
{

public:
  BasicSplitPaneUI();
  static ::javax::swing::plaf::ComponentUI * createUI(::javax::swing::JComponent *);
  virtual void installUI(::javax::swing::JComponent *);
  virtual void uninstallUI(::javax::swing::JComponent *);
public: // actually protected
  virtual void installDefaults();
  virtual void uninstallDefaults();
  virtual void installListeners();
  virtual void uninstallListeners();
public: // actually package-private
  virtual ::javax::swing::InputMap * getInputMap(jint);
  virtual ::javax::swing::ActionMap * getActionMap();
  virtual ::javax::swing::ActionMap * createActionMap();
public: // actually protected
  virtual void installKeyboardActions();
  virtual void uninstallKeyboardActions();
  virtual ::java::beans::PropertyChangeListener * createPropertyChangeListener();
  virtual ::java::awt::event::FocusListener * createFocusListener();
  virtual ::java::awt::event::ActionListener * createKeyboardUpLeftListener();
  virtual ::java::awt::event::ActionListener * createKeyboardDownRightListener();
  virtual ::java::awt::event::ActionListener * createKeyboardHomeListener();
  virtual ::java::awt::event::ActionListener * createKeyboardEndListener();
  virtual ::java::awt::event::ActionListener * createKeyboardResizeToggleListener();
public:
  virtual jint getOrientation();
  virtual void setOrientation(jint);
  virtual jboolean isContinuousLayout();
  virtual void setContinuousLayout(jboolean);
  virtual jint getLastDragLocation();
  virtual void setLastDragLocation(jint);
  virtual ::javax::swing::plaf::basic::BasicSplitPaneDivider * getDivider();
public: // actually protected
  virtual ::java::awt::Component * createDefaultNonContinuousLayoutDivider();
  virtual void setNonContinuousLayoutDivider(::java::awt::Component *);
  virtual void setNonContinuousLayoutDivider(::java::awt::Component *, jboolean);
public:
  virtual ::java::awt::Component * getNonContinuousLayoutDivider();
  virtual ::javax::swing::JSplitPane * getSplitPane();
  virtual ::javax::swing::plaf::basic::BasicSplitPaneDivider * createDefaultDivider();
  virtual void resetToPreferredSizes(::javax::swing::JSplitPane *);
  virtual void setDividerLocation(::javax::swing::JSplitPane *, jint);
  virtual jint getDividerLocation(::javax::swing::JSplitPane *);
  virtual jint getMinimumDividerLocation(::javax::swing::JSplitPane *);
  virtual jint getMaximumDividerLocation(::javax::swing::JSplitPane *);
  virtual void finishedPaintingChildren(::javax::swing::JSplitPane *, ::java::awt::Graphics *);
  virtual void paint(::java::awt::Graphics *, ::javax::swing::JComponent *);
  virtual ::java::awt::Dimension * getPreferredSize(::javax::swing::JComponent *);
  virtual ::java::awt::Dimension * getMinimumSize(::javax::swing::JComponent *);
  virtual ::java::awt::Dimension * getMaximumSize(::javax::swing::JComponent *);
  virtual ::java::awt::Insets * getInsets(::javax::swing::JComponent *);
public: // actually protected
  virtual void resetLayoutManager();
  virtual void startDragging();
  virtual void dragDividerTo(jint);
  virtual void finishDraggingTo(jint);
  virtual jint getDividerBorderSize();
private:
  jint validLocation(jint);
public: // actually protected
  jint __attribute__((aligned(__alignof__( ::javax::swing::plaf::SplitPaneUI)))) beginDragDividerLocation;
  jint dividerSize;
public: // actually package-private
  jint lastDragLocation;
public: // actually protected
  static jint KEYBOARD_DIVIDER_MOVE_OFFSET;
  ::javax::swing::plaf::basic::BasicSplitPaneDivider * divider;
  ::java::beans::PropertyChangeListener * propertyChangeListener;
  ::java::awt::event::FocusListener * focusListener;
  ::java::awt::event::ActionListener * keyboardDownRightListener;
  ::java::awt::event::ActionListener * keyboardEndListener;
  ::java::awt::event::ActionListener * keyboardHomeListener;
  ::java::awt::event::ActionListener * keyboardResizeToggleListener;
  ::java::awt::event::ActionListener * keyboardUpLeftListener;
  ::javax::swing::plaf::basic::BasicSplitPaneUI$BasicHorizontalLayoutManager * layoutManager;
  ::javax::swing::KeyStroke * dividerResizeToggleKey;
  ::javax::swing::KeyStroke * downKey;
  ::javax::swing::KeyStroke * endKey;
  ::javax::swing::KeyStroke * homeKey;
  ::javax::swing::KeyStroke * leftKey;
  ::javax::swing::KeyStroke * rightKey;
  ::javax::swing::KeyStroke * upKey;
  jboolean draggingHW;
  static ::java::lang::String * NON_CONTINUOUS_DIVIDER;
  ::java::awt::Component * nonContinuousLayoutDivider;
  ::javax::swing::JSplitPane * splitPane;
public: // actually package-private
  jboolean dividerLocationSet;
public:
  static ::java::lang::Class class$;
};

#endif // __javax_swing_plaf_basic_BasicSplitPaneUI__
