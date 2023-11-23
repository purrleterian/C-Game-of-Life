#include "main.h"

#include <stdio.h>

// I could just make an array of 0 and 1, but a struct
// can make the code more scalable
typedef struct Cell {
    int state;
} Cell;

int main(int argc, char **argv) {
    // Allocate memory for cells
    // Cell *population = (Cell *)malloc(sizeof(Cell) * (width * height));
    Cell population[populationSize];

    return 0;
}