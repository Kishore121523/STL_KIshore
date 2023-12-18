#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int> arr = {1,2,3,4};
  int n = arr.size(); 
  
  for(int i = n-1; i>=0; i--){
    if(i==n-1){
      arr[i]++;
    }
    if(arr[i] == 10){
      arr[i] = 0;
      if(i!=0){
        arr[i-1]++;
      }
      else{
        arr.push_back(0);
        arr[i] = 1;
      }
    }
  }

  for(auto it: arr){
    cout << it << "\n";
  }
  
  return 0;
}