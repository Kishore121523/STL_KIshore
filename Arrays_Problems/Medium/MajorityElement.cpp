#include<bits/stdc++.h>

using namespace std;

int majorityElementBetter(vector<int> &arr){
  map<int,int> mpp;

  for(int i=0; i< arr.size(); i++){
    mpp[arr[i]]++;
  }

  for(auto it: mpp){
    if(it.second >= arr.size()/2){
      return it.first;
    }
  }

  return -1;
}

int majorityElementOptimal(vector<int> &arr){
  // Moore's Voting Algorithm
  int ele;
  int cnt = 0;

  // Applying Moore's Voting Algorithm to find the element
  for(int i=0; i<arr.size(); i++){
    if(cnt == 0){
      cnt++;
      ele = arr[i];
    }
    else if(arr[i] == ele){
      cnt++;
    }
    else{
      cnt--;
    }
  }

  int cnt1 = 0;
  // Checking if the found element is majority
  for(int i=0; i<arr.size(); i++){
    if(arr[i] == ele){
      cnt1++;
    }
  }

  if(cnt1 > arr.size()/2) return ele;

  else return -1;


}

int main(){
  // Given an array of size n, return element which appears more than n/2 times
  vector<int> arr = {7,7,5,7,5,1,5,7,5,5,7,7,5,5,5,5};

  cout << majorityElementBetter(arr);
  cout<< "\n";
  cout << majorityElementOptimal(arr);

  return 0;
  
}