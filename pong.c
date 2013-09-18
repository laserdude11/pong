// Pong implementation.

#include <stdlib.h>
#include <stdbool.h>
#include <SDL/SDL.h>
#include "dbg.h"
#include "game.h"
#include "ball.h"
#include "paddle.h"
#include "court.h"

// * Game-wide structures.

int playerscores[] = {0, 0};

unsigned short screensize[] = {800, 600};

// Colors.
typedef Uint32 Color;

Color white;

void update(Court* c, Paddle* p1, Paddle* p2, Ball* b)
{
    Court_update(c);
    Paddle_update(p1, c);
    Paddle_update(p2, c);
    Ball_update(b, c, p1, p2);
}


void redraw(Court* c, Paddle* p1, Paddle* p2, Ball* b, SDL_Surface* screen){
    SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0x00, 0x00, 0x00)); 
    Court_draw(c, screen);
    Paddle_draw(p1, screen);
    Paddle_draw(p2, screen);
    Ball_draw(b, screen);
    SDL_Flip(screen);
}

void handle_keydown(int code){
    switch(code){
        case SDLK_ESCAPE: {
            // PAUSE
            is_running = false;
            break;
        }
        default:
            break;
    }
}

int handle_event(SDL_Event* event){
    switch(event->type){
        case SDL_KEYDOWN: {
            handle_keydown(event->key.keysym.sym);
            break;
        }
        case SDL_QUIT:
            is_running = false;
            break;
        default: {
            fprintf(stderr, "Warning: action not handled.");
            break;
        }
    }
}

void showStartMenu(){
    
}

void loop(Court* c, Paddle* p1, Paddle* p2, Ball* b, SDL_Surface* screen)
{
    showStartMenu();
    SDL_Event event;
    while(is_running){
        while (SDL_PollEvent(&event)){
            handle_event(&event);
        }
        update(c, p1, p2, b);
        redraw(c, p1, p2, b, screen);
    }
}

int main(int argc, char* argv[]){
    
    SDL_Surface* screen = NULL;
    is_running = true;
    SDL_Init(SDL_INIT_VIDEO);
    atexit(SDL_Quit);
    Court* c = Court_new();
    Paddle* p1 = Paddle_new(0);
    Paddle* p2 = Paddle_new(1); 
    Ball *b = Ball_new();
    screen = SDL_SetVideoMode(screensize[0], screensize[1], 32, SDL_SWSURFACE);
    loop(c, p1, p2, b, screen);
    Court_free(c);
    Paddle_free(p1);
    Paddle_free(p2);
    Ball_free(b);
    return 0;
}
