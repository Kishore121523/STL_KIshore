#include<bits/stdc++.h>

using namespace std;

void leftRotateArrayBy1Place(vector<int> &arr, int n){
  int temp = arr[0];

  for(int i=1; i<n; i++){
    arr[i-1] = arr[i];
  }
  arr[n-1] = temp;
}

int main(){
  vector<int> arr = {1,2,3,4,5};
  int n = arr.size();

  leftRotateArrayBy1Place(arr, n); // O(n) time complexity - optimal solution
  for(auto it: arr){
    cout<<it<<", ";
  }
  return 0;
}