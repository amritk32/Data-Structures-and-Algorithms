#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution{
public:
    bool isValidVector(vector<int> &have , vector<int> &need){
        for(int i = 0; i < need.size(); i++){
            if(have[i] < need[i]) return false;
        }
        return true;
    }

    vector<int> minWindowVector(vector<int> &main , vector<int> &target){
        vector<int> target_freq(1001 , 0);  //Container to store target frequencies
        vector<int> main_freq(1001 , 0);    //Container to store main frequencies
        vector<int> results;                //Container to store the results

        int k = target.size();
        int n = main.size();
        int minLen = INT_MAX;
        int bestStart = -1;

        // Stored Target Frequencies
        for(int i = 0; i < k; i++){
            target_freq[target[i]]++;
        }

        // Sliding Window Logic 
        int start = 0;
        for(int j = 0; j < n; j++){
            main_freq[main[j]]++;

            while(isValidVector(main_freq , target_freq)){
                if(j - start + 1 < minLen){
                    minLen = j - start + 1;
                    bestStart = start;
                }

                main_freq[main[start]]--;
                start++;
            }
        }

        if(bestStart == -1) return {};
        for(int i = bestStart; i < bestStart + minLen; i++){
            results.push_back(main[i]);
        }
        return results;
    }


};
