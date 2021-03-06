/*
   FreeRDP: A Remote Desktop Protocol client.
   GDI Color Conversion Routines

   Copyright 2010 Marc-Andre Moreau <marcandre.moreau@gmail.com>

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#ifndef __GDI_COLOR_H
#define __GDI_COLOR_H

#include "libfreerdpgdi.h"

/* GDI Color Space Conversions: http://msdn.microsoft.com/en-us/library/ff566496(VS.85).aspx */

/* Color Space Conversion */
 
#define RGB_565_888(_r, _g, _b) \
	_r = (_r << 3 & ~0x7) | (_r >> 2); \
	_g = (_g << 2 & ~0x3) | (_g >> 4); \
	_b = (_b << 3 & ~0x7) | (_b >> 2);

#define RGB_888_565(_r, _g, _b) \
	_r = (_r >> 3); \
	_g = (_g >> 2); \
	_b = (_b >> 3);
 
/* COLORREF (RGB 24) */

#ifdef USE_ALPHA
#define RGB(_r, _g, _b)  \
	(0xFF << 24) | (_r << 16) | (_g << 8) | _b;
#else
#define RGB(_r, _g, _b)  \
	(_r << 16) | (_g << 8) | _b;
#endif

#define PixelRGB(_pixel)  \
	(_pixel.red << 16) | (_pixel.green << 8) | _pixel.blue

#define GetRGB(_r, _g, _b, _p) \
	_r = (_p & 0xFF0000) >> 16; \
	_g = (_p & 0xFF00) >> 8; \
	_b = (_p & 0xFF); \

/* RGB 15 (RGB_555) */

#define RGB15(_r, _g, _b)  \
	(_r << 10) | (_g << 5) | _b;

#define GetRGB15(_r, _g, _b, _p) \
	_r = (_p & 0x7C00) >> 10; \
	_g = (_p & 0x3E0) >> 5; \
	_b = (_p & 0x1F);

/* BGR 15 (BGR_555) */

#define BGR15(_r, _g, _b)  \
	(_b << 10) | (_g << 5) | _r;

#define GetBGR15(_r, _g, _b, _p) \
	_b = ((_p << 3) & 0xF8) | ((_p >> 2) & 0x7); \
	_g = ((_p >> 2) & 0xF8) | ((_p >> 8) & 0x7); \
	_r = ((_p >> 7) & 0xF8) | ((_p >> 12) & 0x7);

/* RGB 16 (RGB_565) */

#define RGB16(_r, _g, _b)  \
	(_r << 11) | (_g << 5) | _b;

#define GetRGB_565(_r, _g, _b, _p) \
	_r = (_p & 0xF800) >> 11; \
	_g = (_p & 0x7E0) >> 5; \
	_b = (_p & 0x1F);

#define GetRGB16(_r, _g, _b, _p) \
	GetRGB_565(_r, _g, _b, _p); \
	RGB_565_888(_r, _g, _b);

/* BGR 16 (BGR_565) */

#define BGR16(_r, _g, _b)  \
	(_b << 11) | (_g << 5) | _r;

#define GetBGR_565(_r, _g, _b, _p) \
	_b = (_p & 0xF800) >> 11; \
	_g = (_p & 0x7E0) >> 5; \
	_r = (_p & 0x1F);
 
#define GetBGR16(_r, _g, _b, _p) \
	GetBGR_565(_r, _g, _b, _p); \
	RGB_565_888(_r, _g, _b);

/* RGB 24 (RGB_888) */

#define RGB24(_r, _g, _b)  \
	(_r << 16) | (_g << 8) | _b;

#define GetRGB24(_r, _g, _b, _p) \
	_r = (_p & 0xFF0000) >> 16; \
	_g = (_p & 0xFF00) >> 8; \
	_b = (_p & 0xFF);

/* BGR 24 (BGR_888) */

#define BGR24(_r, _g, _b)  \
	(_b << 16) | (_g << 8) | _r;

#define GetBGR24(_r, _g, _b, _p) \
	_b = (_p & 0xFF0000) >> 16; \
	_g = (_p & 0xFF00) >> 8; \
	_r = (_p & 0xFF);

/* RGB 32 (ARGB_8888), alpha ignored */

#ifdef USE_ALPHA
#define RGB32(_r, _g, _b)  \
	(0xFF << 24) | (_r << 16) | (_g << 8) | _b;
#else
#define RGB32(_r, _g, _b)  \
	(_r << 16) | (_g << 8) | _b;
#endif

#define GetRGB32(_r, _g, _b, _p) \
	_r = (_p & 0xFF0000) >> 16; \
	_g = (_p & 0xFF00) >> 8; \
	_b = (_p & 0xFF);

/* ARGB 32 (ARGB_8888) */

#define ARGB32(_a,_r, _g, _b)  \
	(_a << 24) | (_r << 16) | (_g << 8) | _b;

#define GetARGB32(_a, _r, _g, _b, _p) \
	_a = (_p & 0xFF000000) >> 24; \
	_r = (_p & 0xFF0000) >> 16; \
	_g = (_p & 0xFF00) >> 8; \
	_b = (_p & 0xFF);

/* BGR 32 (ABGR_8888), alpha ignored */

#define BGR32(_r, _g, _b)  \
	(_b << 16) | (_g << 8) | _r;

#define GetBGR32(_r, _g, _b, _p) \
	_b = (_p & 0xFF0000) >> 16; \
	_g = (_p & 0xFF00) >> 8; \
	_r = (_p & 0xFF);

/* BGR 32 (ABGR_8888) */

#define ABGR32(_a, _r, _g, _b)  \
	(_a << 24) | (_b << 16) | (_g << 8) | _r;

#define GetABGR32(_a, _r, _g, _b, _p) \
	_a = (_p & 0xFF000000) >> 24; \
	_b = (_p & 0xFF0000) >> 16; \
	_g = (_p & 0xFF00) >> 8; \
	_r = (_p & 0xFF);

/* Color Conversion */

#define BGR16_RGB32(_r, _g, _b, _p) \
	GetBGR16(_r, _g, _b, _p); \
 	RGB_565_888(_r, _g, _b); \
	_p = RGB32(_r, _g, _b);

void gdi_color_convert(PIXEL *pixel, int color, int bpp, HPALETTE palette);
char* gdi_image_convert(char* srcData, int width, int height, int srcBpp, int dstBpp, HPALETTE palette);
char* gdi_glyph_convert(int width, int height, char* data);

#endif /* __GDI_COLOR_H */
