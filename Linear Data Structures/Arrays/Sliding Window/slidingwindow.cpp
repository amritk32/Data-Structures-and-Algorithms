#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxAverage(vector<int> &arr , int k){
    int n = arr.size();
    int currentSum = 0;

    // sum of first k elements
    for(int i = 0; i < k; i++){
        currentSum += arr[i];
    }
    int maxSum = currentSum;

    // slide the window
    for(int i = k; i < n; i++){
        currentSum += arr[i];        // add new element
        currentSum -= arr[i - k];    // remove old element
        maxSum = max(maxSum , currentSum);
    }

    return maxSum / k;   // integer average
}


int main(){
    vector<int> arr1 ={1,12,-5,-6,50,3};
    int value = maxAverage(arr1 , 4);
    cout << value;   // prints 12 (integer division)
    return 0;
}