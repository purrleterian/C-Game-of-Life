#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv) {
    srand(time(NULL));
    int population[HEIGHT][WIDTH];
    int running = 1;

    initializePopulation(population);
    printf("\33[?25l");
    while (running) {
        displayPopulation(population);
        updatePopulation(population);
        system("clear");
    }

    return 0;
}

void updatePopulation(int (*population)[WIDTH]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int state = population[y][x];
            int surrounding = getSurrounding(population, x, y);
            if (state == 1 && (surrounding < 2 || surrounding > 3)) {
                setCellState(population, x, y, 0);
            } else if (state == 0 && (surrounding == 3)) {
                setCellState(population, x, y, 1);
            } else {
                setCellState(population, x, y, state);
            }
        }
    }
}

int getSurrounding(int population[HEIGHT][WIDTH], int x, int y) {
    int total = 0;
    for (int iy = -1; iy < 2; iy++) {
        for (int ix = -1; ix < 2; ix++) {
            // Remove the center cell, aka itself
            if (!(ix == 0 && iy == 0))
                total += population[(y + iy) % HEIGHT][(x + ix) % WIDTH];
        }
    }
    return total;
}

void setCellState(int (*population)[WIDTH], int x, int y, int state) {
    population[y][x] = state;
}

void initializePopulation(int (*population)[WIDTH]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
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