#include <stdlib.h>
#include <stdbool.h>
#include <SDL/SDL.h>

// ** Declarations.

// * Definitions.
#define PLAYER1 0
#define PLAYER2 1
#define MAXSCORE 10
#define LENGTH 20
#define PADDLE1X 
#define PADDLE2X


// * Game-wide structures.
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
} p1, p2;

int playerscores[] = {0, 0};

SDL_Surface* screen;

int screensize[] = {800, 600};

// ** Function Declarations.
void declare_win(int player);
void loop();
void reset_ball();
void reset_paddle(struct paddle* p);
void score(int player);
void setup_game();
void update_ball();
void update_paddle();

// Declare a winner of the game.
void declare_win(int player){
    // TODO: Add a dialog saying that the player won
    is_running = false;    
}

void score(int player)
{
    playerscores[player] = playerscores[player] + 1;
    if (playerscores[player] >= MAXSCORE) declarewin(player);
}

void update_ball(){
    // Check if the ball needs to interact with a paddle or score
    if (Ball.x >= PADDLE2X){
        if (Ball.y <= p2.y && Ball.y >= p2.y + LENGTH){
            Ball.xspeed = -(Ball.xspeed);
        } else {
            score(PLAYER1);
            reset_round();
            return;
        }

    } else if (Ball.x <= PADDLE1X){
        if (ball.y <= p1.y && ball.y >= p1.y + LENGTH){
            Ball.xspeed = -(Ball.xspeed);
        } else {
            score(PLAYER2);
            reset_round();
            return;
        }
    }
    // bounce off of the walls if it connects with the top or bottom
    if (Ball.y >= TOP || Ball.y <= BOTTOM){
        Ball.yspeed = -(Ball.yspeed);
    }
    Ball.x += Ball.xspeed;
    Ball.y += Ball.yspeed;
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

void update_paddle(){
    
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
