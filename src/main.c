#include "game_of_life.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <time.h>

int main(int argc, char *argv[]) {
    const char *inputFile = NULL;
    int world[HEIGHT][WIDTH];
    int newWorld[HEIGHT][WIDTH];
    int genDelay = 1; // default delay is 1 second
    processCommandLineArgs(argc, argv, &inputFile, &genDelay);
    srand(time(NULL));
    initWorld(world, inputFile);
    while (1) {
        clearScreen();
        printWorld(world);
        updWorld(world, newWorld);
        usleepSeconds(genDelay);
    }

    return 0;
}