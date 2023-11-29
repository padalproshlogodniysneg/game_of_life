#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H

#define WIDTH 80
#define HEIGHT 25
#define ALIVE_CELL 1
#define DEAD_CELL 0
#define MIN_NEIGHBORS_TO_SURVIVE 2
#define MAX_NEIGHBORS_TO_SURVIVE 3
#define NEIGHBORS_FOR_REPRODUCTION 3
#define MICROSECONDS_PER_SECOND 1000000

void processCommandLineArgs(int argc, char *argv[], const char **inputFile, int *genDelay);
void usleepSeconds(int seconds);
void clearScreen();
void initWorld(int world[HEIGHT][WIDTH], const char *file);
void printWorld(int world[HEIGHT][WIDTH]);
void updWorld(int world[HEIGHT][WIDTH], int newWorld[HEIGHT][WIDTH]);
int countNeighbours(int world[HEIGHT][WIDTH], int i, int j);
void updateCellState(int currentState, int *newState, int neighbour);
void copyWorld(int source[HEIGHT][WIDTH], int destination[HEIGHT][WIDTH]);

#endif