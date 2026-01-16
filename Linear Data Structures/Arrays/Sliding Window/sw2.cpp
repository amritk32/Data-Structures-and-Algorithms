#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Maximum Points u can obtain from either ends of size k
int getMaxSum(vector<int> &arr, int k)
{

    int maxSum = INT_MIN;
    int currentSum = 0;
    int rightsum = 0;
    int n = arr.size();

    // Sum of first K elements
    for (int left = 0; left < k; left++)
    {
        currentSum += arr[left];
        maxSum = currentSum;
    }

    // Slide the window
    int right = n - 1;
    for (int i = k - 1; i >= 0; i--)
    {
        currentSum -= arr[i];
        rightsum += arr[right];
        right--;
        maxSum = max(maxSum, currentSum + rightsum);
    }

    return maxSum;
}

// Longest subarray without repeating characters
int getLongestSubvector(vector<int> &arr)
{
    vector<int> freq(101, 0);
    int currentLength = 0;
    int maxLength = INT_MIN;
    int start = 0;

    for (int i = 0; i < arr.size(); i++)
    {

        freq[arr[i]]++;

        while (freq[arr[i]] > 1)
        {

            freq[arr[start]]--;
            start++;
        }
        currentLength = i - start + 1;
        maxLength = max(currentLength, maxLength);
    }
    return maxLength;
}
// K frequency Subarray
int getMaxLength(vector<int> &arr, int k)
{
    int maxLength = INT_MIN;
    vector<int> freq(101, 0);
    int start = 0;
    int currentLength = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;

        while (freq[arr[i]] > k)
        {
            freq[arr[start]]--;
            start++;
        }
        currentLength = i - start + 1;
        maxLength = max(currentLength, maxLength);
    }

    return maxLength;
}

// Golden rule for any sliding window

/*for (int i = 0; i < n; i++) {
    // STEP 1: ADD
    // Add arr[i] to your sum or frequency map
    freq[arr[i]]++;

    // STEP 2: VALIDATE (The While Loop)
    // "While the window is ILLEGAL..."
    while (/* condition that makes window bad */
// freq[arr[start]]--;
// start++;
// }

// STEP 3: UPDATE RESULT
// The window is now officially VALID.
// This is the ONLY safe place to calculate length or max.

// Max Consecutive Ones Leetcode(1004)
int getMaxOnes(vector<int> &arr, int k)
{
    int start = 0;
    int currentLength = 0;
    int maxLength = INT_MIN;
    int zeroCount = 0;
    int n = arr.size();

    for (int end = 0; end < n; end++)
    {
        if (arr[end] == 0)
        {
            zeroCount++;
        }

        while (zeroCount > k)
        {
            if (arr[start] == 0)
            {
                zeroCount--;
            }

            start++;
        }

        currentLength = end - start + 1;
        maxLength = max(currentLength, maxLength);
    }
    return maxLength;
}

int getMax(vector<int> &arr){
    int start = 0;
    int currentLength = 0;
    int maxLength = INT_MIN;
    int n = arr.size();
    vector<int> freq(101,0);

    for(int i = 0; i < n; i++){
        freq[arr[i]]++;

        while(freq[arr[i]] > 1){
            freq[arr[start]]--;
            start++;
        }

        currentLength = i - start + 1;
        maxLength = max(currentLength,maxLength);
    }
    return maxLength;
}

// Smallest Subarray with greatest sum
/*For questions where minlength is asked update the length inside the while loop itself
 */
int getMinLength(vector<int> &arr, int target)
{
    int start = 0;
    int currentSum = 0;
    int currentLength = 0;
    int minLength = INT_MAX;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        currentSum += arr[i];

        while (currentSum >= target)
        {
            currentLength = i - start + 1;
            minLength = min(currentLength, minLength);
            currentSum -= arr[start];
            start++;
        }
    }
    return minLength;
}

// Sample problem
int helper(vector<int> &arr, int target)
{
    int start = 0;
    int currentLength = 0;
    int minLength = INT_MAX;
    int counter = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            counter++;
        }

        while (counter >= target)
        {
            currentLength = i - start + 1;
            minLength = min(currentLength, minLength);
            if(arr[start] == 1){
                counter--;
            }
            start++;
            
        }
    }
    return minLength;
}

// Smallest Subarray with all targets
int getMinSubarray(vector<int> &arr , vector<int> &target){
    int start = 0;
    int currentLength = 0;
    int minLength = INT_MAX;
    int n = arr.size();
    int m = target.size();


}

int main()
{

    // vector<int> arr = {6, 2, 3, 4, 7, 2, 1, 7, 1};
    // int k = 4;
    // cout << "The max sum is " << getMaxSum(arr, k) << endl;

    // vector<int> arr1 = {1, 2, 2, 3, 4, 5, 5, 6};
    // cout << "Max Length of subvector is " << getLongestSubvector(arr1) << endl;

    // vector<int> arr2 = {1, 2, 1, 2, 1, 2, 1};
    // cout << "Max Length of k frequency subvector is " << getMaxLength(arr2, 2) << endl;

    // vector<int> arr3 = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    // cout << "Max Length of sub vector with continuous ones is " << getMaxOnes(arr3, 2) << endl;

    // vector<int> arr4 = {2, 3, 1, 2, 4, 3};
    // int k1 = 7;
    // cout << "Min Length of Subarray with sum = 7 is " << getMinLength(arr4, k1) << endl;

    vector<int> arr5 = {1, 0, 1, 1, 0, 0, 1, 1};
    cout << "Min Length of net is " << helper(arr5, 3) << endl;

    vector<int> arr6 = {1,2,3,1,2,3,4};
    cout<<getMax(arr6);
    return 0;
}