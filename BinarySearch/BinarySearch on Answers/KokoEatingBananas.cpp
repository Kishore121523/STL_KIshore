#include<bits/stdc++.h>

using namespace std;

int maximumEle(vector<int> &arr){
  int maxElement = INT_MIN;

  for(auto it: arr){
    maxElement = max(it, maxElement);
  }
  return maxElement;
}

int totalHoursFoo(vector<int> &arr, int hours){
  int totalHours = 0;

  for(int i=0; i<arr.size(); i++){
    totalHours += ceil((double)arr[i]/(double)hours);
  }

  return totalHours;
}

int kokoEatingBananas(vector<int> &arr, int h){
  // the answer can always be between 1 and max element in array. Hence run BS on answers
  int low = 1;
  int high = maximumEle(arr);
  int ans = INT_MAX;

  while(low<=high){
    int mid = low + (high-low)/2;

    int totalHours = totalHoursFoo(arr,mid);

    if(totalHours <= h){
      ans = mid;
      high = mid-1;
    }else{
      low = mid+1;
    }
  }

  return ans;
}

int main(){
  vector<int> arr = {3,6,7,11};
  int h = 8;
  
  cout << kokoEatingBananas(arr,h);
  return 0;
}