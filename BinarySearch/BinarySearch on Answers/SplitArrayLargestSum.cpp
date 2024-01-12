#include<bits/stdc++.h>

using namespace std;

int countPaintersFoo(vector<int> &arr, int sumPossible){
  int painterCount = 1;
  int bricksInTheWall = 0;

  for(int i=0 ;i<arr.size(); i++){
    if(bricksInTheWall+arr[i] <= sumPossible){
      bricksInTheWall += arr[i]; //assign the bricks to the same painter
    }else{
      painterCount++; // increase the painter 
      bricksInTheWall = arr[i];
    }
  }

  return painterCount;
}

int painterPartition(vector<int> &arr, int n, int k){
  int low = *max_element(arr.begin(), arr.end());
  int high = accumulate(arr.begin(), arr.end(), 0);

  while(low<=high){
    int mid = low+ (high-low)/2;

    int countPainters = countPaintersFoo(arr, mid);

    if(countPainters > k){
      low = mid + 1;
    }else{
      high = mid -1 ;
    }
  }
  return low;

}


int main(){
  // Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized. Return the minimized largest sum of the split.
  vector<int> arr = {10,20,30,40};
  int n = arr.size();
  int k = 2;

  cout << painterPartition(arr,n,k); // TC = O([log2(max-min)*O(N)])
  cout << "\n";

  return 0;
}