#include<bits/stdc++.h>

using namespace std;

void sort012Better(vector<int> &arr){
  int n = arr.size();
  int cnt0 = 0; 
  int cnt1 = 0; 
  int cnt2 = 0; 

  for(int i=0; i<n; i++){
    if(arr[i] == 0) cnt0++;
    else if(arr[i] == 1) cnt1++;
    else cnt2++;
  }

  for(int i = 0; i < cnt0; i++){
    arr[i] = 0;
  }
  for(int i = cnt0; i < cnt0+cnt1; i++){
    arr[i] = 1;
  }
  for(int i = cnt0+cnt1; i<n; i++){
    arr[i] = 2;
  }

  for(auto it: arr){
    cout << it;
  }
}

void sort012Optimal(vector<int> &arr){
  // using Dutch National Flag Algorithm, using three pointer approach
  // [0 ... low-1] should be 0
  // [low ... mid-1] should be 1
  // [mid ... high] should be 0/1/2 in unsorted manner - initial array arr[0] will be low and mid and high will be n-1
  // [high+1 ... n-1] should be 2

  int low=0; int mid = 0; int high = arr.size()-1;

  while(mid <= high){
    if(arr[mid] == 0){
      swap(arr[mid], arr[low]);
      low++;
      mid++;
    }

    else if(arr[mid] == 1){
      mid++;
    }

    else {
      swap(arr[mid], arr[high]);
      high --;
    }
  }

 for(auto it: arr){
    cout << it;
  }

}

int main(){
  vector<int> arr = {0,1,2,0,1,2,1,2,0,0,0,1};
  
  sort012Better(arr);
  cout << "\n";
  sort012Optimal(arr);


  return 0;
}