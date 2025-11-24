#include "game.h"
#include "ui.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

void read_keyboard() {
    if (_kbhit()) {
        int ch = getch();
        if (ch >= 'A' && ch <= 'Z') ch = ch - 'A' + 'a';

        switch(ch) {
            case 'w': nextDirX=0; nextDirY=-1; break;
            case 's': nextDirX=0; nextDirY=1; break;
            case 'a': nextDirX=-1; nextDirY=0; break;
            case 'd': nextDirX=1; nextDirY=0; break;
            case 'p': isPaused = !isPaused; break;
        }
    }
}

int main() {
    srand(time(0));
    hide_cursor();
    load_highscore();
    show_start_screen();

    while (1) {
        reset_game();

        while (!isGameOver) {
            for (int i = 0; i < ROWS * COLS; i++) board[i] = ' ';
            for (int y = 0; y < ROWS; y++) {
                board[y*COLS] = '#';
                board[y*COLS+COLS-1] = '#';
            }
            for (int x = 0; x < COLS; x++) {
                board[x] = '#';
                board[(ROWS-1)*COLS + x] = '#';
            }

            draw_food();
            draw_snake();
            game_rules();
            process_food();
            move_cursor_to_top();
            printf("Score: %d  Level: %d\nHighScore: %d\n", score, score/500+1, highScore);
            if (isPaused) printf("*** PAUSED - press 'p' to continue ***\n");
            print_board();

            if (!isPaused) move_snake();
            if (!isGameOver) read_keyboard();

            int level = score / 500 + 1;
            int delay = 200 - (level-1)*20;
            if (delay < 50) delay = 50;
            Sleep(delay);
        }

        if (score > highScore) {
            highScore = score;
            save_highscore();
        }

        show_game_over_menu();
    }

    return 0;
}
