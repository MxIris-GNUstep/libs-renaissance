/* -*-objc-*-
   GSAutoLayoutViewDefaults.h

   Copyright (C) 2002 Free Software Foundation, Inc.

   Author: Nicola Pero <n.pero@mi.flashnet.it>
   Date: April 2002

   This file is part of GNUstep Renaissance

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.
   
   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public
   License along with this library; see the file COPYING.LIB.
   If not, write to the Free Software Foundation,
   59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*/

#ifndef _GNUstep_H_GSAutoLayoutDefaults
#define _GNUstep_H_GSAutoLayoutDefaults

#ifndef GNUSTEP
# include <Foundation/Foundation.h>
# include <AppKit/AppKit.h>
# include "GNUstep.h"
#else
# include <AppKit/NSView.h>
#endif

/*
 * An essential idea in the GSAutoLayout framework is that of default
 * autolayout behaviour.  Every class can provide/compute default
 * autolayout flags for objects of that class.  Unless overridden,
 * those flags are automatically used.
 *
 * The expand/align flags are normally chosen as follows - 
 *
 *  - if the control displays information and making the control
 *  bigger displays more information (for example a textfield in the
 *  horizontal direction, a textview in all directions, a scrollview
 *  in all directions, etc), then that control has a
 *  GSAutoLayoutAlignment of GSAutoLayoutExpand set in that direction.
 *  For containers, if anything the container contains
 *  expand in that direction, the container expands too in that
 *  direction.  Typically, a window is made resizable in a direction 
 *  if and only if it contains a view that expands in that direction.
 *
 * - in all other cases, it's basically a matter of aesthetics to 
 * decide what to do when more space is available.  There are a few
 * options:
 *
 *  GSAutoLayoutWeakExpand: means the control is expanded when more
 *   space is available.  This is different from GSAutoLayoutExpand
 *   in that the control does not 'suggest' to be given more space;
 *   that is, a weak-expand view in a window does not normally cause 
 *   the window to be made resizable.  But if more space is made
 *   available, a weak-expand view will expand.  Typically, `spaces'
 *   (vspace and hspace) are weak-expand views.
 *
 *  GSAutoLayoutCenter, GSAutoLayoutAlignMin, GSAutoLayoutAlignMax:
 *   The view is moved to the center, min or max (of the coordinates)
 *   of the available space, and the remaining space is left blank.
 *   The default for everything which is not expanding is
 *   GSAutoLayoutCenter.  You may often want to override this
 *   with GSAutoLayoutAlignLeft, or GSAutoLayoutAlignRight.
 *
 * The borders are normally chosen as follows -
 *
 *  - 4 in all directions for all views, but 0 in all directions for
 *    containers.
 *
 */

/* This enum is used to pass alignment flags for views.  Only one of
 * the options is valid in each direction.  AlignMin is alignment
 * towards the minimum coordinates - ie, left if coordinates increase
 * from left to right, and right for AlignMax.  */
typedef enum 
{
  GSAutoLayoutExpand = 0,
  GSAutoLayoutWeakExpand = 1,
  GSAutoLayoutAlignMin = 2,
  GSAutoLayoutAlignCenter = 3,
  GSAutoLayoutAlignMax = 4
} GSAutoLayoutAlignment;

@interface NSView (AutoLayoutDefaults)

- (GSAutoLayoutAlignment) autolayoutDefaultHorizontalAlignment;

- (GSAutoLayoutAlignment) autolayoutDefaultVerticalAlignment;

- (float) autolayoutDefaultHorizontalBorder;

- (float) autolayoutDefaultVerticalBorder;

@end

#endif
