// N Queens Problem
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(vector<string> &board, int row , int col , int n){
        // Horizontally Check
        for(int j = 0; j < n; j++){
            if(board[row][j] == 'Q'){
                return false;
            }
        }
        // Vertically Check
        for(int i = 0; i < n; i++){
            if(board[i][col] == 'Q'){
                return false;
            }
        }
        // Left Diagonal Check
        for(int i = row, j = col; i >= 0 && j >= 0; i--,j--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        // Right Diagonal Check
        for(int i = row, j = col; i >= 0 && j < n; i--,j++){
            if(board[i][j] == 'Q'){
                return false;
            }
        }

        return true;
    }
    void nQueens(vector<string> &board, int row, int n, vector<vector<string>> &ans){
        // Base Case
        if(row == n){
            ans.push_back({board});
            return;
        }

        // Main Case
        for(int i = 0; i < n; i++){
            if(isValid(board , row , i , n)){
                board[row][i] = 'Q';
                // Move to next Row
                nQueens(board , row + 1, n , ans);
                // BackTrack
                board[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        vector<vector<string>> ans;
        nQueens(board , 0 , n , ans);
        return ans;
    }
};