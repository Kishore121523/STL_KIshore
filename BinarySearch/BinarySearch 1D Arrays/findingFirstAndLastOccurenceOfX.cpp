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

int binarySearchLowerIndex(vector<int> &arr, int n, int target){
  int low = 0;
  int high = n-1;
  int firstOccurence = -1;


  while(low<=high){
    int mid = low + (high-low)/2;

    if(arr[mid] == target) {
    firstOccurence = mid;
    high = mid - 1; // we are looking for the first element, hence move on the left
    }
    else if (target > arr[mid]) low = mid+1;
    else high = mid - 1;  
  }

  return firstOccurence;
}
int binarySearchUpperIndex(vector<int> &arr, int n, int target){
  int low = 0;
  int high = n-1;
  int lastOccurence = -1;

  while(low<=high){
    int mid = low + (high-low)/2;

    if(arr[mid] == target) {
    lastOccurence = mid;
    low = mid + 1; // we are looking for the last element, hence move on the right
    }
    else if (target > arr[mid]) low = mid+1;
    else high = mid - 1;  
  }

  return lastOccurence;
}

vector<int> findFirstAndLastOccurenceOfNumberBinarySearch(vector<int> &arr, int n, int target){

  int lowerIndex = binarySearchLowerIndex(arr,n,target);
  if(lowerIndex == -1) return {-1,-1};
  int upperIndex = binarySearchUpperIndex(arr,n,target);

  return {lowerIndex, upperIndex};

}


int main(){
  vector<int> arr = {5,7,7,8,8,10};
  int n = arr.size();
  int targetElement = 6;
  vector<int> ans;
  vector<int> ans2;

  ans = findFirstAndLastOccurenceOfNumber(arr,n,targetElement); // TC = 2 * O(log2N) 
  ans2 = findFirstAndLastOccurenceOfNumberBinarySearch(arr,n,targetElement); // TC = 2 * O(log2N) 


  for(auto it: ans){
    cout << it << ", ";
  }
  cout << "\n";
  for(auto it: ans2){
    cout << it << ", ";
  }

  return 0;
}