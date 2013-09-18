#include "paddle.h"

Paddle* Paddle_new(int player){
    Paddle* this = calloc(1, sizeof(Paddle));
    this->velocity = 0;
    this->rect = calloc(1, sizeof(SDL_Rect));
    this->rect->w = 2;
    this->rect->h = 100; 
    if (player == 0) this->rect->x = 5;
    else if (player == 1) this->rect->x = 800 - 5;
    return this;    
}

void Paddle_free(Paddle* p){
    free(p->rect); 
    free(p);
}

void Paddle_draw(Paddle *p, SDL_Surface* surf)
{
    SDL_FillRect(surf, p->rect, SDL_MapRGB(surf->format, 0xff, 0x00, 0x00)); 
}

void Paddle_update(Paddle *p, Court *c)
{
    p->rect->y += p->velocity; 
    if (p->rect->y <= 0 || p->rect->y + p->rect->h >= 600){ 
        p->velocity = 0;
    }
}

void Paddle_setVel(Paddle *p, int vel){
    p->velocity = vel;
}

void Paddle_reset(Paddle* p){
    p->rect->y = (600/2) - (p->rect->h/2);
}


