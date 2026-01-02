#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

int maxProduct(vector<int> &nums){
  int i = 0;
  int currentProduct = 1;
  int maxProduct = INT_MIN;
  int negativeCount = 0;
  while(i < nums.size()){
    // Left to Right iteration
    currentProduct = currentProduct * nums[i];
    maxProduct = max(currentProduct, maxProduct);
    if(nums[i] == 0){
      // Handling Zeroes first
      currentProduct = 1;
      negativeCount = 0;
    }
    else if(nums[i] < 0){
      // Handling Negatives
      negativeCount++;
    }
    else{
      if(negativeCount % 2 == 0){
        maxProduct = max(currentProduct, maxProduct);
      }
      else{
        continue;
      }
    }
    i++;
  }

  currentProduct = 1;
  negativeCount = 0;
  int j = nums.size() - 1; 
  // Right to Left iteration
  while(j >= 0){
    currentProduct = currentProduct * nums[j];
    maxProduct = max(currentProduct , maxProduct);
    if(nums[j] == 0){
      // Handling Zeroes
      currentProduct = 1;
      negativeCount = 0;
    }
    else if(nums[j] < 0){
      // Handling Negatives
      negativeCount++;
    }
    else{
      if(negativeCount % 2 == 0){
        maxProduct = max(currentProduct , maxProduct);
      }
      else{
        continue;
      }
    }
    j--;
  }

  return maxProduct;
}

int main(){
  vector<int> nums = {2,3,-2,4};
  int value = maxProduct(nums);
  cout << value << endl;   // ✅ added newline for clear output
  return 0;
}