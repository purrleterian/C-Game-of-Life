#define WIDTH 30
#define HEIGHT 10

#define populationSize (WIDTH * HEIGHT)

// I could just make an array of 0 and 1, but a struct
// can make the code more scalable
typedef struct Cell {
    short state;
} Cell;

void setCellState(int (*population)[WIDTH], int x, int y, int state);
int getCellState(int population[HEIGHT][WIDTH], int x, int y);
int getSurrounding(int population[HEIGHT][WIDTH], int x, int y);
void updatePopulation(int (*population)[WIDTH]);

void initializePopulation(int (*ptrPopulation)[WIDTH]);
void displayPopulation(int population[HEIGHT][WIDTH]);