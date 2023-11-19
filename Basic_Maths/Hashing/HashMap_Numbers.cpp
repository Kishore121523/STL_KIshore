#include<bits/stdc++.h>

using namespace std;

int main(){
  // Map<Key, Value> Stores keys and values as a pair. Number - Key and Frequency - Value
  // Map - ordered - O(log n), Unordered Map - Best and avg = O(1) - Worst O(n)
  int n = 5;
  vector<int> arr = {1,3,2,1,3}; // input array which can have values between 1 to 12

  // precompute
  map<int,int> mpp; // declaring the hash array and initialising the count with 0
  
  // unordered_map<int,int> mpp; // can also use unordered_map for this problem
  for(int i=0; i<arr.size(); i++){
    mpp[arr[i]]++; // increases the corresponding key's(arr elements) value by 1 each time
  }

  // stores in a sorted order of key
  int max = arr[0];
  for(auto it: mpp){
    cout << it.first << "->" << it.second << "\n";
    if(it.second > max ) max = it.second;
  }

  // Printing Keys with maximum frequency
  for(auto it: mpp){
    if(it.second == max){
      cout << "Max Frequency Elements " << it.first <<", \n";
    }
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