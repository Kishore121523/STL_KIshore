#include<bits/stdc++.h>

using namespace std;

int numberThatAppearsOnce(vector<int> &arr){
  int n = arr.size();
  map<long long, int> mp;

  for(int i =0; i<n; i++){
    mp[arr[i]]++;
  }

  for(auto it: mp){
    if(it.second == 1){
      return it.first;
    }
  }
  return 0;
}

int numberThatAppearsOnceOptimal(vector<int> &arr){
  int n = arr.size();
  int XOR = 0;

  for(int i=0; i<n; i++){
    XOR = XOR ^ arr[i];
  }

  return XOR;
}

int main(){
  vector<int> arr = {1,1,2,3,3,4,4,5,5};

  cout << numberThatAppearsOnce(arr) << "\n" ;
  cout << numberThatAppearsOnceOptimal(arr);
  return 0;
}