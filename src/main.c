#include "main.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    // Allocate memory for cells
    Cell **population = malloc(populationSize * sizeof(Cell *));

    initializePopulation(population);

    setCell(population, 2, 2);
    displayPopulation(population);
    return 0;
}

void initializePopulation(Cell **population) {
    for (int i = 0; i < populationSize; i++) {
        population[i] = malloc(sizeof(Cell *));
        population[i]->state = 0;
    }
}

void displayPopulation(Cell **population) {
    for (int i = 0; i < populationSize; i++) {
        printf("%d", population[i]->state);
        if (i % WIDTH == WIDTH - 1) {
            printf("\n");
        }
    }
    printf("\n");
}

void setCell(Cell **population, int x, int y) {}