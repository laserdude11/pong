#ifndef GAME_H

#define GAME_H

#include <stdbool.h>

// * Definitions.
static int player1 = 0;
static int player2 = 1;
static int maxscore = 10;
static int length = 20;
static int paddle1x = 2;
static int paddle2x = 799;
static int bottom = 600;
static int top = 0;

bool is_running;

void reset();
#endif /* end of include guard: GAME_H */
