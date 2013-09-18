#include "ball.h"

Ball* Ball_new(){
    Ball* b = calloc(0, sizeof(Ball));
    b->rect = calloc(0, sizeof(SDL_Rect));
    b->rect->w = 3;
    b->rect->h = 3;
    Ball_reset(b); 
    return b;
}

void Ball_free(Ball *b){
    free(b->rect); 
    free(b);
}

void Ball_draw(Ball *b, SDL_Surface *surf){
    SDL_FillRect(surf, b->rect, SDL_MapRGB(surf->format, 0xff, 0xff, 0xff)); 
}


void Ball_reset(Ball *b){
    b->rect->x = 300;
    b->rect->y = 400;

    // TODO: Do this randomly?
    b->xspeed = 1;
    b->yspeed = 1; 
}

void reset(Ball *b, Court *w, Paddle* p1, Paddle* p2){
    Ball_reset(b);
    Court_reset(w);
    Paddle_reset(p1);
    Paddle_reset(p2);
}

void Ball_update(Ball *b, Court *w, Paddle* p1, Paddle* p2){
    
    // Recreate the ball's rectangle
     
    b->rect->x += b->xspeed;
    b->rect->y += b->yspeed;

    // Check if the Ball needs to interact with a paddle or score
    if (b->rect->x <= p1->rect->x){
        if (Rect_collide(b->rect, p1->rect)){
            b->xspeed = -(b->xspeed);
        } else {
            Court_score(w, 0);
            reset(b, w, p1, p2);
            return;
        }

    } else if (b->rect->x >= p2->rect->x){
        if (Rect_collide(b->rect, p2->rect)){
            b->xspeed = -(b->xspeed);
        } else {
            Court_score(w, 1);
            reset(b, w, p1, p2);
            return;
        }
    }
    // bounce off of the walls if it connects with the top or bottom
    if (b->rect->y <= 0 || b->rect->y + b->rect->h >= 600){
        b->yspeed = -(b->yspeed);
    }
}

