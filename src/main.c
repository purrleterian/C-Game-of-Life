#include "main.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int population[HEIGHT][WIDTH];

    initializePopulation(population);

    setCellState(population, 1, 1, 1);
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
            population[y][x] = 0;
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