#include<bits/stdc++.h>

using namespace std;

void reArrangeArrayEleBySignBrute(vector<int> arr){
  vector<int> postiveArr;
  vector<int> negativeArr;

  int n = arr.size();

  for(int i=0; i<n; i++){
    if(arr[i] > 0) postiveArr.push_back(arr[i]);
    else negativeArr.push_back(arr[i]);
  }

  for(int i=0; i<n/2; i++){
    arr[2*i] = postiveArr[i];
    arr[2*i+1] = negativeArr[i];
  }

  for(auto it: arr){
    cout << it << ',';
  }
}

void reArrangeArrayEleBySignOptimal(vector<int> arr){
  int n = arr.size();
  vector<int> ans(n,0);
  int even = 0;
  int odd = 0;

  for(int i=0; i<n; i++){
    if(arr[i] > 0){
      ans[2*even] = arr[i];
      even++;
      
    }
    else{
      ans[2*odd+1] = arr[i];
      odd++;
    }
  }

   for(auto it: ans){
    cout << it << ',';
  }
}

int main(){
  // Given an array with equal positive and negative elements. Re arrange the array with alternating positive and negative sign in the same order.
  vector<int> arr = {3,1,-2,-5,2,-4}; // output = {3,-2,1,-5,2,-4}
  vector<int> arr2 = {3,1,-2,-5,2,-4}; // output = {3,-2,1,-5,2,-4}
  reArrangeArrayEleBySignBrute(arr);
  cout << "\n";
  reArrangeArrayEleBySignOptimal(arr2);
  return 0;
}