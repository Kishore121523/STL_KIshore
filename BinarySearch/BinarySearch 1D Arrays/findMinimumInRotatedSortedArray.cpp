#include<bits/stdc++.h>

using namespace std;

int findMinimumInRotatedSortedArrayElements(vector<int> &arr, int n){
  int low = 0;
  int high = n-1;
  int minElement = INT_MAX;

  while(low<=high){
    int mid = low + (high-low)/2;

    if(arr[low] <= arr[high]){
      minElement = min(arr[low], minElement);
      break;
    }

    // Left half is sorted, hence take the smallest and elimate the left half
    if(arr[low] <= arr[mid]){
      minElement = min(arr[low], minElement);
      low = mid + 1;
    }
    // Right Half is sorted, hence take the smallest and elimate the right half
    else{
      minElement = min(arr[mid], minElement);
      high = mid - 1;
    }
  }

  return minElement;
}


int main(){
  vector<int> arr = {4,5,6,7,0,1,2};
  int n = arr.size();

  cout << findMinimumInRotatedSortedArrayElements(arr,n); // TC = O(log2N)
  cout << "\n";

  return 0;
}