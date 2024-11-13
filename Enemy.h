#include "PrimMaze.h"
#include "SLLPriorityQueue_stub.h"

class Enemy 
{
public:
    int currentLocation;   	// The enemy's current position in the maze (1D index)
    int target;				// The location where the enemy wishes to go (1D index)
	int distanceToTarget;  	// The shortest number of steps to the target
    int nextLocation;      	// The next cell the enemy should move to (1D index) 
	PrimMaze maze;

    // Constructor to initialize the enemy's starting position
    Enemy(int start, PrimMaze m)
	{
		currentLocation = start;
		distanceToTarget = INT_MAX;
		nextLocation = -1;
		maze = m;
	}
	
	void updateTarget(int location)
	{
		target = location;
	}
	
	void updatePathing(const vector<char>& grid)
	{
		calculateShortestPath(grid);
	}
	
	void takeStep()
	{
		if(nextLocation >= 0){
			currentLocation = nextLocation;
			//Required to update pathing before steping again.
			updatePathing(maze.getMaze());
		}
	}
	
private:

    // Dijkstra's algorithm to calculate the shortest path to the player
    void calculateShortestPath(const vector<char>& grid) 
	{
		// Initialize distance vector to store the shortest distance to each cell (set to infinity initially)
		vector<int> dist(maze.getMazeWidth() * maze.getMazeHeight(), INT_MAX);
		
		// Initialize a vector to store the previous cell that led to each current cell
		vector<int> path(maze.getMazeWidth() * maze.getMazeHeight(), -1); // -1 means no previous cel

		// Create the singly linked list priority queue
		SLLPriorityQueue pq;

		// Set the distance to the target index as 0
		dist[currentLocation] = 0;
		// Enqueue a node with 0 distance and currentLocation index into the priority queue
		pq.enqueue(0, currentLocation);

		// While the priority queue is not empty, process the next node
		while (!pq.isEmpty()) 
		{
			Node currentNode = pq.dequeue();// = Dequeue the cell with the smallest distance (highest priority)
			int current = currentNode.cellIndex; // = get the index from the current node


			// If we've reached the goal, return the distance
			if (current == target) 
			{
				break;
			}

			// Convert the current 1D index to 2D coordinates
			int currentRow = maze.indexTo2DRow(current);// = 
			int currentCol = maze.indexTo2DCol(current);// = 

			// Define the four possible directions (N, S, E, W) as 2D row/col changes
			int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

			// Check each neighboring cell
			for (int i = 0; i < 4; i++) 
			{
				int neighborRow = currentRow + directions[i][0];
				int neighborCol = currentCol + directions[i][1];

				// Check if the neighboring cell is within bounds.
				if (maze.isValid(neighborRow, neighborCol)) 
				{
					int neighborIndex = maze.indexFrom2D(neighborRow, neighborCol); // = convert 2D to index

					// Check if the neighboring cell is not a wall.
					if (!(grid[neighborIndex] == '#'))
					{ 
						//calculate the new distance to neighbor
						int newDist = dist[current] + 1;// = the neighbor is 1 more step from current 

						// If the new distance is shorter than the current known distance to neighbor
						if (newDist < dist[neighborIndex])
						{
							// Update the distance in the neighbor's index of the distance vector
							dist[neighborIndex] = newDist;

							// Update the location that led to the neighbor in the neighbor's index of the path vector
							path[neighborIndex] = current;

							// Add the neighbor to the queue with updated distance
							pq.enqueue(newDist, neighborIndex);

						}
					}
				}
			}
		}	
		
		// If the target is unreachable (The index in distance will be INT_MAX)
		if (dist[target] == INT_MAX) 
		{
			//Set distanceToTarget to INT_MAX 
			distanceToTarget = INT_MAX ;
			//Set nextLocation to -1;
			nextLocation = -1;
		}
		else
		{
			distanceToTarget = dist[target];// = Set the shortest distance to the target

			// Backtrack from the target's location to find the next step.
			int currentStep = target;
			// Loop while the currentStep in path is not the enemies location
			while (path[currentStep] != currentLocation && path[currentStep] != -1) 
			{
				currentStep = path[currentStep]; // = Make the currentStep the index stored in path
			}
			nextLocation = currentStep; // = Set the next location for the enemy to move toward
		}
	}
};