// Koko Eating Bananas
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int isValid(vector<int> &arr,int h, int maxAllowed){
  int totalHours=0;
  int n=arr.size();
  for(int i=0;i<n;i++){
    totalHours += ceil(arr[i] / (double)maxAllowed);
 }
  
  return totalHours<=h;
}

int eatBananas(vector<int> &arr,int n,int hours){
    int start=1;
    int sum=0;
    int ans=-1;
    for(int i=0;i<n;i++){sum+=arr[i];}
    int end=sum;
    while (start<=end)
    {
        int mid=start+(end-start)/2;
        if(isValid(arr,hours,mid)){
            ans=mid;
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }

    return ans;
    
}