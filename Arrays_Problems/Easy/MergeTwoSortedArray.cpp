#include<bits/stdc++.h>

using namespace std;

int main(){
  vector<int> nums1 = {1,2,3,0,0,0};
  int m = 3;
  vector<int> nums2 = {2,5,6};
  int n = 3;
  vector<int> nums3(m+n);

  int i = 0;
  int j = 0;
  int k = 0;

  while(i<m && j<n){
    if(nums1[i] < nums2[j]){
      nums3[k] = nums1[i];
      i++;
      k++;
    }else{
      nums3[k] = nums2[j];
      j++;
      k++;
    }
}

if(i<m){
  for(int i2=i; i2<m; i2++){
    nums3[k] = nums1[i2];
    k++;
  }
}

if(j<n){
  for(int i3=j; i3<n; i3++){
    nums3[k] = nums2[i3];
    k++;
  }
}

 for(auto it: nums3){
  cout << it << " ";
 }

  return 0;
}