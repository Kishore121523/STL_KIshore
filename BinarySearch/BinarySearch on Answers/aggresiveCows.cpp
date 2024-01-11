#include<bits/stdc++.h>

using namespace std;

bool countCows(vector<int> &arr, int dist, int cows){
  int cntCows = 1;
  int lastPlaceWhereCowsStood = arr[0];

  for(int i=0; i<arr.size(); i++){
    if(arr[i] - lastPlaceWhereCowsStood >= dist){
      cntCows++;
      lastPlaceWhereCowsStood = arr[i];
    }

    if(cntCows >= cows) return true;
  }

  return false;
}

int aggresiveCows(vector<int> &arr, int n, int cows){
  sort(arr.begin(), arr.end());
  int low = 1;
  int high = arr[n-1] - arr[0];
  int ans = -1;

  while(low <= high){
    int mid = low + (high - low)/2;

    bool canWePlaceCows = countCows(arr,mid,cows);

    if(canWePlaceCows){
      ans = mid;
      low = mid+1;
    }else{
      high = mid -1 ;
    }
  }

  return ans;

}


int main(){
  vector<int> arr = {0,3,4,7,9,10};
  int n = arr.size();
  int cows = 4;

  cout << aggresiveCows(arr,n,cows); // TC = O(nlogn + [log2(max-min)*O(N)])
  cout << "\n";

  return 0;
}