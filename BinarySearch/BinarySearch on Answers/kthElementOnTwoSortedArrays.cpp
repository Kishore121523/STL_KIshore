#include<bits/stdc++.h>

using namespace std;

double kthElement(vector<int> &arr1,vector<int> &arr2, int k){
  int n1= arr1.size();
  int n2 = arr2.size();

  if(n1>n2) return kthElement(arr2,arr1,k); // to perform the binary search on the smaller array, and this makes sure that arr1 is always the smaller arary

  int low = max(0,k-n2);
  int high = min(k,n1);
  int noOfElemenentsinLeft = k;
  int n = n1+n2; // 10

  while(low<=high){
    int mid1 = low+(high-low)/2; // 2
    int mid2 = noOfElemenentsinLeft - mid1; // 3

    int l1 = INT_MIN, l2 = INT_MIN;
    int r1 = INT_MAX, r2 = INT_MAX;

    if(mid1<n1) r1= arr1[mid1];
    if(mid2<n2) r2= arr2[mid2];
    if(mid1-1>=0) l1 = arr1[mid1-1];
    if(mid2-1>=0) l2 = arr2[mid2-1];

    if(l1<=r2 && l2<=r1){
      return max(l1,l2);
    }
    else if (l1>r2) high = mid1-1;
    else low = mid1+1; 
  }
return -1;
}



int main(){
  vector<int> arr1 = {1,3,4,7,10,12}; // 6
  vector<int> arr2 = {2,3,6,15}; // 4
  int k = 5;

  cout << kthElement(arr1,arr2,k); // TC = O(min(logm,logn))
  cout << "\n";

  return 0;
}