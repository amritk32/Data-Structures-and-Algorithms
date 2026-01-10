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
    
    for(int i = 0; i < arr.size(); i++){

        // 1) Inclusion
        swap(arr[index] , arr[i]);
        // Move to next index
        getPermutation(arr , nums , index+1 , result);
        // BackTracking
        swap(arr[index] , arr[i]);
    }
    

}
