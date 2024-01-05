#include<bits/stdc++.h>

using namespace std;

int binarySearchIterative(vector<int> &arr, int n, int target){
  int low = 0;
  int high = n-1;

  while(low<=high){
    int mid = (low+high)/2; // if overflow then use --> mid = low + (high-low)/2

    if(arr[mid] == target) return mid;
    else if(target > arr[mid]) low = mid+1;
    else high = mid-1;
  }

  return -1;
}

int binarySearchRecursive(vector<int> &arr, int low, int high, int target){
  if(low>high) return -1;

  int mid = (low+high)/2;

  if(arr[mid] == target) return mid;
  else if(target > arr[mid]) return binarySearchRecursive(arr,mid+1,high, target);
  else return binarySearchRecursive(arr,low,mid-1,target);
}

int main(){
  vector<int> arr = {1,2,4,5,6,22,25,34};
  int n = arr.size();
  int targetElement = 22;

  cout << binarySearchIterative(arr,n,targetElement); // TC = O(log2N)
  cout << "\n";
  cout << binarySearchRecursive(arr,0,n-1,targetElement);

  return 0;
}