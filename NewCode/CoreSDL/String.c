//
// Created by exepa on 10/1/25.
//
#include <string.h>
#include "String.h"

// Convierte un C-string a Str255 (como haría Pascal)
void CtoPStr255(Str255 dest, const char *src) {
    size_t len = strlen(src);
    if (len > 255) len = 255;       // Limitar a 255 caracteres
    dest[0] = (unsigned char)len;   // Primer byte = longitud
    memcpy(&dest[1], src, len);     // Copiar los caracteres
}

// Convierte Str255 a un C-string (útil para debug)
void PtoCStr255(const Str255 src, char *dest) {
    size_t len = src[0];
    memcpy(dest, &src[1], len);
    dest[len] = '\0';               // Null terminator para C-string
}

// Convierte un C-string a Str15
void CtoPStr15(Str15 dest, const char *src) {
    size_t len = strlen(src);
    if (len > 15) len = 255;       // Limitar a 15 caracteres
    dest[0] = (unsigned char)len;   // Primer byte = longitud
    memcpy(&dest[1], src, len);     // Copiar los caracteres
}

// Convierte Str15 a un C-string (útil para debug)
void PtoCStr15(const Str15 src, char *dest) {
    size_t len = src[0];
    memcpy(dest, &src[1], len);
    dest[len] = '\0';               // Null terminator para C-string
}