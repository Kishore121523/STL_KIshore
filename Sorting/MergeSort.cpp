#include<bits/stdc++.h>

using namespace std;

void merge2(vector<int> &arr, int low, int mid, int high){
  vector<int> tempArr;
  //[low..high] = [low...mid] + [mid+1..high]
  int left = low;
  int right = mid+1;

  // When elements present in both right and left part of the array, compare and store the lesser element in temp array
  while(left<=mid && right<=high){
    if(arr[left]<=arr[right]){
      tempArr.push_back(arr[left]);
      left++;
    }
    else{
      tempArr.push_back(arr[right]);
      right++;
    }
  }

  // If right part is over, then simply store all the remaining elements in left part into the array
  while(left<=mid){
    tempArr.push_back(arr[left]);
    left++;
  }

  // If left part is over, then simply store all the remaining elements in right part into the array
  while(right<=high){
    tempArr.push_back(arr[right]);
    right++;
  }

  // Storing values from temp array into original array
  for(int i=low; i<=high; i++){
    arr[i] = tempArr[i-low];
  }
}

void mergeSort(vector<int> &arr, int low, int high){
  if(low==high){
    return;
  }
  int mid = (low+high)/2;
  mergeSort(arr, low,  mid);
  mergeSort(arr, mid+1, high);
  merge2(arr,low,mid,high);
  }

int main(){
  // Focusses on Divide and Conquer Method
  // This algorithm hypothetically divides the array into 2 parts
  // Then, left part is divided into 2 parts and right part into two parts. And recursively repeats the same process until the elements in the divided parts can't be divided further.
  // Later, the divided arrays are merged. While merging, the two arrays will be sorted and merged.
  // Time complexity - O(N * log2(N)) and Space Complexity - O(N)
  vector<int> arr = {3,2,4,1,3};
  int n = arr.size();

  mergeSort(arr, 0, n-1);

  for(auto it: arr){
    cout << it << ", ";
  }

  return 0;
}