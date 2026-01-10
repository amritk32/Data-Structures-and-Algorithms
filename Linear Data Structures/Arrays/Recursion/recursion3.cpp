// Permutations with duplicate elements
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void getValidPermutation(vector<int> &arr , vector<vector<int>> &result , int index){
    // Base Case
    if(index == arr.size()){
        result.push_back(arr);
        return;
    }

    unordered_set<int> seen;

    // Recursive Case
    
    for(int i = index; i < arr.size(); i++){
        if(seen.find(arr[i]) != seen.end()){
            continue;
        } 
        seen.insert(arr[i]);

        // 1) Swap 
        swap(arr[index] , arr[i]);
        // 2) move to next element
        getValidPermutation(arr,result,index+1);
        // 3)Backtracking
        swap(arr[index],arr[i]);
    }
}

// Combinations using recursive backtracking approach

void getCombinations(int n , vector<vector<int>> &ans , int index , vector<int> &current , int k){
    // Base Case
    if(current.size() == k){
        ans.push_back(current);
        return ;
    }


    for(int i = index; i <= n; i++){
        // Push into answer
        current.push_back(i);
        // Move to next element
        getCombinations(n,ans,i+1,current,k);
        // Backtrack
        current.pop_back();
    }

}