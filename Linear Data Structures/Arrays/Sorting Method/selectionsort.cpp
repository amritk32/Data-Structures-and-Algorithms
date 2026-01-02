// Selection Sort Algorithm
#include <iostream>
#include <vector>

using namespace std;

void sortArray(vector<int> &arr){
    int n = arr.size();
    for(int i=0;i<n;i++){
        int minIndex=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIndex]){
                minIndex=j;

            }
        }
        swap(arr[minIndex],arr[i]);
    }
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};
    sortArray(arr);
    int n = arr.size();
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}

// Time and Space Complexity
/*
Time - O(n^2)
Space - O(1)
Best Case - O(n^2)
Worst Case - O(n^2)

*/
