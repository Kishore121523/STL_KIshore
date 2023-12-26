#include<bits/stdc++.h>

using namespace std;

int maxSubarraySum(vector<int> &arr){
  // Kadane's Algorithm
  int sum=0;
  int maxi = INT_MIN;

  for(int i=0; i<arr.size(); i++){

    sum += arr[i];

    if(sum > maxi){
      maxi = sum;
    }

    if(sum < 0) sum = 0;

  }
    return maxi;
}

void printmaxSubarraySum(vector<int> &arr){
  int maxi = INT_MIN;
  int sum = 0;
  int startIndex = -1;
  int endIndex = -1;

  for(int i=0; i<arr.size(); i++){
    if(sum == 0){
      startIndex = i;
    }

    sum += arr[i];

    if(sum > maxi){
      maxi = sum;
      endIndex = i;
    }

    if(sum < 0){
      sum = 0;
    }
  }

  for(int i = startIndex; i<=endIndex; i++){
    cout << arr[i]<<", ";
  }
}

int main(){
  vector<int> arr = {-2,-3,4,-1,-2,1,5,-3};

  cout << maxSubarraySum(arr);
  cout << "\n";
  printmaxSubarraySum(arr);
  return 0;
}