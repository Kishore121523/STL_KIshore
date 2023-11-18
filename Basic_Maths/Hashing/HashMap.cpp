#include<bits/stdc++.h>

using namespace std;

int main(){
  // Map<Key, Value> Stores keys and values as a pair. Number - Key and Frequency - Value
  int n = 5;
  vector<int> arr = {1,3,2,1,3}; // input array which can have values between 1 to 12

  // precompute
  map<int,int> mpp; // declaring the hash array and initialising the count with 0
  for(int i=0; i<arr.size(); i++){
    mpp[arr[i]]++;
  }

  // stores in a sorted order of key
  for(auto it: mpp){
    cout << it.first << "->" << it.second << "\n";
  }

  int q = 5; // number of elements to which we need to find the frequency
  while(q--){
    int number;
    cin >> number;
    //fetching from hash array
    cout << number << " Appeared " << mpp[number] << " times" << "\n";
  }
  return 0;
}