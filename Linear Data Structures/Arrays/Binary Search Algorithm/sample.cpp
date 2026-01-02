// Aggressive cows problem
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isValue(vector<int> &stalls,int k,int mid){
    int cow=1;
    int lastPosition=stalls[0];

    for(int i=0;i<stalls.size();i++){
        if(stalls[i]-lastPosition>=mid){
            cow++;
            if(cow==k){
                return true;
            }
            lastPosition=stalls[i];
        }
    }

    return false;

}

int arrangeCows(vector<int> &stalls,int n,int k){
    int start=0;
    sort(stalls.begin(),stalls.end());
    int maximum=INT8_MIN;
    for(int i=0;i<n;i++){
        if(stalls[i]>maximum){
            maximum=stalls[i];
        }
    }
    int ans=-1;
    int end = maximum;

    while(start<=end){
        int mid=start+(end-start)/2;
        if(isValue(stalls,k,mid)){
           ans=mid;
           start=mid+1;
        }
        else{
            end=mid-1;
        }
    }

    return ans;
}