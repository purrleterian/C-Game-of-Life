#include "main.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int population[HEIGHT][WIDTH];

    initializePopulation(population);
    displayPopulation(population);
    return 0;
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
            printf("%d", population[y][x]);
        }
        printf("\n");
    }
}