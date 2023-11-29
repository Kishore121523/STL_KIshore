#include<bits/stdc++.h>

using namespace std;

int largestElement(vector<int> &arr, int n){
  int largest = arr[0];

  for(int i=0; i<n; i++){
    if(arr[i]>=largest) {
      largest = arr[i];
    }
  }

  return largest;
}
int main(){
  vector<int> arr = {5,65,3,234,5,67};
  int n = arr.size();

  cout<<largestElement(arr,n);
  return 0;
}