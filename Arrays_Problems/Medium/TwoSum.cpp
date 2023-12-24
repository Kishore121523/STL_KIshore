#include<bits/stdc++.h>

using namespace std;

bool twoSumBetter(vector<int> &arr, int n, int sum){
  // using map data structure
  map<int, int> mpp;

  for(int i=0; i<n; i++){
    int ele = arr[i];
    int more = sum - ele;

    if(mpp.find(more) != mpp.end()){
      return true; // for returning the indices - return (mpp[more], i)
    }
    mpp[ele] = i;
  }

  return false;
}

bool twoSumOptimal(vector<int> &arr, int n, int targetSum){
  // without using map data structure
  int left = 0;
  int right = n-1;
  sort(arr.begin(), arr.end());

  while(left < right){
    int sum = arr[left] + arr[right];

    if(sum == targetSum){
      return true;
    }

    else if(sum < targetSum) left++;
    else right--;
  }
  return false;
}

int main(){
  vector<int> arr = {2,6,5,8,11};
  int n = arr.size();
  int targetSum = 14;

  cout << twoSumBetter(arr,n,targetSum);
  cout << twoSumOptimal(arr,n,targetSum);
  return 0;
}