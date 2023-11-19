# HangMan
GitHub Copilot: # Word Guessing Game

This is a simple console-based word guessing game developed in C++. The game allows the player to guess letters of a hidden word within a certain number of attempts. The game is divided into different categories and levels to enhance the user experience.

## Features

- Multiple categories: Animals, Birds, Movies.
- Different levels: Easy, Medium, Hard.
- Random word selection from a file based on the chosen category and level.
- The player can guess one letter at a time.
- The number of chances is twice the length of the word.
- The game can be restarted after each round.

## How to Play

1. Run the program.
2. Choose a category and level.
3. Start guessing letters.
4. If you guess a correct letter, it will be revealed in the word.
5. If you guess the entire word correctly, you win and your score (remaining chances) will be displayed.
6. If you run out of chances before guessing the word, you lose.
7. After each round, you can choose to restart the game or exit.

## Requirements

- C++ Compiler
- Text files with words for each category and level

## Compilation and Execution

Compile the program using a C++ compiler:

```bash
g++ main.cpp -o game
```

Run the game:

```bash
./game
```

## Developer

This game was developed by Tejas Kakani.

## Disclaimer

This game is a simple project for learning and practicing C++. It is not intended for commercial use. The developer is not responsible for any misuse.
