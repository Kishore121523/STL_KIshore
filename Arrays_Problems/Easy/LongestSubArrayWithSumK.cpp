#include<bits/stdc++.h>

using namespace std;

int longestSubArrBrute(vector<int> &arr, int n, int k){
  int len = 0;
  for(int i=0;i<n; i++){
    for(int j=i;j<n;j++){
        int sum = 0;
        for(int k=i; k<=j; k++){
          sum += arr[k];
        } 
      if(sum == k) len = max(len, j-i+1);
    }
  }
  return len;
}

int longestSubArrOptimal(vector<int> &arr, int n, int k){
  
}

int main(){
  // Given sum K, return the length of subarray which is longest with sum K
  vector<int> arr = {1,2,3,1,1,1,4,2,3};
  int n = arr.size();
  int k = 3;

  cout << longestSubArrBrute(arr,n,k)<<"\n";
  cout << longestSubArrOptimal(arr,n,k)<<"\n";

  return 0; 
}