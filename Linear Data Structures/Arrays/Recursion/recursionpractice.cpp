#include <iostream>
#include <vector>

using namespace std;

// Changed return type to void because we are using pass-by-reference (&ans)
void sequences(int n, int k, vector<int> &current, vector<vector<int>> &ans,int index){
    // Base Case
    if(current.size() == k){
        ans.push_back(current);
        return; // Now this is allowed because the function is void
    }

    for(int i = index; i <= n; i++){
        current.push_back(i);

        sequences(n, k, current, ans,index);

        // Backtrack
        current.pop_back();
    }
}

int main(){
    vector<int> current;
    vector<vector<int>> ans;
    
    // Just call it; no need to assign (ans = ...) because it's void
    sequences(1, 3, current, ans,0);

    for (const auto& row : ans) {
        cout << "[ ";
        for (int val : row) {
            cout << val << " ";
        }
        cout << "]" << endl;
    }

    cout << "Total sequences: " << ans.size() << endl;
    return 0;
}