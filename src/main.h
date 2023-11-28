#define WIDTH 90
#define HEIGHT 25
#define populationSize (WIDTH * HEIGHT)

// I could just make an array of 0 and 1, but a struct
// can make the code more scalable
typedef struct Cell {
    short state;
} Cell;

void setCellState(int population[HEIGHT][WIDTH], int x, int y, int state);
int getSurrounding(int population[HEIGHT][WIDTH], int x, int y);
void updatePopulation(int population[HEIGHT][WIDTH]);

void assembleFrame(int population[HEIGHT][WIDTH]);

void initializePopulation(int population[HEIGHT][WIDTH]);
void displayPopulation(int population[HEIGHT][WIDTH]);