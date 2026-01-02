#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxAverage(vector<int> &arr , int k){
    int currentSum = 0;
    int maxSum = 0;

    for(int i = 0; (i < arr.size()) && (i < i + k); i++){
        currentSum += arr[i];
        maxSum = max(currentSum , maxSum);

    }

  return maxSum/k;
    
}

int main(){
    vector<int> arr1 ={1,12,-5,-6,50,3};
    int value = maxAverage(arr1 , 4);
    cout << value;
    return 0;
}