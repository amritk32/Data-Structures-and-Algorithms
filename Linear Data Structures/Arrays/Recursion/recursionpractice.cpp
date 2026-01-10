#include <iostream>
#include <vector>

using namespace std;

void combinations(int n , int index , vector<int> &current , vector<vector<int>> &ans , int k){
    // int n = arr.size();
    // Base Case
    if(current.size() == k){
        ans.push_back(current); // Found a Valid answer pushback
        return;                 // Returns to function call stack
    }

    // Recursive Case
    for(int i = index; i <= n; i++){
        // Fill first position
        current.push_back(i);
        // Move to next index
        combinations(n,index+1,current,ans,k);
        // Backtrack
        current.pop_back();

    }



}