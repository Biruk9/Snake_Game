
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define cols 10
#define rows 10

char board[cols * rows];
int isGameOver = 0;
void fill_board()
{

    int x, y;
    for (y = 0; y < rows; y++)
    {
        for (x = 0; x < cols; x++)
        {
            if (x == 0 || y == 0 || x == cols - 1 || y == rows - 1)

                board[y * cols + x] = '#';
            else
                board[y * cols + x] = ' ';
        }
    }
}

void Clear_Screen()
{

    system("cls");
}

void print_board()
{
    int x, y;

    Clear_Screen();

    for (y = 0; y < rows; y++)
    {
        for (x = 0; x < cols; x++)
        {
            putchar(board[y * cols + x]);
        }
        putchar('\n');
    }
}

int snakeX = 5;
int snakeY = 5;

void draw_snake()
{
    board[snakeY * cols + snakeX] = '@';
}

void move_snake(int deltaX, int deltaY)
{
    snakeX += deltaX;
    snakeY += deltaY;
}
void read_Keyboard()
{
    int ch = getch();

    switch (ch)
    {

    case 'w':
        move_snake(0, -1);
        break;
    case 's':
        move_snake(0, 1);
        break;
    case 'a':
        move_snake(-1, 0);
        break;
    case 'd':
        move_snake(1, 0);
        break;
    }
}
int main(int argc, char **a)
{
    while (!isGameOver)
    {

        fill_board();
        draw_snake();
        print_board();
        read_Keyboard();
    }

    return 0;
}
