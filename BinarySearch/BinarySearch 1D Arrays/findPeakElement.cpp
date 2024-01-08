#include<bits/stdc++.h>

using namespace std;

int findPeakElement(vector<int> &arr, int n){
  // edge cases
  if(n==1) return 0;
  if(arr[n-1] > arr[n-2]) return n-1;
  if(arr[0]>arr[1]) return 0;

  // binary search
  int low = 1;
  int high = n-2;

  while(low<=high){
    int mid = low + (high-low)/2;

    if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) return mid;

    // the mid element is in the increasing curve, hence the peak will always be in the right half - eliminate left half
    if(arr[mid] > arr[mid-1] && arr[mid] < arr[mid+1]){
      low = mid + 1;
    }else{
      high = mid-1;
    }
  }
  return -1;
}


int main(){
  vector<int> arr = {1,2,3,4,5,6,7,8,5,1};
  int n = arr.size();

  // arr[i-1] < arr[i] > arr[i+1] - arr[i] is the peak element
  cout << findPeakElement(arr,n); // TC = O(log2N)
  cout << "\n";

  return 0;
}