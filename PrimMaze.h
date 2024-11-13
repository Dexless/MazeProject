#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>   // For rand()
#include <ctime>     // For time()

using namespace std;

class PrimMaze
{
private:
    vector<char> maze;
    int width;
    int height;
    int mazewidth;
    int mazeheight;

    void setMaze()
    {
        srand(time(NULL));  // Seed for random number generator
        mazewidth = width * 2 + 1;// = set the actual width of the maze;
        mazeheight = height * 2 + 1;// = set the actual height of the maze;
        //resize the maze vector and fill it with '#'
        maze.resize(mazeheight * mazewidth, '#');
    }

    // Move your Prim's Algorithm here
    void primMaze() 
    {
    //Remove the vector<char> maze line at the start.
    //	That is now done in setMaze.
    vector<int> frontier; // Frontier will store 1D indices of frontier walls

    srand(time(0));  // Seed for random number generator

    // Start at a random point on the grid (must be an odd coordinate)
    int startRow = (rand() % height) * 2 + 1;
    int startCol = (rand() % width) * 2 + 1;

    maze[indexFrom2D(startRow, startCol)] = ' ';  // Mark starting point as an open space

    //Your code here
    //Add Initial Cords?
    //frontier.push_back(indexFrom2D(startRow, startCol));

    // Add neighboring cells to the frontier list (in 1D index form)
    // Use four seperate if statements to check if the location 2 spaces away is valid
    // in the NORTH, SOUTH, EAST, and WEST directions.
    // If a location is valid, push it's location index onto the frontier vector.
    if(isValid(startRow + 2, startCol)) {
    frontier.push_back(indexFrom2D(startRow + 2, startCol));
    }
    if(isValid(startRow - 2, startCol)) {
        frontier.push_back(indexFrom2D(startRow - 2, startCol));
    }
    if(isValid(startRow, startCol + 2)) {
        frontier.push_back(indexFrom2D(startRow, startCol + 2));
    }
    if(isValid(startRow, startCol - 2)) {
        frontier.push_back(indexFrom2D(startRow, startCol - 2));
    }

    // Prim's algorithm loop
    // Begin a while loop that will end when the frontier is empty
    while (!frontier.empty()) 
    {
        int randIndex = rand() % frontier.size(); // = Pick a random frontier cell
        int frontierCell = frontier[randIndex]; // = Store the index found there 
        frontier.erase(frontier.begin() + randIndex);  // Remove from frontier list

        int frontierRow = indexTo2DRow(frontierCell); // = Convert the frontier cell (1D index) to 2D row
        int frontierCol = indexTo2DCol(frontierCell); // = Convert the frontier cell (1D index) to 2D col

        vector<int> mazeNeighbors;  //Make an empty list to store potential new neighbors.
        // Check neighbors that are part of the maze (2-cell jump away)
        //   Use 4 seperate if statements to ask if a location 2 spaces away from
        //   frontierCell in each direction, N,S,E,W, isValid AND is open (' ')
        //   If it is both, push its index onto the the mazeNeighbors vector.
        if (isValid(frontierRow + 2, frontierCol) && maze[indexFrom2D(frontierRow + 2, frontierCol)] == ' ') {
            mazeNeighbors.push_back(indexFrom2D(frontierRow + 2, frontierCol));
        }
        if (isValid(frontierRow - 2, frontierCol) && maze[indexFrom2D(frontierRow - 2, frontierCol)] == ' ') {
            mazeNeighbors.push_back(indexFrom2D(frontierRow - 2, frontierCol));
        }
        if (isValid(frontierRow, frontierCol + 2) && maze[indexFrom2D(frontierRow, frontierCol + 2)] == ' ') {
            mazeNeighbors.push_back(indexFrom2D(frontierRow, frontierCol + 2));
        }
        if (isValid(frontierRow, frontierCol - 2) && maze[indexFrom2D(frontierRow, frontierCol - 2)] == ' ') {
            mazeNeighbors.push_back(indexFrom2D(frontierRow, frontierCol - 2));
        }

        // If there are valid neighbors in the maze, carve a path between the frontier and ONE of its neighbors
        if (!mazeNeighbors.empty()) 
        {
            int neighbor = mazeNeighbors[rand() % mazeNeighbors.size()];  // Random neighbor
            int neighborRow = indexTo2DRow(neighbor); // = Convert neighbor (1D index) to 2D row
            int neighborCol = indexTo2DCol(neighbor);// = Convert neighbor (1D index) to 2D col

            // Carve the path (remove the wall between them)
            //   Use (frontierRow + neighborRow) / 2 to find the row between them.
            //   Use (frontierCol + neighborcol) / 2 to find the col between them.
            //   Set the cell between to ' '
            //   Set the frontierCell to ' '
            int findRow = (frontierRow + neighborRow) / 2;
            int findCol = (frontierCol + neighborCol) / 2;
            maze[indexFrom2D(findRow, findCol)] = ' ';
            maze[frontierCell] = ' ';


            // Add new frontier cells (neighbors of the current frontier cell)
            //   Use 4 seperate if statements to ask if a location 2 spaces away from
            //   frontierCell in each direction, N,S,E,W, isValid AND is closed ('#')
            //   If it is both, push its index onto the the frontier vector.
            if (isValid(frontierRow + 2, frontierCol) && maze[indexFrom2D(frontierRow + 2, frontierCol)] == '#') {
               frontier.push_back(indexFrom2D(frontierRow + 2, frontierCol));
            }
            if (isValid(frontierRow - 2, frontierCol) && maze[indexFrom2D(frontierRow - 2, frontierCol)] == '#') {
                frontier.push_back(indexFrom2D(frontierRow - 2, frontierCol));
            }
            if (isValid(frontierRow, frontierCol + 2) && maze[indexFrom2D(frontierRow, frontierCol + 2)] == '#') {
                frontier.push_back(indexFrom2D(frontierRow, frontierCol + 2));
            }
            if (isValid(frontierRow, frontierCol - 2) && maze[indexFrom2D(frontierRow, frontierCol - 2)] == '#') {
                frontier.push_back(indexFrom2D(frontierRow, frontierCol - 2));
            }
        }
    }
    }

public:
	//Make 3 constructors.
	//In each one set the width and height and call setMaze()
    
