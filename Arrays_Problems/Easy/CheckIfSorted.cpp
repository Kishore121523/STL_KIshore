#include<bits/stdc++.h>

using namespace std;

bool checkIfSorted(vector<int> &arr, int n){
  for(int i=1;i<n;i++){
    if(arr[i] >= arr[i-1]){
      continue;
    }
    else{
      return false;
    }
  }

  return true;
}

int main(){
  vector<int> arr = {5,65,3,234,5,67};
  // vector<int> arr = {55,67,88,454};
  int n = arr.size();

  cout << checkIfSorted(arr, n);
  return 0;
}