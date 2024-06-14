#include "greedy_robot.h"
#include <cmath>
#include <iostream>
using namespace std;

// Constructor to initialize the robot's parameters
GreedyRobot::GreedyRobot(int max_distance, int robot_x, int robot_y, int treasure_x, int treasure_y)
    : max_distance(max_distance), robot_x(robot_x), robot_y(robot_y), treasure_x(treasure_x), treasure_y(treasure_y), num_paths(0) {}

// Recursive function to find all possible paths from robot's position to the treasure
void GreedyRobot::recursiveFindPaths(int xr, int yr, int xt, int yt, string path, int countN, int countS, int countE, int countW) {
    // Base case: if robot reaches the treasure
    if (xr == xt && yr == yt) {
        paths.push_back(path);  // Add the path to the list of paths
        num_paths++;  // Increment the number of paths found
        return;
    }

    // Check possible moves and continue recursively
    if (yr < yt && countN < max_distance) {  // Move North
        recursiveFindPaths(xr, yr + 1, xt, yt, path + "N", countN + 1, 0, 0, 0);
    }
    if (yr > yt && countS < max_distance) {  // Move South
        recursiveFindPaths(xr, yr - 1, xt, yt, path + "S", 0, countS + 1, 0, 0);
    }
    if (xr < xt && countE < max_distance ) {  // Move East
        recursiveFindPaths(xr + 1, yr, xt, yt, path + "E", 0, 0, countE + 1, 0);
    }
    if (xr > xt && countW < max_distance) {  // Move West
        recursiveFindPaths(xr - 1, yr, xt, yt, path + "W", 0, 0, 0, countW + 1);
    }
}

// Function to start finding paths
void GreedyRobot::findPaths() {
    recursiveFindPaths(robot_x, robot_y, treasure_x, treasure_y, " ", 0, 0, 0, 0);
}

// Function to get the found paths
vector<string> GreedyRobot::getPaths() const {
    return paths;
}

// Function to get the number of found paths
int GreedyRobot::getNumberOfPaths() const {
    return num_paths;
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the correct number of arguments are provided
    if (argc != 6) {
        cout << "Usage: ./greedy_robot max_distance robot_x robot_y treasure_x treasure_y" << endl;
        return 1;
    }

    // Parse command line arguments
    int max_distance = stoi(argv[1]);
    int robot_x = stoi(argv[2]);
    int robot_y = stoi(argv[3]);
    int treasure_x = stoi(argv[4]);
    int treasure_y = stoi(argv[5]);

    // Create GreedyRobot object
    GreedyRobot robot(max_distance, robot_x, robot_y, treasure_x, treasure_y);

    // Find all unique shortest possible paths
    robot.findPaths();

    // Output the paths
    vector<string> paths = robot.getPaths();
    for (const auto &path : paths) {
        cout << path << endl;
    }

    // Output the number of unique paths
    cout << robot.getNumberOfPaths() << endl;

    return 0;
}
