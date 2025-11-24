#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

// Global variables
Snake snake;
Food food[FOODS];
char board[COLS * ROWS];

int pendingGrowth = 0;
int dirX = 1, dirY = 0;
int nextDirX = 1, nextDirY = 0;
int score = 0, highScore = 0;
int isGameOver = 0, isPaused = 0;

void load_highscore() {
    FILE *file = fopen("highscore.dat", "r");
    if (!file) { highScore = 0; return; }
    fscanf(file, "%d", &highScore);
    fclose(file);
}

void save_highscore() {
    FILE *file = fopen("highscore.dat", "w");
    if (!file) return;
    fprintf(file, "%d", highScore);
    fclose(file);
}

void setup_snake() {
    snake.length = 3;
    for (int i = 0; i < snake.length; i++) {
        snake.part[i].x = 1 + rand() % (COLS - 2);
        snake.part[i].y = 1 + rand() % (ROWS - 2);
    }
}

void setup_food() {
    for (int i = 0; i < FOODS; i++) {
        food[i].x = 1 + rand() % (COLS - 2);
        food[i].y = 1 + rand() % (ROWS - 2);
        food[i].consumed = 0;
        food[i].consumed_counted = 0;
    }
}

void draw_snake() {
    for (int i = 0; i < snake.length; i++) {
        board[snake.part[i].y * COLS + snake.part[i].x] = (i == 0) ? '@' : '*';
    }
}

void draw_food() {
    for (int i = 0; i < FOODS; i++) {
        if (!food[i].consumed)
            board[food[i].y * COLS + food[i].x] = '+';
    }
}

void process_food() {
    for (int i = 0; i < FOODS; i++) {
        if (food[i].consumed && !food[i].consumed_counted) {
            score += 100;
            food[i].consumed_counted = 1;
            food[i].x = 1 + rand() % (COLS - 2);
            food[i].y = 1 + rand() % (ROWS - 2);
            food[i].consumed = 0;
            food[i].consumed_counted = 0;
        }
    }
}

void move_snake() {
    if (!(nextDirX == -dirX && nextDirY == -dirY)) {
        dirX = nextDirX;
        dirY = nextDirY;
    }

    SnakePart oldTail = snake.part[snake.length - 1];
    for (int i = snake.length - 1; i > 0; i--) {
        snake.part[i] = snake.part[i - 1];
    }

    snake.part[0].x += dirX;
    snake.part[0].y += dirY;

    if (pendingGrowth > 0 && snake.length < MAX_SNAKE_LEN) {
        snake.part[snake.length] = oldTail;
        snake.length++;
        pendingGrowth--;
    }
}

void game_rules() {
    for (int i = 0; i < FOODS; i++) {
        if (!food[i].consumed && snake.part[0].x == food[i].x && snake.part[0].y == food[i].y) {
            food[i].consumed = 1;
            pendingGrowth += 2;
        }
    }

    if (snake.part[0].x <= 0 || snake.part[0].x >= COLS - 1 || snake.part[0].y <= 0 || snake.part[0].y >= ROWS - 1)
        isGameOver = 1;

    for (int i = 1; i < snake.length; i++)
        if (snake.part[0].x == snake.part[i].x && snake.part[0].y == snake.part[i].y)
            isGameOver = 1;
}

void reset_game() {
    score = 0;
    isGameOver = 0;
    isPaused = 0;
    dirX = 1; dirY = 0;
    nextDirX = 1; nextDirY = 0;
    pendingGrowth = 0;

    setup_snake();
    setup_food();
}
