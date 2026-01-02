// Container with most water
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxWater(vector<int> &arr){
    int maxWater=INT_MIN;       
    int currentArea=0;         
    int start=0;               
    int n=arr.size();
    int end=n-1;

    while(start<end){
        int width=end-start;
        int height=min(arr[start],arr[end]);
        currentArea=width*height;
        maxWater=max(currentArea,maxWater);
        
        
        if(arr[start]<arr[end]){
            start++;
        }
        else{
            end--;
        }
        
        

    }
    return maxWater;

}

int main(){
    vector<int> arr={1,100,1,1,1,100,1};
    int value=maxWater(arr);
    cout<<value;
    return 0;
}