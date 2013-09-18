#ifndef BALL_H

#define BALL_H

#include <SDL/SDL.h>
#include "court.h"
#include "paddle.h"
// Ball mechanics.
typedef struct ball {
    SDL_Rect* rect;  
    int xspeed;
    int yspeed;
} Ball;

// Allocate a new Ball.
Ball* Ball_new();

// Free a ball.
void Ball_free(Ball* b);

// Draw a ball onto an SDL Surface.
void Ball_draw(Ball* b, SDL_Surface* c);

// Reset a ball to the middle of the field.
void Ball_reset(Ball* b);

// Let the ball interact with the court and other things.
void Ball_update(Ball* b, Court* c, Paddle* p1, Paddle* p2);

#endif /* end of include guard: BALL_H */
