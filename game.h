#ifndef GAME_H
#define GAME_H

#include <windows.h>

#define COLS 40 // Change board width here
#define ROWS 25 // Change board height here
#define FOODS 50
#define MAX_SNAKE_LEN 256

typedef struct
{
    int x, y;
} SnakePart;

typedef struct
{
    SnakePart part[MAX_SNAKE_LEN];
    int length;
} Snake;

typedef struct
{
    int x, y;
    int consumed;
    int consumed_counted;
} Food;

// Global variables
extern Snake snake;
extern Food food[FOODS];
extern char board[COLS * ROWS];

extern int pendingGrowth;
extern int dirX, dirY;
extern int score, highScore;
extern int isGameOver, isPaused;
extern int nextDirX, nextDirY;

// Function declarations
void setup_snake(void);
void setup_food(void);
void draw_snake(void);
void draw_food(void);
void process_food(void);
void move_snake(void);
void game_rules(void);
void reset_game(void);

void load_highscore(void);
void save_highscore(void);
void set_color(int color);

#endif
