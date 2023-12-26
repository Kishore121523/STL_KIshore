#include<bits/stdc++.h>

using namespace std;

int maxSubarraySum(vector<int> &arr){
  // Kadane's Algorithm
  int sum=0;
  int maxi = INT_MIN;

  for(int i=0; i<arr.size(); i++){

    sum += arr[i];
    maxi = max(sum,maxi);

    if(sum < 0) sum = 0;

  }
    return maxi;
}

int main(){
  vector<int> arr = {-2,-3,4,-1,-2,1,5,-3};

  cout << maxSubarraySum(arr);
  return 0;
}