/*
*  This program find the shortest distance for the robot to  move across a " treasure map",
*  from the robot's starting position to the location of the treasure.
*  Kaleab Gudissa
*  ktg7@uw.edu
*  04/25/2024
*/

#ifndef GREEDY_ROBOT_H
#define GREEDY_ROBOT_H

#include <string>
#include <vector>
using namespace std;

class GreedyRobot {
public:
    // Constructor to initialize the GreedyRobot object
    GreedyRobot(int max_distance, int robot_x, int robot_y, int treasure_x, int treasure_y);

    // Function to find all possible paths from robot to treasure
    void findPaths();

    // Function to get the found paths
    vector<string> getPaths() const;

    // Function to get the number of found paths
    int getNumberOfPaths() const;

private:
    // Recursive function to find all possible paths from robot to treasure
    void recursiveFindPaths(int xr, int yr, int xt, int yt, string path, int countN, int countS, int countE, int countW);

    
    int max_distance;
    int robot_x;
    int robot_y;
    int treasure_x;
    int treasure_y;
    vector<string> paths;
    // total paths
    int num_paths;
};

#endif

