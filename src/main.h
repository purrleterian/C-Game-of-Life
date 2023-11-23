#define WIDTH 50
#define HEIGHT 10

#define populationSize (WIDTH * HEIGHT)

// I could just make an array of 0 and 1, but a struct
// can make the code more scalable
typedef struct Cell {
    short state;
} Cell;

void initializePopulation(int (*ptrPopulation)[WIDTH]);
void displayPopulation(int population[HEIGHT][WIDTH]);