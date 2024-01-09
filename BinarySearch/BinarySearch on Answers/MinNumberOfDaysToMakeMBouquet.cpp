#include<bits/stdc++.h>

using namespace std;

bool possibleFoo(vector<int> &arr,int day, int m, int k){
  int cnt = 0;
  int boqCount = 0;

  for(int i=0; i<arr.size(); i++){
    if(arr[i] <= day){
      cnt++;
    }else{
      boqCount += (cnt/k);
      cnt = 0;
    }
  }
  boqCount += (cnt/k);
  return boqCount >= m;
}

int minNumberOfDaysToMakeMBouquet(vector<int> &arr, int m, int k){
  // There will be a minimum and a maximum day within the array between which our answer lies
  // If m*k >= no of flowers (size of array) then return -1, since the no of flowers required exceeds the required flowers
  int n = arr.size();
  long long val = m * 1LL * k * 1LL;

  if(val > n) return -1;

  int mini = INT_MAX;
  int maxi = INT_MIN;

  for(int i=0; i<n; i++){
    mini = min(mini, arr[i]);
    maxi = max(maxi, arr[i]);
  }

  int low = mini;
  int high = maxi;

  while(low<=high){
    int mid = low + (high-low)/2;

    if(possibleFoo(arr,mid,m,k)){
      high = mid-1;
    }
    else{
      low = mid+1;
    }
  }

  return low;
}


int main(){
  vector<int> arr = {1,10,3,10,2};
  int m = 3; // no of bouquets
  int k =1; // Number of flowers each bouquet should have

  cout << minNumberOfDaysToMakeMBouquet(arr,m,k); // TC = O(log2N)
  cout << "\n";

  return 0;
}