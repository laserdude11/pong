#include <stdlib.h>
#include <stdbool.h>
#include <SDL/SDL.h>

#define PLAYER1 0
#define PLAYER2 1

#define MAXSCORE 10
#define LENGTH 20

bool is_running;

struct ball {
    int x;
    int y;
    int xspeed;
    int yspeed;
} Ball;

struct paddle {
    int y;
    //int length;
};

struct paddle p1;
struct paddle p2;

int playerscores[] = {0, 0};

SDL_Surface* screen;

int screensize[] = {800, 600};

void declarewin(int player){
    // TODO: Add a dialog saying that the player won
    is_running = false;    
}

void score(int player)
{
    playerscores[player] = playerscores[player] + 1;
    if (playerscores[player] >= MAXSCORE) declarewin(player);
}

void reset_ball(){
    Ball.x = 300;
    Ball.y = 400;
    Ball.xspeed = 1;
    Ball.yspeed = 1; 
}

void reset_paddle(struct paddle* p){
    p->y = 290;
}

void setupGame()
{
     screen = SDL_SetVideoMode(screensize[0], screensize[1], 32, SDL_SWSURFACE);
     reset_paddle(&p1);
     reset_paddle(&p2);
     reset_ball();
}

void loop()
{
    while(is_running){
        
        update_paddle(p1);
        update_paddle(p2);
        update_ball(Ball);
        redraw();
    }
}

int main(int argc, char* argv[]){
    is_running = true;
    SDL_Init(SDL_INIT_VIDEO);
    atexit(SDL_Quit);
    setupGame();
    loop();
    return 0;
}
