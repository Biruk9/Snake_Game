Snake Game in C

Overview:
This is a console-based Snake Game written in C for Windows. It demonstrates modular programming, file handling, console UI, and real time game logic. The game features:

- Dynamic snake movement with WASD controls.
- Multiple food items on the board.
- Score tracking and high score persistence (highscore.dat).
- Increasing speed as score increases (level system).
- Pause functionality.
- Start screen and Game Over menu.
- Colored console output for better visual experience.
- Modular code structure: main.c, game.c, ui.c, game.h, ui.h.

Game Controls:
W     - Move Up
A     - Move Left
S     - Move Down
D     - Move Right
P     - Pause / Resume
ENTER - Start Game (from Start Screen)
Q     - Quit Game
R     - Restart Game (from Game Over Menu)

Installation & Compilation:
1. Clone the repository:
   git clone https://github.com/Biruk9/snake-game.git
   cd snake-game

2. Compile using GCC (Windows):
   gcc main.c game.c ui.c -o snake.exe 

3. Run the game:
   snake.exe

Note: This game is designed for Windows console.It uses windows.h for cursor control and conio.h for keyboard input.

Folder Structure:
main.c         - Entry point
game.c         - Game logic: snake, food, movement, collisions
ui.c           - Console rendering, start screen, game over menu
game.h         - Game constants, structs, function declarations
ui.h           - UI function declarations (note: rename short global 'UI' to a descriptive name like 'ui_manager' to avoid ambiguous global names)
highscore.dat  - Stores the high score (created after first run)
README.md      - This file

Features & Future Improvements:
Current Features:
- High-score tracking
- Start screen & Game Over menu
- Colored console output
- Increasing difficulty
- Pause & Resume

Future Improvements:
- Multiple levels with different board layouts
- Multiple food types (bonus points, speed boosts)
- Sound effects for eating and game over
- Cross-platform support (Linux/Mac)
- Save and load game state

Technologies:
Language: C (C99 standard)
Libraries: windows.h for console control, conio.h for keyboard input
Platform: Windows console application

Contribution:
Feel free to fork this repository, make improvements, and submit a pull request! If you find bugs or have suggestions, open an issue.


