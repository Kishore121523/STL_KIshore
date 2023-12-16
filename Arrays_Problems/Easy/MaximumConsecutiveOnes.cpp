#include<bits/stdc++.h>

using namespace std;

int maxConsecutiveOnes(vector<int> &arr){
  int maxi = 0;
  int cnt = 0;
  for(int i=0; i< arr.size(); i++){
    if(arr[i]==1){
      cnt++;
      maxi = max(maxi,cnt);
    }
    else {
      cnt = 0;
    }
  }

  return maxi;
}

int main(){
  vector<int> arr = {1,1,0,1,1,1,0,0,1};

  cout<<maxConsecutiveOnes(arr);
  return 0;
}