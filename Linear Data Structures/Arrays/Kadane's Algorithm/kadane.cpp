// Kadane's Algorithm
#include <iostream>
#include <vector>
#include <climits>
using namespace std;



int kadaneAlgo(vector<int> &vec,int n){
    int currentSum=0;
    int maxSum=INT_MIN;  
    for (int i = 0; i < n; i++)
  { currentSum+=vec[i];
    maxSum=max(currentSum,maxSum);
    if(currentSum<0){
        currentSum=0;
    }
  }
  return maxSum;
      

}



int main(){
    vector<int> arr={1,-2,-3,4};
    // vector<int> arr1={0, 1, -2, -3, 4, 0, -1, -2};
    int value=kadaneAlgo(arr,4);
    cout<<value;
    return 0;
}