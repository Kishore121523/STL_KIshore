#include<bits/stdc++.h>

using namespace std;

int sumDivisorFoo(vector<int> &arr, int n, int divisor){
  int sum = 0;

  for(int i=0; i<n; i++){
    sum += ceil((double)arr[i]/(double)divisor);
  }

  return sum;
}

int findSmallestDivisor(vector<int> &arr, int n, int threshold){

  int maxi = INT_MIN;

  for(int i=0; i<n; i++){
    maxi = max(maxi, arr[i]);
  }

  int low = 1;
  int high = maxi;
  int ans = 1;

  while(low<=high){
    int mid = low + (high-low)/2;

    int sumDivisor = sumDivisorFoo(arr,n,mid);

    if(sumDivisor <= threshold){
      ans = mid;
      high = mid-1;
    }else{
      low = mid+1;
    }
  }
  return ans;
}


int main(){
  vector<int> arr = {1,2,5,9};
  int n = arr.size();
  int threshold = 6;

  cout << findSmallestDivisor(arr,n, threshold); // TC = O(log2(max)*N)
  cout << "\n";

  return 0;
}