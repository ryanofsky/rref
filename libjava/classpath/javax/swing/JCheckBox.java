/* JCheckBox.java -- 
   Copyright (C) 2002, 2004, 2005 Free Software Foundation, Inc.

This file is part of GNU Classpath.

GNU Classpath is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

GNU Classpath is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
along with GNU Classpath; see the file COPYING.  If not, write to the
Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
02110-1301 USA.

Linking this library statically or dynamically with other modules is
making a combined work based on this library.  Thus, the terms and
conditions of the GNU General Public License cover the whole
combination.

As a special exception, the copyright holders of this library give you
permission to link this library with independent modules to produce an
executable, regardless of the license terms of these independent
modules, and to copy and distribute the resulting executable under
terms of your choice, provided that you also meet, for each linked
independent module, the terms and conditions of the license of that
module.  An independent module is a module which is not derived from
or based on this library.  If you modify this library, you may extend
this exception to your version of the library, but you are not
obligated to do so.  If you do not wish to do so, delete this
exception statement from your version. */


package javax.swing;

import javax.accessibility.AccessibleContext;

/**
 * An instance of JCheckbox can be added to a panel, frame etc
 *
 * @author Ronald Veldema (rveldema@cs.vu.nl)
 */
public class JCheckBox extends JToggleButton
{
  private static final long serialVersionUID = -5246739313864538930L;

  public static final String BORDER_PAINTED_FLAT_CHANGED_PROPERTY =
    "borderPaintedFlat";
  
  private boolean borderPaintedFlat;

  private void init()
  {
    borderPainted = false;
    contentAreaFilled = false;
  }
  
  public JCheckBox()
  {
    super();
    init();
  }

  public JCheckBox(Action action)
  {
    super(action);
    init();
  }

  public JCheckBox(Icon icon)
  { 
    super(icon);
    init();
  }    
  
  public JCheckBox(Icon icon, boolean selected)
  { 
    super(icon, selected);
    init();
  }    
  
  public JCheckBox(String text)
  {
    super(text);
    init();
  }
      
  public JCheckBox(String text, boolean selected)
  {
    super(text, selected);
    init();
  }
      
  public JCheckBox(String text, Icon icon)
  {
    super(text, icon);
    init();
  }

  public JCheckBox(String text, Icon icon, boolean selected)
  {
    super(text, icon, selected);
    init();
  }

  /**
   * Gets the AccessibleContext associated with this JCheckBox.
   */
  public AccessibleContext getAccessibleContext()
  {
    return null;
  }
  
  /**
   * Returns a string that specifies the name of the Look and Feel class
   * that renders this component.
   */
  public String getUIClassID()
  {
    return "CheckBoxUI";
  }
  
  protected  String paramString()
  {
    return super.paramString() + ",borderPaintedFlat=" + borderPaintedFlat;
  }

  public boolean isBorderPaintedFlat()
  {
    return borderPaintedFlat;
  }

  public void setBorderPaintedFlat(boolean newValue)
  {
    firePropertyChange("borderPaintedFlat", borderPaintedFlat, newValue);
    borderPaintedFlat = newValue;
  }
}