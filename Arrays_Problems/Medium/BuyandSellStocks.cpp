#include<bits/stdc++.h>

using namespace std;

int buyAndSellStock(vector<int> &arr){
  int mini = arr[0];
  int maxProfit = 0;

  for(int i=1; i<arr.size(); i++){
    int cost = arr[i] - mini;
    maxProfit = max(maxProfit, cost);
    mini = min(mini, arr[i]);
  }

  return maxProfit;
}

int main(){
  // maximisze the profit. The stock prizes are given in the array in the inreasing order of the date (1st day ,2nd day...)
  vector<int> arr = {7,1,5,3,6,4};
  cout << buyAndSellStock(arr);
  return 0;
}