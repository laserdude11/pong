#ifndef PADDLE_H

#define PADDLE_H

#include <SDL/SDL.h>
#include "court.h"

typedef struct paddle {
    SDL_Rect* rect;
    int velocity;
} Paddle;

Paddle* Paddle_new();

void Paddle_free(Paddle* p);

void Paddle_draw(Paddle* p, SDL_Surface* surf);

void Paddle_reset(Paddle* p);

void Paddle_update(Paddle* p, Court* c);

#endif /* end of include guard: PADDLE_H */
