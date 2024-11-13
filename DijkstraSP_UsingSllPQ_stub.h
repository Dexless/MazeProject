class Enemy 
{
public:
    int currentLocation;   	// The enemy's current position in the maze (1D index)
    int target;				// The location where the enemy wishes to go (1D index)
	int distanceToTarget;  	// The shortest number of steps to the target
    int nextLocation;      	// The next cell the enemy should move to (1D index)

    // Constructor to initialize the enemy's starting position
    Enemy(int start)
	{
		currentLocation = start;
		distanceToPlayer = INT_MAX;
		nextLocation = -1;
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
		if(nextLocation >= 0) currentLocation = nextLocation;
	}
	
private:
    // Dijkstra's algorithm to calculate the shortest path to the player
    void calculateShortestPath(const vector<char>& grid) 
	{
		// Initialize distance vector to store the shortest distance to each cell (set to infinity initially)
		vector<int> dist(MAZE_WIDTH * MAZE_HEIGHT, INT_MAX);
		
		// Initialize a vector to store the previous cell that led to each current cell
		vector<int> path(MAZE_WIDTH * MAZE_HEIGHT, -1); // -1 means no previous cel

		// Create the singly linked list priority queue
		SLLPriorityQueue pq;

		// Set the distance to the target index as 0
		// Enqueue a node with 0 distance and currentLocation index into the priority queue


		// While the priority queue is not empty, process the next node
		while () 
		{
			Node currentNode;// = Dequeue the cell with the smallest distance (highest priority)
			int current; // = get the index from the current node

			// If we've reached the goal, return the distance
			if (current == target) 
			{
				break;
			}

			// Convert the current 1D index to 2D coordinates
			int currentRow;// = 
			int currentCol;// = 

			// Define the four possible directions (N, S, E, W) as 2D row/col changes
			int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

			// Check each neighboring cell
			for (int i = 0; i < 4; i++) 
			{
				int neighborRow = currentRow + directions[i][0];
				int neighborCol = currentCol + directions[i][1];

				// Check if the neighboring cell is within bounds.
				if () 
				{
					int neighborIndex; // = convert 2D to index
					
					// Check if the neighboring cell is not a wall.
					if ()
					{ 
						//calculate the new distance to neighbor
						int newDist;// = the neighbor is 1 more step from current 

						// If the new distance is shorter than the current known distance to neighbor
						if () 
						{
							// Update the distance in the neighbor's index of the distance vector
							// Update the location that led to the neighbor in the neighbor's index of the path vector
							// Add the neighbor to the queue with updated distance
						}
					}
				}
			}
		}	
		
		// If the target is unreachable (The index in distance will be INT_MAX)
		if () 
		{
			//Set distanceToTarget to INT_MAX 
			//Set nextLocation to -1;
		}
		else
		{
			distanceToTarget;// = Set the shortest distance to the target

			// Backtrack from the target's location to find the next step.
			int currentStep = target;
			// Loop while the currentStep in path is not the enemies location
			while () 
			{
				currentStep; // = Make the currentStep the index stored in path
			}
			nextLocation; // = Set the next location for the enemy to move toward
		}
	}
};
