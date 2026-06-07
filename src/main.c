#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

int main(int argc, char **argv) {
    srand(time(NULL));
    int population[HEIGHT][WIDTH];
    int running = 1;

    initializePopulation(population);
    printf("\33[?25l");
    while (running) {
        printf("\e[1;1H\e[2J");


        assembleFrame(population);
        updatePopulation(population);
        Sleep(50);
    }

    return 0;
}

void updatePopulation(int population[HEIGHT][WIDTH]) {
    int temp_population[HEIGHT][WIDTH];
    memcpy(temp_population, population, HEIGHT*WIDTH * sizeof(int));

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int state = population[y][x];
            int surrounding = getSurrounding(population, x, y);

            if (state == 1 && (surrounding < 2 || surrounding > 3)) {
                setCellState(temp_population, x, y, 0);
            } else if (state == 0 && surrounding == 3) {
                setCellState(temp_population, x, y, 1);
            } else {
                setCellState(temp_population, x, y, state);
            }
        }
    }

    memcpy(population, temp_population, HEIGHT*WIDTH * sizeof(int));
}

int getSurrounding(int population[HEIGHT][WIDTH], int x, int y) {
    int total = 0;
    for (int iy = -1; iy < 2; iy++) {
        for (int ix = -1; ix < 2; ix++) {
            // Remove the center cell, aka itself
            if (!(ix == 0 && iy == 0)) {
                total += population[(y + iy) % HEIGHT][(x + ix) % WIDTH];
            }
        }
    }
    return total;
}

void setCellState(int population[HEIGHT][WIDTH], int x, int y, int state) {
    population[y][x] = state;
}

void initializePopulation(int population[HEIGHT][WIDTH]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int chance = rand() % 2;
            if (chance == 1) {
                population[y][x] = 1;
            } else {
                population[y][x] = 0;
            }
        }
    }
}

void assembleFrame(int population[HEIGHT][WIDTH]) {
    // + HEIGHT makes space for the new line at the end of each row
    char frameBuffer[populationSize + HEIGHT + 1];
    int i = 0;

    for (int iy = 0; iy < HEIGHT; iy++) {
        for (int ix = 0; ix < WIDTH; ix++) {
            frameBuffer[i++] = population[iy][ix] ? 'O' : ' ';
            
        }
        frameBuffer[i++] = '\n';
    }

    frameBuffer[i] = '\0';
    printf("%s", frameBuffer);
}
