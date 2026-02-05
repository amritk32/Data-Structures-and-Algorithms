#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    void getHelp(int n, int index, vector<vector<int>> &ans, vector<int> &current)
    {



        // Base Case
        if (index == current.size())
        {
            ans.push_back(current);

            return;
        }

        // Main Logic of the function
        for (int i = index; i < current.size(); i++)
        {
            swap(current[i], current[index]);
            getHelp(n, index + 1, ans, current);

            // Backtracking step
            swap(current[i], current[index]);
        }
    }

public:
    vector<vector<int>> task_manager(int n)
    {

        int index = 0;
        vector<int> current;

        vector<vector<int>> ans;

        getHelp(n, index, ans, current);

        return ans;
    }
};

