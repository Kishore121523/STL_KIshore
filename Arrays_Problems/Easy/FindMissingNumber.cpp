#include<bits/stdc++.h>

using namespace std;

int findMissingNumberHashing(vector<int> &arr, int n){
  vector<int> hashArray(n+1,0); // creating hashArray with size of n+1 and initialzing everything with 0
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

int main(){

  vector<int> arr = {1,2,4,3};
  int n =5;
  cout << findMissingNumberHashing(arr,n) << "\n";
  // findMissingNumberHashing(arr,n);
  return 0;
}