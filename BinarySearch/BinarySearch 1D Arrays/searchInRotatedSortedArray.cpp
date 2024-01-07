#include<bits/stdc++.h>

using namespace std;

int searchInRotatedSortedArrayUniqueElements(vector<int> &arr, int n, int target){
  // check for left sorted or right sorted and perform search
  int low = 0;
  int high = n-1;

  while(low<=high){
    int mid = low + (high-low)/2;

    if(arr[mid] == target) return mid;

    // check if left half is sorted
    else if(arr[low] <= arr[mid]){
      if(target >= arr[low] && target <= arr[mid]){
        high = mid - 1;
      }else{
        low = mid + 1;
      }
    }

    else{
      if(target >= arr[mid] && target <= arr[high]){
        low = mid + 1;
      }else{
        high = mid -1;
      }
    }
  }

  return -1;
}

bool searchInRotatedSortedArrayDuplicateElements(vector<int> &arr, int n, int target){
  // check for left sorted or right sorted and perform search
  int low = 0;
  int high = n-1;

  while(low<=high){
    int mid = low + (high-low)/2;

    if(arr[mid] == target) return true;
    
    if (arr[low] == arr[mid] && arr[mid] == arr[high]){
      low += 1;
      high -= 1;
      continue;
    }

    // check if left half is sorted
    if(arr[low] <= arr[mid]){
      if(target >= arr[low] && target <= arr[mid]){
        high = mid - 1;
      }else{
        low = mid + 1;
      }
    }

    else{
      if(target >= arr[mid] && target <= arr[high]){
        low = mid + 1;
      }else{
        high = mid -1;
      }
    }
  }

  return false;
}

int main(){
  vector<int> arr = {7,8,9,1,2,3,4,5,6};
  int n = arr.size();
  int targetElement = 11;

  cout << searchInRotatedSortedArrayUniqueElements(arr,n,targetElement); // TC = O(log2N)
  cout << "\n";
  cout << searchInRotatedSortedArrayDuplicateElements(arr,n,targetElement); // TC = O(log2N) and worst case O(N/2)

  return 0;
}