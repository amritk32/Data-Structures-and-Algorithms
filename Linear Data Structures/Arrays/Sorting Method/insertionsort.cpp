// Insertion Sort
#include <iostream>
#include <vector>

using namespace std;

void sortArray(vector<int> &arr){
    int n=arr.size();
   
    for(int i=1;i<n;i++){
        int temp=arr[i];
         int j=i-1;
        for(;j>=0;j--){
            if(arr[j]>temp){
              arr[j+1]=arr[j];
            }
            else{
                break;
            }
            
        }
        arr[j+1]=temp;
    }
}

int main(){

    vector<int> arr={7,6,5,4,3,2,1};
    sortArray(arr);

    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    
    }
    return 0;
}

// Time and Space Complexity
// Time - O(n^2)
// Space - O(1)
// Best Case - O(n)
// Worst Case - O(n^2)