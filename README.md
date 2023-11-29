# Game of Life

This is a simple implementation of Conway's Game of Life in C. The program allows you to simulate the evolution of a cellular automaton based on a set of predefined rules.

## Features

- **Random Initialization**: The program can generate a random initial state for the game.
- **File Initialization**: You can also provide an input file to initialize the game's initial state.
- **Command Line Options**: Customize the program's behavior using command line options.
- **Terminal-based Display**: The game state is displayed in the terminal, with a clear screen between generations.
- **Adjustable Generation Delay**: Control the speed of the simulation with an adjustable delay between generations.

## How to Use

### Compilation

To compile the program, use the provided Makefile:

```bash
make
```

### Command Line Options
- -f FILE: Specify an input file to initialize the world.
- -s SECONDS: Set the delay between generations in seconds.

Example:

```bash
./build/game_of_life -f input.txt -s 1
```

This command initializes the world using the contents of input.txt and sets a generation delay of 1 second.

### Clean

To clean the build artifacts, run:

```bash
make clean
```

## Rules
The rules of Conway's Game of Life:

- A live cell with fewer than 2 live neighbors dies (underpopulation).
- A live cell with more than 3 live neighbors dies (overpopulation).
- A live cell with 2 or 3 live neighbors survives.
- A dead cell with exactly 3 live neighbors becomes alive (reproduction).

## File Format

If you choose to initialize the world using a file, the file should represent the initial state of the world. Use 0 for dead cells and 1 for live cells. Each line of the file corresponds to a row in the world.

```bash
00000000
00010000
00001000
00111000
00000000
```

## Source Code
The source code is organized into the following files:

- main.c: Contains the main function and program entry point.
- game_of_life.c: Implements the core logic of the Game of Life.
- game_of_life.h: Header file with function declarations and constants.
- Makefile: Makefile for compiling the program.
