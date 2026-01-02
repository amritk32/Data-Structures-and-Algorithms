#include <iostream>
#include <climits>

using namespace std;

void printSum(int arr[][3] , int row , int col){
    for(int i = 0; i < row; i++){
        int sum = 0;
        for(int j = 0; j < col; j++){
            sum += arr[i][j];
        }
        cout << "Sum of Row " << i+1 <<" is " << sum <<endl;
    }
    
    
}

int largestRowSum(int arr[][3], int row , int col){
    int maxi = INT_MIN;
    int rowNum = -1;
    
    for(int row = 0; row < 5; row++){
        int sum = 0;
        for(int col = 0; col < 3; col++){
            sum += arr[row][col];
        }

        if(sum > maxi){
            maxi = sum;
            rowNum = row;
        }
    }

    cout << "The Maximum Sum Is" << maxi << endl;
    cout << "The Maximum Sum row is" << row << endl;
    return row;


}

int main(){
    int vec[5][3] = {{1,2,3},{1,2,3},{1,2,3},{5,3,7},{9,6,2}};
    largestRowSum(vec,5,3);
    // printSum(vec,5,3);
 
    return 0;
}