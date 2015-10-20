/* $XdotOrg: xc/include/extensions/Xinerama.h,v 1.3 2004/12/01 19:03:46 daniels Exp $ */
/*

Copyright 2003  The Open Group

Permission to use, copy, modify, distribute, and sell this software and its
documentation for any purpose is hereby granted without fee, provided that
the above copyright notice appear in all copies and that both that
copyright notice and this permission notice appear in supporting
documentation.

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
OPEN GROUP BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN
AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

Except as contained in this notice, the name of The Open Group shall not be
used in advertising or otherwise to promote the sale, use or other dealings
in this Software without prior written authorization from The Open Group.

*/
/* $XFree86: xc/include/extensions/Xinerama.h,v 3.3 2002/09/16 18:05:19 eich Exp $ */

#ifndef _Xinerama_h
#define _Xinerama_h

#include <X11/Xlib.h>

typedef struct {
   int   screen_number;
   short x_org;
   short y_org;
   short width;
   short height;
} XineramaScreenInfo;

_XFUNCPROTOBEGIN

Bool XineramaQueryExtension (
   Display *dpy,
   int     *event_base,
   int     *error_base
);

Status XineramaQueryVersion(
   Display *dpy,
   int     *major_versionp,
   int     *minor_versionp
);

Bool XineramaIsActive(Display *dpy);


/* 
   Returns the number of heads and a pointer to an array of
   structures describing the position and size of the individual
   heads.  Returns NULL and number = 0 if Xinerama is not active.
  
   Returned array should be freed with XFree().
*/

XineramaScreenInfo * 
XineramaQueryScreens(
   Display *dpy,
   int     *number
);

_XFUNCPROTOEND

#endif /* _Xinerama_h */

