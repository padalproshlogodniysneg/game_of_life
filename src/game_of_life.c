#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <time.h>
#include "game_of_life.h"

// сommand line arguments processing
void processCommandLineArgs(int argc, char *argv[], const char **inputFile, int *genDelay) {
    int opt;

    while ((opt = getopt(argc, argv, "f:s:")) != -1) {
        switch (opt) {
        case 'f':
            *inputFile = optarg;
            break;
        case 's':
            *genDelay = atoi(optarg);
            break;
        default:
            // display usage information in case of an error
            fprintf(stderr, "Usage: %s [-f input_file] [-s delay_seconds]\n", argv[0]);
            exit(EXIT_FAILURE);
        }
    }
}

// clear terminal screen
void clearScreen() {
    printf("\033[H\033[J");
}

// initialize the world from a file or with random values
void initWorld(int world[HEIGHT][WIDTH], const char *file) {
    if (file != NULL) {
        FILE *fp = fopen(file, "r");
        if (fp != NULL) {
            for (int i = 0; i < HEIGHT; i++) {
                for (int j = 0; j < WIDTH; j++) {
                    // reading values from a file
                    if (fscanf(fp, "%1d", &world[i][j]) != 1) {
                        world[i][j] = DEAD_CELL;
                    }
                }
            }
            fclose(fp);
        }
    } else {
        // initialization with random values
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                world[i][j] = rand() % 2;
            }
        }
    }
}

// print the state of the world to the screen
void printWorld(int world[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            // display '*' for a live cell, space for a dead cell
            if (world[i][j] == ALIVE_CELL) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// update the state of the world
void updWorld(int world[HEIGHT][WIDTH], int newWorld[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int neighbour = countNeighbours(world, i, j);
            updateCellState(world[i][j], &newWorld[i][j], neighbour);
        }
    }
    copyWorld(newWorld, world);
}

// count the number of live neighbors
int countNeighbours(int world[HEIGHT][WIDTH], int i, int j) {
    int neighbour = 0;
    for (int x = -1; x <= 1; x++) {
        for (int y = -1; y <= 1; y++) {
            if (!(x == 0 && y == 0)) {
                int new_i = (i + x + HEIGHT) % HEIGHT;
                int new_j = (j + y + WIDTH) % WIDTH;
                neighbour += world[new_i][new_j];
            }
        }
    }
    return neighbour;
}

// update the state of a cell
void updateCellState(int currentState, int *newState, int neighbour) {
    if (currentState == ALIVE_CELL) {
        // rules for a live cell
        *newState = (neighbour < MIN_NEIGHBORS_TO_SURVIVE || neighbour > MAX_NEIGHBORS_TO_SURVIVE) ? DEAD_CELL : ALIVE_CELL;
    } else {
        // rules for a dead cell
        *newState = (neighbour == NEIGHBORS_FOR_REPRODUCTION) ? ALIVE_CELL : DEAD_CELL;
    }
}

// copy the world from one array to another
void copyWorld(int source[HEIGHT][WIDTH], int destination[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            destination[i][j] = source[i][j];
        }
    }
}

// sleep for the specified number of seconds
void usleepSeconds(int seconds) {
    usleep(seconds * MICROSECONDS_PER_SECOND);
}
