#include <iostream>
#include <vector>
#include <cassert>
#include "Enemy.h"
#include "PrimMaze.h"

// Test function to verify enemy movement in the maze
void testEnemyMovement() {
    // 5x5 predefined maze layout (' ' for open path, '#' for walls)
    std::vector<char> layout = {
        '#', '#', '#', '#', '#',
        '#', ' ', ' ', ' ', '#',
        '#', '#', ' ', '#', '#',
        '#', ' ', ' ', ' ', '#',
        '#', '#', '#', '#', '#'
    };

    PrimMaze maze(2, 2, layout);
    Enemy enemy(6, maze);  // Start at (1,1) in the 5x5 grid, 1D index 6
    
    enemy.updateTarget(18);  // Set target at (3,3), 1D index 18
    
    enemy.updatePathing(maze.getMaze());  // Calculate path to target
    // Check if the shortest path is calculated correctly
    
    maze.drawMaze(18,6);

    assert(enemy.distanceToTarget == 4);  // Expected path length to target

    // Simulate movement step-by-step
    std::vector<int> expectedSteps = {7, 12, 17, 18};  // Expected sequence of steps to the target
    for (int expectedLocation : expectedSteps) 
    {
        enemy.takeStep();  // Move the enemy
        if(enemy.currentLocation != expectedLocation) cout << enemy.currentLocation << " " << expectedLocation << endl;
        assert(enemy.currentLocation == expectedLocation);
        maze.drawMaze(18,enemy.currentLocation);
        cout << endl;
    }

    std::cout << "Enemy movement test passed!" << std::endl;
}

int main() {
    testEnemyMovement();
    return 0;
}
