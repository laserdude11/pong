#ifndef COURT_H

#define COURT_H

#include <SDL/SDL.h>

// Court mechanics.
typedef struct Court {
    int width, height;
    int scores[2];
}Court;

Court* Court_new();

void Court_free(Court* c);

void Court_render(Court* c, SDL_Surface* surf);

void Court_update(Court *c);

void Court_reset(Court* c);

void Court_score(Court* c, int player);

void Court_declare_win(Court *c, int player);

#endif /* end of include guard: COURT_H */
