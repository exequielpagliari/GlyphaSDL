#ifndef STRUCTS_H
#define STRUCTS_H

#include <SDL.h>

typedef struct {
    SDL_Renderer* renderer;
    SDL_Window* window;
} App;

typedef struct {
	int x;
	int y;
	SDL_Texture* texture;

} Entity;


typedef struct {
	int x;
	int y;
	SDL_Texture* texture;
	SDL_Rect* rect;

} AnimateEntity;

typedef struct {
	Entity fighterHead, * fighterTail;
	Entity bulletHead, * bulletTail;
} Stage;


typedef struct Textures {
	SDL_Texture* texture;
} Textures;
#endif // STRUCTS_H
