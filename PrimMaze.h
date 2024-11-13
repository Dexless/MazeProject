#include <iostream>
#include <vector>
#include <cstdlib>   // For rand()
#include <ctime>     // For time()

using namespace std;

const int WIDTH = 20;        // Maze playable width
const int HEIGHT = 10;       // Maze playable height
const int MAZE_WIDTH = WIDTH * 2 + 1;   // Full grid width (including walls)
const int MAZE_HEIGHT = HEIGHT * 2 + 1; // Full grid height (including walls)

// 1D to 2D conversion (returns row based on 1D index)
int indexTo2DRow(int index) 
{
    return 0;
}

// 1D to 2D conversion (returns col based on 1D index)
int indexTo2DCol(int index) 
{
    return 0;
}

// 2D to 1D conversion (converts row and column into 1D index)
int indexFrom2D(int row, int col) 
{
    return 0;
}

// Check if a cell is within bounds
bool isValid(int row, int col) 
{
    return true;
}

// Draw the maze using cout
void drawMaze(const vector<char>& maze) 
{
    for (int i = 0; i < MAZE_HEIGHT; ++i) 
    {
        for (int j = 0; j < MAZE_WIDTH; ++j) 
        {
            cout << maze[indexFrom2D(i, j)];
        }
        cout << endl;
    }
}

// Prim's algorithm to generate the maze
void primMaze() 
{
    vector<char> maze(MAZE_WIDTH * MAZE_HEIGHT, '#'); // Initialize all cells as walls
    vector<int> frontier; // Frontier will store 1D indices of frontier walls

    srand(time(0));  // Seed for random number generator

    // Start at a random point on the grid (must be an odd coordinate)
    int startRow = rand() % HEIGHT * 2 + 1;
    int startCol = rand() % WIDTH * 2 + 1;

    maze[indexFrom2D(startRow, startCol)] = ' ';  // Mark starting point as an open space

    //Your code here

    // Add neighboring cells to the frontier list (in 1D index form)
    // Use four seperate if statements to check if the location 2 spaces away is valid
    // in the NORTH, SOUTH, EAST, and WEST directions.
    // If a location is valid, push it's location index onto the frontier vector.


    // Prim's algorithm loop
    // Begin a while loop that will end when the frontier is empty
    while (!frontier.empty()) 
    {
        int randIndex; // = Pick a random frontier cell
        int frontierCell; // = Store the index found there 
        frontier.erase(frontier.begin() + randIndex);  // Remove from frontier list

        int frontierRow; // = Convert the frontier cell (1D index) to 2D row
        int frontierCol; // = Convert the frontier cell (1D index) to 2D col

        vector<int> mazeNeighbors;  //Make an empty list to store potential new neighbors.
        // Check neighbors that are part of the maze (2-cell jump away)
        //   Use 4 seperate if statements to ask if a location 2 spaces away from
        //   frontierCell in each direction, N,S,E,W, isValid AND is open (' ')
        //   If it is both, push its index onto the the mazeNeighbors vector.

        // If there are valid neighbors in the maze, carve a path between the frontier and ONE of its neighbors
        if (!mazeNeighbors.empty()) 
        {
            int neighbor = mazeNeighbors[rand() % mazeNeighbors.size()];  // Random neighbor
            int neighborRow; // = Convert neighbor (1D index) to 2D row
            int neighborCol;// = Convert neighbor (1D index) to 2D col

            // Carve the path (remove the wall between them)
            //   Use (frontierRow + neighborRow) / 2 to find the row between them.
            //   Use (frontierCol + neighborcol) / 2 to find the col between them.
            //   Set the cell between to ' '
            //   Set the frontierCell to ' '

            // Add new frontier cells (neighbors of the current frontier cell)
            //   Use 4 seperate if statements to ask if a location 2 spaces away from
            //   frontierCell in each direction, N,S,E,W, isValid AND is closed ('#')
            //   If it is both, push its index onto the the frontier vector.
        }
    }

    // Draw the resulting maze
    drawMaze(maze);
}

int main() {
    primMaze();  // Generate and display the maze
    return 0;
}
