#include<bits/stdc++.h>

using namespace std;

int lowerBound(vector<int> &arr, int n, int target){
  // int lb = lower_bound(arr.begin(), arr.end(), target) - arr.begin() - STL function
  // smallest index such that arr[ind] >= target
  int low = 0;
  int high = n-1;
  int ans = n; // initial when the answer is not in array we have to return n

  while(low<=high){
    int mid = (low+high)/2;
    if(arr[mid] >= target){
      ans = mid; // may be an answer, hence move further to the left to find the smallest index
      high = mid-1;
    }else{
      low = mid+1; // can't be an answer hence go the right
    }
  }
    return ans;
}

int upperBound(vector<int> &arr, int n, int target){
  // int lb = upper_bound(arr.begin(), arr.end(), target) - arr.begin() - STL function
  // smallest index such that arr[ind] > target
  int low = 0;
  int high = n-1;
  int ans = n; // initial when the answer is not in array we have to return n

  while(low<=high){
    int mid = (low+high)/2;
    if(arr[mid] > target){
      ans = mid; // may be an answer, hence move further to the left to find the smallest index
      high = mid-1;
    }else{
      low = mid+1; // can't be an answer hence go the right
    }
  }
    return ans;
}

int searchInsertPosition(vector<int> &arr, int n, int target){
  return lower_bound(arr.begin(),arr.end(), target) - arr.begin();
}


int main(){
  vector<int> arr = {1,2,4,5,6,22,25,34};
  int n = arr.size();
  int targetElement = 22;

  cout << lowerBound(arr,n,targetElement); // TC = O(log2N)
  cout << upperBound(arr,n,targetElement); // TC = O(log2N)

  // Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
  cout << searchInsertPosition(arr,n,targetElement);

  return 0;
}