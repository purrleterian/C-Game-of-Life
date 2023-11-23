#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv) {
    srand(time(NULL));
    int population[HEIGHT][WIDTH];

    initializePopulation(population);
    displayPopulation(population);
    return 0;
}

int getCellState(int (*population)[WIDTH], int x, int y) {
    return population[y][x];
}

void setCellState(int (*population)[WIDTH], int x, int y, int state) {
    population[y][x] = state;
}

void initializePopulation(int (*population)[WIDTH]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            // 50% to be alive or dead
            int randomState = rand() % 2;
            population[y][x] = randomState;
        }
    }
}

void displayPopulation(int population[HEIGHT][WIDTH]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int state = population[y][x];
            if (state == 0) {
                printf(".");
            } else {
                printf("O");
            }
        }
        printf("\n");
    }
}