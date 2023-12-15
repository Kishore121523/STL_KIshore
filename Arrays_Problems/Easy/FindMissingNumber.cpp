#include<bits/stdc++.h>

using namespace std;

int findMissingNumberHashing(vector<int> &arr, int n){
  vector<int> hashArray(n+1,0); // creating hashArray with size of n+1 and initialzing everything with zero
  int missingNumber = 0;

  for(int i=0;i<n;i++){
    hashArray[arr[i]] = 1;
  }
  
  for(int i=1;i<=n;i++){
    if(hashArray[i] == 0) {
    missingNumber = i;
    break;  
    }
  }
  return missingNumber;
}

int findMissingNumberOptimalUsingSum(vector<int> &arr, int n){
  int sum = (n*(n+1))/2;
  int sum2 = 0;

  for(int i=0; i<n; i++){
    sum2 = sum2 + arr[i];
  }

  return sum-sum2;
}

int findMissingNumberOptimalUsingXOR(vector<int> &arr, int n){
  int XOR1 = 0;
  int XOR2 = 0;

  for(int i=0; i<n-1; i++){
    XOR2 = XOR2 ^ arr[i];
    XOR1 = XOR1 ^ (i+1);
  }

  XOR1 = XOR1 ^ n;

  return XOR1 ^ XOR2;
}


int main(){

  vector<int> arr = {1,2,4,5};
  int n =5;
  cout << findMissingNumberHashing(arr,n) << "\n";
  cout << findMissingNumberOptimalUsingSum(arr,n) << "\n";
  cout << findMissingNumberOptimalUsingXOR(arr,n) << "\n";
  return 0;
}