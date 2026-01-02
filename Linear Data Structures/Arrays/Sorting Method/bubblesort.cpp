// Bubble Sort Algorithm
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void sortArray(vector<int> &arr){
    int n=arr.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

int main(){
    vector<int> arr1={1,3,5,2,9,1,7,0};
    sortArray(arr1);
    for(int i=0;i<arr1.size();i++){
        cout<<arr1[i]<<" ";
    }
    cout<<endl;

    return 0;
}

// Time and Space Complexity
/*
Time - O(n^2)
Space - O(1)
Best Case - O(n) {If array is already sorted}
Worst Case - O(n^2)

*/ 