#include<bits/stdc++.h>

using namespace std;

int sumFoo(vector<int> &arr, int n){
  int sum = 0;

  for(int i=0; i<n; i++){
    sum += arr[i];
  }

  return sum;
}

int findDays(vector<int> &arr, int cap){
  int days = 1;
  int load = 0;

  for(int i=0; i<arr.size(); i++){
    if(arr[i]+load > cap){
      days += 1;
      load = arr[i];
    }else{
      load += arr[i];
    }
  }
  return days;
}

int capacityToShipPackageWithinDDays(vector<int> &arr, int n, int days){

  int maxi = INT_MIN;

  for(int i=0; i<n; i++){
    maxi = max(maxi, arr[i]);
  }

  int low = maxi;
  int high = sumFoo(arr,n);

  while(low<=high){
    int mid = low + (high-low)/2;

    int noOfDays = findDays(arr,mid);

    if(noOfDays <= days){
      high = mid - 1;
    }else{
      low = mid+1;
    }
  }

  return low;
}


int main(){
  vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
  int n = arr.size();
  int days = 5;

  cout << capacityToShipPackageWithinDDays(arr,n, days); // TC = O(log2(max)*N)
  cout << "\n";

  return 0;
}