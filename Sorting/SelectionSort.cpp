#include<bits/stdc++.h>

using namespace std;

int main(){
  // Selection sort - we select minimums and swap
  // Step 1 - get the minimum element in the array and swap it with the first element
  // Step 2 - From second element, find minimum of the array and swap it with second element
  // Step 3 - From the third element, repeat the same steps till end of the array

  // 13,46,24,52,20,9 - Input 
  // 9,46,24,52,20,13 - Swap 0th index with min element [0 to n-1 array]
  // 9,13,24,52,20,46 - Swap 1st index with min element [1 to n-1 array]
  // 9,13,20,52,24,46 - Swap 2nd index with min element [2 to n-1 array]
  // 9,13,20,24,52,46 - Swap 3rd index with min element [3 to n-1 array]
  // 9,13,20,24,46,52 - Swap 4th index with min element [4 to n-1 array]
  // 9,13,20,24,46,52 - Sorted
  // 6 elements, sorted in 5 stepes - n-1 steps where n is number of elements in input array

  vector<int> arr = {13,46,24,52,20,9};
  int n = arr.size();

  for (int i=0; i<=n-2; i++){
    int min = i;

    for(int j=i; j<=n-1; j++){
      if(arr[j] < arr[min]){
        min = j;
      }
    }
    // swap
    int temp = arr[min];
    arr[min] = arr[i];
    arr[i] = temp;
  }

  for(auto it: arr){
    cout << it << ", ";
  }
  return 0;
}