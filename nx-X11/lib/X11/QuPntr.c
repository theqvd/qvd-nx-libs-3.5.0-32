/* $Xorg: QuPntr.c,v 1.4 2001/02/09 02:03:35 xorgcvs Exp $ */
/*

Copyright 1986, 1998  The Open Group

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

#define NEED_REPLIES
#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include "Xlibint.h"

Bool XQueryPointer(dpy, w, root, child, root_x, root_y, win_x, win_y, mask)
     register Display *dpy;
     Window w, *root, *child;
     int *root_x, *root_y, *win_x, *win_y;
     unsigned int *mask;

{       
    xQueryPointerReply rep;
    xResourceReq *req;

    LockDisplay(dpy);
    GetResReq(QueryPointer, w, req);
    if (_XReply (dpy, (xReply *)&rep, 0, xTrue) == 0) {
	    UnlockDisplay(dpy);
	    SyncHandle();
	    return(False);
	}

    *root = rep.root;
    *child = rep.child;
    *root_x = cvtINT16toInt (rep.rootX);
    *root_y = cvtINT16toInt (rep.rootY);
    *win_x = cvtINT16toInt (rep.winX);
    *win_y = cvtINT16toInt (rep.winY);
    *mask = rep.mask;
    UnlockDisplay(dpy);
    SyncHandle();
    return (rep.sameScreen);
}

