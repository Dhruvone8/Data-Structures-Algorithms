#include <iostream>
#include <vector>
using namespace std;

void all_paths(string p, vector<vector<bool>> &maze, int rows, int cols, vector<vector<int>> &path, int step)
{
    if (rows == maze.size() - 1 && cols == maze[0].size() - 1)
    {
        path[rows][cols] = step;
        for (int i = 0; i < path.size(); i++)
        {
            cout << "{";
            for (int j = 0; j < path[0].size(); j++)
            {
                cout << path[i][j];
                if (j != path[0].size() - 1)
                {
                    cout << ", ";
                }
            }
            cout << "}" << endl;
        }

        cout << p << endl;

        cout << endl;

        return;
    }

    if (maze[rows][cols] == false)
    {
        return;
    }

    // Mark the cell you are visiting as false to avoid travsering same path again
    maze[rows][cols] = false;

    path[rows][cols] = step;

    if (rows < maze.size() - 1)
    {
        all_paths(p + "D", maze, rows + 1, cols, path, step + 1);
    }

    if (cols < maze[0].size() - 1)
    {
        all_paths(p + "R", maze, rows, cols + 1, path, step + 1);
    }

    if (rows > 0)
    {
        all_paths(p + "U", maze, rows - 1, cols, path, step + 1);
    }

    if (cols > 0)
    {
        all_paths(p + "L", maze, rows, cols - 1, path, step + 1);
    }

    // Revert the changes while going back to previous recurion calls
    maze[rows][cols] = true;

    path[rows][cols] = 0;
}

int main()
{
    vector<vector<bool>> maze = {
        {true, true, true},
        {true, true, true},
        {true, true, true}};

    vector<vector<int>> path(maze.size(), vector<int>(maze[0].size()));

    all_paths("", maze, 0, 0, path, 1);
}