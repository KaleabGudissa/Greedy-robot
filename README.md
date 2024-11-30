# Greedy Robot

### Author: Kaleab Gudissa  
**Email**: ktg7@uw.edu  
**Date**: April 25, 2024  

---

## Project Overview

**Greedy Robot** is a C++ program that calculates all the possible paths a robot can take to reach a treasure on a grid, following specific constraints:
- The robot moves a maximum number of steps in each direction (`max_distance`).
- It starts from a given position (`robot_x`, `robot_y`) and aims to reach a treasure at (`treasure_x`, `treasure_y`).
- The program identifies all valid shortest paths and counts them.

---

## Features

- Recursive backtracking algorithm to find paths.
- Supports edge cases:
  - Robot starting at the treasure.
  - Unreachable treasures due to constraints.
- Clear and user-friendly output of paths and counts.
- Error handling for invalid input.

---

## How to Run

### Prerequisites
- A C++ compiler (e.g., `g++`).
- The program files: `greedy_robot.h`, `greedy_robot.cpp`.

### Compile
```bash
g++ -o greedy_robot greedy_robot.cpp