	//Default Constructor
	PrimMaze()
    {
        width = 0;
        height = 0;
        setMaze();
    }
	
	//Overload Constructor (custom width and height)
    PrimMaze(int w, int h)
    {
        width = w;
        height = h;
        setMaze();

    }
	
	//Overload constructor (custom maze for testing)
	//After calling setMaze(), make maze = layout
    PrimMaze(int w, int h, std::vector<char>& layout)
    {
        width = w;
        height = h;
        maze = layout;
        setMaze();

    }

	//Public function to create a maze.
	//Make this function call primMaze()
    void generateMaze()
    {
        primMaze();
    }

	//Move your index converters and valid check to here
    // 1D to 2D conversion (returns row based on 1D index)
    int indexTo2DRow(int index) {return index / mazewidth;}

    // 1D to 2D conversion (returns col based on 1D index)
    int indexTo2DCol(int index) {return index % mazewidth;}

    // 2D to 1D conversion (converts row and column into 1D index)
    int indexFrom2D(int row, int col) { return row * mazewidth + col;}

    // Check if a cell is within bounds
    bool isValid(int row, int col) {
        return row >= 0 && row < mazeheight && col >= 0 && col < mazewidth;
    }

	//Create getters for mazeheight and mazewidth
    int getMazeHeight(){
        return mazeheight;
    }
    int getMazeWidth(){
        return mazewidth;
    }
    
	//Create a getter that returns a reference to maze

    const vector<char>& getMaze(){
        return maze;
    }

	//Function to find valid starting 
	//locations for player and enemy
    int getEmptyCell()
    {
        while(true)
        {
            int row = rand() % mazeheight;
            int col = rand() % mazewidth;
            int index = indexFrom2D(row,col);
            if(maze.at(index) == ' ') return index; 
        }
    }

    //Move your draw maze code here
	//Update it to accept indexes p and e
	//When printing the indexes p and e, do not print 
	//what is in the maze vector.
	//Instead print 'P' or 'E'

    //Need to Add: When E = P, Cout  << !
    //Currently just outputs P and ends
    void drawMaze(int p, int e)
    {
        for (int i = 0; i < mazeheight; ++i)
        {
            for (int j = 0; j < mazewidth; ++j)
            {
                if (indexFrom2D(i, j) == p)
                {
                    cout << 'P';
                }
                else if (indexFrom2D(i, j) == e)
                {
                    cout << 'E';
                }
                else
                {
                    cout << maze[indexFrom2D(i, j)];
                }
            }
            cout << endl;
        }
    }
};