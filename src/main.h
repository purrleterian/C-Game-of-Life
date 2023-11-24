#define WIDTH 35
#define HEIGHT 10

// I could just make an array of 0 and 1, but a struct
// can make the code more scalable
typedef struct Cell {
    short state;
} Cell;

void setCellState(int (*population)[WIDTH], int x, int y, int state);
int getSurrounding(int population[HEIGHT][WIDTH], int x, int y);
void updatePopulation(int (*population)[WIDTH]);

void initializePopulation(int (*ptrPopulation)[WIDTH]);
void displayPopulation(int population[HEIGHT][WIDTH]);