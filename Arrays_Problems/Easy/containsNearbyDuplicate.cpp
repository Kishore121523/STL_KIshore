#include<bits/stdc++.h>

using namespace std;

  bool bool1(vector<int>& nums, int k) {
       unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++) {
            if(mp.count(nums[i]))
            {
                int diff = abs(mp[nums[i]] - i);
                if (diff <= k)return true;  
            }
            // If the number is already present update the index
            mp[nums[i]] = i;
        }
        return false;
        
}

int main(){
  // Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.
  vector<int> nums = {1,0,1,1};
  int k = 1;

  cout << bool1(nums, k);
  return 0;
}