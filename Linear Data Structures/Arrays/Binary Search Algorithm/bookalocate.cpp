// Book Allocation Problem(MAANG)
#include <iostream>
using namespace std;

bool isValid(int arr[],int n,int m,int maxAllowedPages)
{
    int students=1;
    int pages=0;
    if(students>m){return false;}
    for(int i=0;i<n;i++){
        if(arr[i]>maxAllowedPages){return false;}
        if(pages+arr[i]<=maxAllowedPages){
            pages+=arr[i];
        }
        else{
            students++;
            pages=arr[i];
        }
    }
    return students>m ? false:true;
}

int allocateBooks(int arr[],int n,int m){
    int start=0;
    int ans=-1;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int end=sum;

    while(start<=end){
        int mid=start+(end-start)/2;
        if(isValid(arr,n,m,mid)){
            ans=mid;
            end=mid-1;
        }
        else{
            start=mid+1;
        }

    }
    return ans;
}

int main(){
    int arr[5]={7,2,5,10,8};
    int ans=allocateBooks(arr,5,2);
    cout<<ans;
}