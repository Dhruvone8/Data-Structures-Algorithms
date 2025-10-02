// Traverse all directions

#include <iostream>
#include <vector>
using namespace std;

void all_paths(string p, vector<vector<bool>> &maze, int rows, int cols)
{
    if (rows == maze.size() - 1 && cols == maze[0].size() - 1)
    {
        cout << p << endl;
        return;
    }

    if (maze[rows][cols] == false)
    {
        return;
    }

    // Mark the cell you are visiting as false to avoid travsering same path again
    maze[rows][cols] = false;

    if (rows < maze.size() - 1)
    {
        all_paths(p + "D", maze, rows + 1, cols);
    }

    if (cols < maze[0].size() - 1)
    {
        all_paths(p + "R", maze, rows, cols + 1);
    }

    if (rows > 0)
    {
        all_paths(p + "U", maze, rows - 1, cols);
    }

    if (cols > 0)
    {
        all_paths(p + "L", maze, rows, cols - 1);
    }

    // Revert the changes while going back to previous recursion calls
    maze[rows][cols] = true;
}

int main()
{
    vector<vector<bool>> maze = {
        {true, true, true},
        {true, true, true},
        {true, true, true}};

    all_paths("", maze, 0, 0);
}