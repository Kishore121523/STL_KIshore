#include<bits/stdc++.h>

using namespace std;

vector<int> nextPermutationOptimal(vector<int> arr){
  int index = -1;
  int n = arr.size();

  for(int i = n-2; i>=0; i--){
    if(arr[i] < arr[i+1]){
      index = i;
      break;
    }
  }

  if(index == -1){
    reverse(arr.begin(), arr.end());
    return arr;
  }

  for(int i = n-1; i>index; i--){
    if(arr[i] > arr[index]){
      swap(arr[i], arr[index]);
      break;
    }
  }

  reverse(arr.begin() + index + 1, arr.end());

  return arr;
}

int main(){
  // {3,1,2} => (1,2,3), (1,3,2), (2,1,3), (2,3,1), (3,1,2), (3,2,1) a total of 3! = 6 permutations arranged in dictionary order 
  vector<int> arr = {2,3,1};
  vector<int> ans = {};
  ans = nextPermutationOptimal(arr);

  for(auto it:ans){
    cout << it <<", ";
  }
  return 0;
}