#define WIDTH 30
#define HEIGHT 10

#define populationSize (WIDTH * HEIGHT)

// I could just make an array of 0 and 1, but a struct
// can make the code more scalable
typedef struct Cell {
    short state;
} Cell;

void initializePopulation(Cell **population);
void displayPopulation(Cell **population);
void setCell(Cell **population, int x, int y);