/*
   Copyright (C) 2009 Red Hat, Inc.

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with this library; if not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _H_GDICANVAS
#define _H_GDICANVAS

#include "canvas.h"
#include "gdi_canvas.h"
#include "red_pixmap_gdi.h"

class RedPixmap;


class GDICanvas: public Canvas {
public:
    GDICanvas(int width, int height, uint32_t format,
	      PixmapCache& pixmap_cache, PaletteCache& palette_cache,
              GlzDecoderWindow &glz_decoder_window, CSurfaces &csurfaces);
    virtual ~GDICanvas();

    virtual void thread_touch() {}
    virtual void copy_pixels(const QRegion& region, RedDrawable* dc,
                             const PixmapHeader* pixmap);
    virtual void copy_pixels(const QRegion& region, RedDrawable& dc);

    virtual CanvasType get_pixmap_type();

private:
    RedPixmapGdi *_pixmap;
    RedPixmapGdi *_helper_pixmap;
    HDC _dc;
    HBITMAP _prev_bitmap;
    unsigned long _base;
    unsigned long _max;
};

#endif

