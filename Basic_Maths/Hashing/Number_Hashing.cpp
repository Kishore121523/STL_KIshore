#include<bits/stdc++.h>

using namespace std;

int main(){
  // pre-storing and fetching if needed - hashing
  int n = 5;
  int arr[5] = {1,3,2,1,3}; // input array which can have values between 1 to 12

  // precompute
  int hash[13] = {0}; // declaring the hash array and initialising the count with 0
  for(int i=0; i<n; i++){
    hash[arr[i]] += 1;
  }

  int q = 5; // number of elements to which we need to find the frequency
  while(q--){
    int number;
    cin >> number;
    //fetching from hash array
    cout << number << " Appeared " << hash[number] << " times" << "\n";
  }

  return 0;
}