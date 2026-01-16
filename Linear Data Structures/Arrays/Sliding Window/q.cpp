#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int taskMaster(vector<vector<int>> &tasks){
    int taskCount = 1;
    int n = tasks.size();

    // Sort on basis of start timings
    sort(tasks.begin() , tasks.end(), [](const vector<int> &a, const vector<int> &b){
        return a[1] < b[1];
    });

    int lastTime = tasks[0][1];
    for(int i = 1; i < n; i++){
       

        if(tasks[i][0] >= lastTime){
            taskCount++;
             lastTime = tasks[i][1];
        }
        else{
            continue;
        }
    }

    return taskCount;
}