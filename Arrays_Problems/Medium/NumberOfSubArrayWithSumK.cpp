#include<bits/stdc++.h>

using namespace std;

int numberOfSubArrayWithSumKBetter(vector<int> &arr, int n, int targetSum){
  int cnt = 0;

  for(int i=0; i<n; i++){
    int sum = arr[i];
    if(sum == targetSum){
      cnt+=1;
    }
    for(int j=i+1; j<n; j++){
      sum += arr[j];
      if(sum == targetSum) {
          cnt+=1;
      }
    }
  }

  return cnt;
}

bool numberOfSubArrayWithSumKOptimal(vector<int> &arr, int n, int k){
  // using prefix sum
  unordered_map<int,int> mpp;
  int cnt = 0;
  int preSum = 0;
  mpp[preSum] = 1;

  for(int i = 0; i<n; i++){
    preSum += arr[i];
    int numberFind = preSum - k;

    if(mpp.find(numberFind) != mpp.end()){
      cnt += mpp[numberFind];
    }

    mpp[preSum]++;
  }

  return cnt;
}

int main(){
  vector<int> arr = {1,2,3,-3,1,1,1,4,2,-3};
  int n = arr.size();
  int targetSum = 3;

  cout << numberOfSubArrayWithSumKBetter(arr,n,targetSum); // TC = O(n^2)
  cout << "\n";
  cout << numberOfSubArrayWithSumKOptimal(arr,n,targetSum); // TC = O(N*logN) - Normal map and O(N*1) for unordered map
  return 0;
}