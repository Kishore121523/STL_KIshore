#include<bits/stdc++.h>

using namespace std;

  bool bool1(vector<int>& nums) {
        set<int> st;

        for(auto it: nums){
          if(st.count(it) > 0) return true;
          st.insert(it);
        }

       return false;
    }

int main(){
  vector<int> nums = {1,2,3,1};

  cout << bool1(nums);
  return 0;
}