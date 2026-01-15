// Rat in a maze problem
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Helper Function
void helper(vector<vector<int>> &board, int row, int col, string path, vector<string> &ans, vector<vector<int>> &visited)
{
    int n = board.size();
    // Base Cases
    if (row < 0 || col < 0)
    {
        return;
    }

    if (row >= n || col >= n)
    {
        return;
    }

    if (board[row][col] == 0)
    {
        return;
    }

    if (row == n - 1 && col == n - 1)
    {
        ans.push_back(path);
        return;
    }

    if (visited[row][col] == 1)
    {
        return;
    }

    // Initialize Visited Matrix
    visited[row][col] = 1;

    // Core Logic of the Function
    helper(board, row - 1, col, path + "U", ans, visited); // Going Upwards
    helper(board, row + 1, col, path + "D", ans, visited); // Going Downwards
    helper(board, row, col - 1, path + "L", ans, visited); // Going Left
    helper(board, row, col + 1, path + "R", ans, visited); // Going Right

    // BackTracking Step
    visited[row][col] = 0;
}

// Returning Function
vector<string> findPath(vector<vector<int>> &mat)
{
    int n = mat.size();

    vector<string> ans;
    if (mat[0][0] == 0 || mat[n - 1][n - 1] == 0)
        return ans;

    vector<vector<int>> visited(n, vector<int>(n, 0));
    string path = "";
    helper(mat, 0, 0, path, ans, visited);

    return ans;
}

// Main Function
int main()
{
    // Example 4x4 Grid
    vector<vector<int>> maze = 
    {{1, 0, 0, 0},
     {1, 1, 0, 1},
     {1, 1, 0, 0},
     {0, 1, 1, 1}};

    vector<string> result = findPath(maze);

    if (result.empty())
    {
        cout << "-1" << endl; // Common output for "No Path Found"
    }
    else
    {
        cout << "All possible paths:" << endl;
        for (const string &p : result)
        {
            cout << p << " ";
        }
        cout << endl;
    }

    return 0;

}
