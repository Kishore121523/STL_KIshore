#include<bits/stdc++.h>

using namespace std;

int searchInRotatedSortedArray(vector<int> &arr, int n, int target){
  
}

int main(){
  vector<int> arr = {1,2,4,5,6,22,25,34};
  int n = arr.size();
  int targetElement = 22;

  cout << searchInRotatedSortedArray(arr,n,targetElement); // TC = O(log2N)

  return 0;
}