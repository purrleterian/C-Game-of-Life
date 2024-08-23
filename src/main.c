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
        assembleFrame(population);
        updatePopulation(population);
        Sleep(10);
        system("cls");
    }

    return 0;
}

void updatePopulation(int population[HEIGHT][WIDTH]) {
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

void setCellState(int population[HEIGHT][WIDTH], int x, int y, int state) {
    population[y][x] = state;
}

void initializePopulation(int population[HEIGHT][WIDTH]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            population[y][x] = (int)rand() % 2;
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

void assembleFrame(int population[HEIGHT][WIDTH]) {
    char frameBuffer[populationSize + HEIGHT];
    int i = 0;
    while (i < populationSize) {
        for (int iy = 0; iy < HEIGHT; iy++) {
            for (int ix = 0; ix < WIDTH; ix++) {
                if (population[iy][ix] == 1) {
                    frameBuffer[i] = 'O';
                } else if (population[iy][ix] == 0) {
                    frameBuffer[i] = '.';
                }
                if ((i % WIDTH) == WIDTH - 1) {
                    frameBuffer[i] = '\n';
                }
                frameBuffer[i + 1] = '\0';
                i++;
            }
        }
    }
    printf("%s", frameBuffer);
}
