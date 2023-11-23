#include "main.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    // Allocate memory for cells
    Cell *population = (Cell *)malloc(sizeof(Cell) * populationSize);

    initializePopulation(population);
    displayPopulation(population);
    return 0;
}

void initializePopulation(Cell *population) {
    for (int i = 0; i < populationSize; i++) {
        population[i].state = 0;
    }
}

void displayPopulation(const Cell *population) {
    for (int i = 0; i < populationSize; i++) {
        printf("%d", population[i].state);
    }
}