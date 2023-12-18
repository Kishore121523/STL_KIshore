#include<bits/stdc++.h>

using namespace std;

int main(){
  vector<int> nums1 = {1,2,3,0,0,0};
  int m = 3;
  vector<int> nums2 = {2,5,6};
  int n = 3;

  for(int i=m;i<m+n;i++){
    nums1[i] = nums2[i-m];
  }

  int size = nums1.size();

  for (int i=0; i<size-1; i++){
    int min = i;

    for(int j=i; j<=size-1; j++){
      if(nums1[j] < nums1[min]){
        min = j;
      }
    }
    // swap
    int temp = nums1[min];
    nums1[min] = nums1[i];
    nums1[i] = temp;
  }

  return 0;
}