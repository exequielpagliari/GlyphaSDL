//
// Created by exepa on 10/1/25.
//

#ifndef SDLMACOSWRAPPER_STRING_H
#define SDLMACOSWRAPPER_STRING_H

#pragma once
#include "SDL_Utilities.h"


void CtoPStr255(Str255 dest, const char *src);
void PtoCStr255(const Str255 src, char *dest);
void CtoPStr15(Str15 dest, const char *src);
void PtoCStr15(const Str15 src, char *dest);


#endif //SDLMACOSWRAPPER_STRING_H