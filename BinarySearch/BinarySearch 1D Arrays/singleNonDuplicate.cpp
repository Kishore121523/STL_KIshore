#include<bits/stdc++.h>

using namespace std;

int upperBoundFoo(vector<int> &arr, int n, int target){
  int low = 0;
  int high = n-1;
  int ans = n;

  while(low<=high){
    int mid = low+ (high-low)/2;

    if(arr[mid] > target){
      ans = mid;
      high = mid-1;
    }else{
      low = mid+1;
    }
  }
  return ans;
}
int  lowerBoundFoo(vector<int> &arr, int n, int target){
  int low = 0;
  int high = n-1;
  int ans = n;

  while(low<=high){
    int mid = low+ (high-low)/2;

    if(arr[mid] >= target){
      ans = mid;
      high = mid-1;
    }else{
      low = mid+1;
    }
  }
  return ans;
}

int singleNonDuplicate(vector<int> &arr, int n){
  int upperBound = -1;
  int lowerBound = -1;

  for(int i=0; i<n; i++){
    lowerBound = lowerBoundFoo(arr,n,arr[i]);
    upperBound = upperBoundFoo(arr,n,arr[i]);

    if((upperBound - lowerBound) == 1){
      return arr[i];
      break;
    }
  }
  return -1;
}

int singleNonDuplicateOptimal(vector<int> &arr, int n){

  // edge cases handling
  if(n==1) return arr[0];
  if(arr[0] != arr[1]) return arr[0];
  if(arr[n-1] != arr[n-2]) return arr[n-1];

  // binary search
  int low = 1;
  int high = n-2;

  while(low<=high){
    int mid = low + (high-low)/2;

    if(arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1]) return arr[mid];

    // the single element in present in right half - eliminate left half
    // (even,odd) - single element is present on the right half, so elimninate the left half
    // (odd,even) - single element is present on the left half, so eliminate the right half
    if((mid%2==0 && arr[mid+1]==arr[mid])||(mid%2==1 && arr[mid-1] == arr[mid])){
      low = mid+1;
    }
    else{
      high = mid-1;
    }
  }
  return -1;
}


int main(){
  vector<int> arr = {1,1,2,3,3,4,4,8,8};
  int n = arr.size();

  cout << singleNonDuplicate(arr,n); // TC = O(N) + O(log2N)
  cout << "\n";

  // cout << singleNonDuplicateOptimal(arr,n); TC = O(log2N)

  return 0;
}