#include "dbg.h"
#include "game.h"
#include "ball.h"
#include "paddle.h"
#include "court.h"

Court *Court_new(){
    Court *c = malloc(sizeof(Court));
    return c; 
}

void Court_free(Court *c)
{
    free(c);
}


void Court_update(Court *c)
{
    
}


void Court_reset(Court* c)
{

}

void Court_draw(Court* c, SDL_Surface* surf)
{
    /* code */
}

// Declare a winner of the game.
void Court_declare_win(Court *c, int player)
{
    // TODO: Add a dialog saying that the player won
    printf("Player %d won!\n", player+1);
    is_running = false;    
}

// Register a score and 
void Court_score(Court *c, int player){
    debug("Player %d scored. %d | %d", player+1, c->scores[0], c->scores[1]);
    c->scores[player] = c->scores[player] + 1;
    if (c->scores[player] >= maxscore) Court_declare_win(c, player);
}

