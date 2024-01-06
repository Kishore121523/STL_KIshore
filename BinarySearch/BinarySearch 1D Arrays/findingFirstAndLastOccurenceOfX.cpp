#include<bits/stdc++.h>

using namespace std;

int lowerBound(vector<int> &arr, int n, int target){
  int low = 0;
  int high = n-1;
  int ans = n;

  // Lower bound is = the smallest element x such that arr[ele] >= target
  while(low<=high){
    int mid = low + (high-low)/2;
    if(arr[mid] >= target){
      ans = mid;
      high = mid - 1;
    }else{
      low = mid + 1;
    }
  }

  return ans;
}

int upperBound(vector<int> &arr, int n, int target){
  int low = 0;
  int high = n-1;
  int ans = n;

  // Lower bound is = the smallest element x such that arr[ele] > target
  while(low<=high){
    int mid = low + (high-low)/2;
    if(arr[mid] > target){
      ans = mid;
      high = mid - 1;
    }else{
      low = mid + 1;
    }
  }

  return ans;
}

vector<int> findFirstAndLastOccurenceOfNumber(vector<int> &arr, int n, int target){

  int lowerIndex = lowerBound(arr,n,target);

  if(lowerIndex == n || arr[lowerIndex] != target) return {-1,-1};
  return {lowerIndex,upperBound(arr,n,target)-1}; 

}


int main(){
  vector<int> arr = {2,4,6,8,8,8,11,13};
  int n = arr.size();
  int targetElement = 8;
  vector<int> ans;

  ans = findFirstAndLastOccurenceOfNumber(arr,n,targetElement); // TC = O(log2N) 

  for(auto it: ans){
    cout << it << ", ";
  }

  return 0;
}