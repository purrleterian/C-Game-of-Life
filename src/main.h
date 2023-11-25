#define WIDTH 65
#define HEIGHT 20
#define populationSize WIDTH* HEIGHT

// I could just make an array of 0 and 1, but a struct
// can make the code more scalable
typedef struct Cell {
    short state;
} Cell;

void setCellState(int (*population)[WIDTH], int x, int y, int state);
int getSurrounding(int population[HEIGHT][WIDTH], int x, int y);
void updatePopulation(int (*population)[WIDTH]);

void assembleFrame(int population[HEIGHT][WIDTH]);

void initializePopulation(int (*ptrPopulation)[WIDTH]);
void displayPopulation(int population[HEIGHT][WIDTH]);