#include "ui.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

void set_color(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void hide_cursor() {
    CONSOLE_CURSOR_INFO info = {100, FALSE};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void move_cursor_to_top() {
    COORD coord = {0, 0};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void print_board() {
    for (int y = 0; y < ROWS; y++) {
        for (int x = 0; x < COLS; x++) {
            char cell = board[y * COLS + x];
            if (cell == '@') set_color(12);
            else if (cell == '*') set_color(14);
            else if (cell == '+') set_color(10);
            else if (cell == '#') set_color(15);
            else set_color(7);
            putchar(cell);
        }
        putchar('\n');
    }
    set_color(7);
}

void show_start_screen() {
    system("cls");
    set_color(11);
    printf("================================\n");
    printf("        S N A K E   G A M E     \n");
    printf("================================\n\n");

    set_color(15);
    printf("Controls:\nW/A/S/D - Move\nP - Pause\nQ - Quit\n\n");
    set_color(10);
    printf("Press ENTER to Start...\n");

    while (!GetAsyncKeyState(VK_RETURN)) Sleep(50);
}

void show_game_over_menu() {
    system("cls");
    set_color(12);
    printf("\n ==== GAME OVER ==== \n\n");

    set_color(15);
    printf("Score: %d\nHigh Score: %d\n\n", score, highScore);

    set_color(10);
    printf("Press 'R' to Restart or 'Q' to Quit\n");

    while (1) {
        if (_kbhit()) {
            int ch = getch();
            if (ch == 'r' || ch == 'R') break;
            if (ch == 'q' || ch == 'Q') exit(0);
        }
        Sleep(100);
    }
}
