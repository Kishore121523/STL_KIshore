#include<bits/stdc++.h>

using namespace std;

int noOfTimesAnArrayIsRotated(vector<int> &arr, int n){
  int low = 0;
  int high = n-1;
  int minIndex = n;

  while(low<=high){
    int mid = low + (high-low)/2;

    if(arr[low] <= arr[high]){
      minIndex = low;
      break;
    }

    // Left half is sorted, hence take the smallest and elimate the left half
    if(arr[low] <= arr[mid]){
      minIndex = low;
      low = mid + 1;
    }
    // Right Half is sorted, hence take the smallest and elimate the right half
    else{
      minIndex = mid;
      high = mid - 1;
    }
  }

  return minIndex;
}


int main(){
  vector<int> arr = {3,4,5,1,2};
  int n = arr.size();

  cout << noOfTimesAnArrayIsRotated(arr,n); // TC = O(log2N)
  cout << "\n";

  return 0;
}