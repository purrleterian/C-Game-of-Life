#define WIDTH 30
#define HEIGHT 30

#define populationSize (WIDTH * HEIGHT)

// I could just make an array of 0 and 1, but a struct
// can make the code more scalable
typedef struct Cell {
    int state;
} Cell;



void displayPopulation(const Cell *population);
void initializePopulation(Cell *population);
