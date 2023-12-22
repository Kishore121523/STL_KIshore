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

int longestSubArrBetter(vector<int> &arr, int n, long long k){
  map<long long, int> prefSumMap;
  long long sum = 0;
  int maxLen = 0;

  for(int i=0; i<arr.size(); i++){
    sum += arr[i];

    if(sum == k) {
      maxLen = max(maxLen, i+1);
    }

    long long remaining = sum - k;

    if(prefSumMap.find(remaining) != prefSumMap.end()){
      int len = i - prefSumMap[remaining];
      maxLen = max(maxLen, len);
    }

    if(prefSumMap.find(sum) != prefSumMap.end()){
      prefSumMap[sum] = i;
    }
  }
  return maxLen;
}

int longestSubArrOptimal(vector<int> &arr, int n, long long k){
  int left = 0, right = 0;
  long long sum = arr[0];
  int maxLen = 0;

  while(right<n){

    while(left <= right && sum > k){
      sum -= arr[left];
      left++;
    }

    if(sum == k){
      maxLen = max(maxLen, right - left + 1 );
    }

    right++;  
    if(right<n){
      sum += arr[right];
    }
  }
  return maxLen;
}

int main(){
  // Given sum K, return the length of subarray which is longest with sum K
  vector<int> arr = {1,2,3,1,1,1,4,2,3};
  int n = arr.size();
  int k = 3;

  cout << longestSubArrBrute(arr,n,k)<<"\n";
  cout << longestSubArrBetter(arr,n,k)<<"\n";
  cout << longestSubArrOptimal(arr,n,k)<<"\n";

  return 0; 
}