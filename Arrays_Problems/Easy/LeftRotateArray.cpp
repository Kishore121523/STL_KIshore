#include<bits/stdc++.h>

using namespace std;

void leftRotateArrayBy1Place(vector<int> &arr, int n){
  int temp = arr[0];

  for(int i=1; i<n; i++){
    arr[i-1] = arr[i];
  }
  arr[n-1] = temp;
}

void leftRoateArraybyDPlaces(vector<int> &arr, int n, int d){
  d = d%n; // Ex: 20 rotations in 7(d) element array - After 7 rotation the array is original array. Hence, 7+7+6 = 20 roation. Hence, only 6 rotation is enough for doing 20 rotation

  // // Brute approach with extra temp array
  // int temp[d];
  // for(int i = 0; i < d; i++){
  //   temp[i] = arr[i]; // storing first d elements in the temp array
  // }
  // for(int i = d; i < n; i++){
  //   arr[i-d] = arr[i];
  // }
  // for(int i = n-d; i<n; i++){
  //   arr[i] = temp[i-(n-d)];
  // }

   
}

int main(){
  vector<int> arr = {1,2,3,4,5};
  vector<int> arr2 = {1,2,3,4,5};
  int n = arr.size();

  leftRotateArrayBy1Place(arr, n); // O(n) time complexity - optimal solution
  for(auto it: arr){
    cout<<it<<", ";
  }

  cout <<"\n";

  leftRoateArraybyDPlaces(arr2,n,2);
   for(auto it: arr2){
    cout<<it<<", ";
  }

  cout <<"\n";
  return 0;
}