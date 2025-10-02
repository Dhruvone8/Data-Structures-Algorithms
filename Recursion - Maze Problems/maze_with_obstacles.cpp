// The maze has obstacles, we can't traverse obstacles
// Starting from (0,0)
// Obstacles are marked as false

#include <iostream>
#include <vector>
using namespace std;

void maze_with_obstacles(string p, vector<vector<bool>> &maze, int rows, int cols)
{
    if (rows == maze.size() - 1 && cols == maze[0].size() - 1)
    {
        cout << p << " ";
        return;
    }

    if (maze[rows][cols] == false)
    {
        return;
    }

    if (rows < maze.size() - 1)
    {
        maze_with_obstacles(p + "D", maze, rows + 1, cols);
    }

    if (cols < maze[0].size() - 1)
    {
        maze_with_obstacles(p + 'R', maze, rows, cols + 1);
    }
}

int main()
{
    vector<vector<bool>> maze = {
        {true, true, true},
        {true, false, true},
        {true, true, true}};

    maze_with_obstacles("", maze, 0, 0);
    return 0;
}