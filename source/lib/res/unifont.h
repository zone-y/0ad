// $Id: unifont.h,v 1.7 2004/10/06 14:00:43 janwas Exp $

#ifndef __UNIFONT_H__
#define __UNIFONT_H__

#include "handle.h"


// Load and return a handle to the font defined
// in fn+".fnt" with texture fn+".tga"
Handle unifont_load(const char* fn, int scope = 0);

// Release a handle to a previously loaded font
int unifont_unload(Handle& h);

// Use the font referenced by h for all subsequent glwprintf() calls.
// Must be called before any glwprintf().
int unifont_bind(Handle h);

// Output text at current OpenGL modelview pos.
void glwprintf(const wchar_t* fmt, ...);

/*
  glwprintf assumes an environment roughly like:

	glEnable(GL_TEXTURE_2D);
	glDisable(GL_CULL_FACE);

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glDisable(GL_ALPHA_TEST);

	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
*/

// Intended for the GUI (hence Unicode). 'height' is roughly the height of
// a capital letter, for use when aligning text in an aesthetically pleasing way.
int unifont_stringsize(const Handle h, const wchar_t* text, int& width, int& height);

// Return spacing in pixels from one line of text to the next
int unifont_linespacing(const Handle h);

#endif // __UNIFONT_H__
