#include<bits/stdc++.h>

using namespace std;

int main() {
  // It takes an element and places it in its correct order
  // 14, 9, 15, 12, 6, 8, 13 - Input
  // 9, 14, 15, 12, 6, 8, 13
  // 9, 14, 15, 12, 6, 8, 13
  // 9, 12, 14, 15, 6, 8, 13
  // 6, 9, 12, 14, 15, 8, 13
  // 6, 8, 9, 12, 14, 15, 13
  // 6, 8, 9, 12, 13, 14, 15 - Sorted array

  // Running the outer loop from 0 to n-1 times, since it takes 6 steps to sort 7 elements
  // worst case and average case time complexity - O(n^2)
  // best case time complexity - O(n)

  vector<int> arr = {14, 9, 15, 12, 6, 8, 13};
  int n = arr.size();

  for(int i=0; i<=n-1; i++){
    int j=i;
    while(j>0 && arr[j-1]>arr[j]){
      int temp = arr[j];
      arr[j] = arr[j-1];
      arr[j-1] = temp;

      j--;
    }
  }

  for(auto it: arr){
    cout << it << ", ";
  }

  return 0;
}

