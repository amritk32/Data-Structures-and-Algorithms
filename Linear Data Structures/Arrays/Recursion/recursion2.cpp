// Recursion with vectors
#include <iostream>
#include <vector>

using namespace std;

// Sorted array or not using recursion
bool isSortedVector(int *arr, int n)
{
    // Edge Case
    if (n == 0 || n == 1)
    {
        return true;
    }

    // Base Case
    if (arr[0] > arr[1])
    {
        return false;
    }

    // Recursive Case
    bool ans = isSortedVector(arr + 1, n - 1);
    return ans;
}

// Sum of the elements of the vector using recursion

int sumElements(int *arr, int size)
{
    // Base Cases
    if (size == 0)
    {
        return 0;
    }
    if (size == 1)
    {
        return arr[0];
    }
    else
    {
        int sum = arr[0];
        int rem = sumElements(arr + 1, size - 1);
        return (sum + rem);
    }
}

// Linear Search using recursion

bool linearSearch(int *arr, int size, int target)
{
    if (size == 0)
    {
        return false;
    }
    if (arr[0] == target)
    {
        return true;
    }
    bool rem = linearSearch(arr + 1, size - 1, target);
    return rem;
}

// Recursive Binary Search

int recursiveBinarySearch(int arr[], int start, int end, int target)
{
    if (start > end)
        return 0;
    int mid = start + (end - start) / 2;

    if (arr[mid] == target)
        return 1;
    if (arr[mid] < target)
    {
        return recursiveBinarySearch(arr, mid + 1, end, target);
    }
    else
    {
        return recursiveBinarySearch(arr, start, mid - 1, target);
    }
}

// Permutations with recursive backtracking

void getPermutation(vector<int> &arr, vector<int> &nums , int index , vector<vector<int>> &result)
{
    // Base Case
    if(index == arr.size()){
        result.push_back(nums);
        return;
    }

    // Recursive Case
    
    for(int i = index; i < arr.size(); i++){

        // 1) Inclusion
        swap(arr[index] , arr[i]);
        // Move to next index
        getPermutation(arr , nums , index+1 , result);
        // BackTracking
        swap(arr[index] , arr[i]);
    }
    

}

class Solution {
private:
    void helper(string &tiles, vector<bool> &visited, int &count, string &current) {
       if(!current.empty()){
        count++;
       }
        unordered_set<char> seen;

        for (int i = 0; i < tiles.size(); i++) {
            
            if (visited[i] || seen.count(tiles[i])) {
                continue;
            }

            // Mark as used
            seen.insert(tiles[i]);
            visited[i] = true;
            current.push_back(tiles[i]);
          

            // Recurse to fill the next position
            helper(tiles, visited, count, current);

            // Backtrack: Reset for the next iteration of the loop
            current.pop_back();
            visited[i] = false;
        }
    }

public:
    int numTilePossibilities(string tiles) {
        int count = 0;
        vector<bool> visited(tiles.size(), false);
        string current = "";
        
        helper(tiles, visited, count, current);
        
        return count;
    }
};

void permute(vector<int> &arr, vector<vector<int>> &ans, vector<int> &current, vector<bool> &used){
    // Base case
    if(current.size() == arr.size()){
        ans.push_back(current);
        return;
    }

    for(int i = 0; i < arr.size(); i++){
        if(!used[i]){

            // Inclusion
            current.push_back(arr[i]);
            used[i] = true;

            // Recursive call
            permute(arr, ans, current, used);

            // Exclusion
            current.pop_back();
            used[i] = false;

            
        }
    }


}

// use for loop when multiple parameters compete for the same place
// Use inclusion exclusion principle without for loop when vector does not have duplicates
// Use inclusion exclusion principle with for loop when vector contains duplicates then manual sorting is required(mergesort)
// To use exactly each number once in a combination question use looping method and in next recursive call for i + 1 instead of index + 1 and start
// i from index in the for loop

// Use proper method for permutations depending upon the question

// Use set to determine duplicates when sorting + skipping is too complex 

// Use sorting and defining duplicates when using set increases space complexity

