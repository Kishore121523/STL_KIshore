#include<bits/stdc++.h>

using namespace std;

// You are given a 1-indexed array of distinct integers nums of length n.

// You need to distribute all the elements of nums between two arrays arr1 and arr2 using n operations. In the first operation, append nums[1] to arr1. In the second operation, append nums[2] to arr2. Afterwards, in the ith operation:

// If the last element of arr1 is greater than the last element of arr2, append nums[i] to arr1. Otherwise, append nums[i] to arr2.
// The array result is formed by concatenating the arrays arr1 and arr2. For example, if arr1 == [1,2,3] and arr2 == [4,5,6], then result = [1,2,3,4,5,6].

// Return the array result.

vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1;
        arr1.push_back(nums[0]);
        vector<int> arr2;
        arr2.push_back(nums[1]);
        
        int start = 2;
        int end = nums.size(); // 3
        
        for(int i=start; i<end; i++){
            if(arr1.back() > arr2.back()) arr1.push_back(nums[i]);
            else arr2.push_back(nums[i]);
        }
        
        arr1.insert(arr1.end(), arr2.begin(), arr2.end());
        
        return arr1;
    }

int main(){
  vector<int> nums = {2,1,3};
  vector<int> res;
  res = resultArray(nums);

  for(auto it: res){
    cout << it << " ";
  }
  return 0;
}