#include<bits/stdc++.h>

using namespace std;

double medianOfTwoSortedArrayBetter(vector<int> &arr1,vector<int> &arr2){
  int n1 = arr1.size();
  int n2 = arr2.size();
  int n = (n1+n2);
  int ind2 = n/2;
  int ind1 = ind2 - 1;
  int i = 0, j = 0;
  int ind1el = -1, ind2el = -1;
  int cnt = 0;

  while(i<n1 && j<n2){
    if(arr1[i] < arr2[j]){
      if(cnt == ind1) ind1el = arr1[i];
      if(cnt == ind2) ind2el = arr1[i];
      cnt++;
      i++;
    }else{
      if(cnt == ind1) ind1el = arr2[j];
      if(cnt == ind2) ind2el = arr2[j];
      cnt++;
      j++;
    }
  }

  while(i<n1){
      if(cnt == ind1) ind1el = arr1[i];
      if(cnt == ind2) ind2el = arr1[i];
      cnt++;
      i++;
  }

  while(j<n2){
      if(cnt == ind1) ind1el = arr2[j];
      if(cnt == ind2) ind2el = arr2[j];
      cnt++;
      j++;
    } 

  if(n%2 == 1) return ind2el;

  return (double)((double)(ind1el + ind2el))/2.0;
  }

double medianOfTwoSortedArrayOptimal(vector<int> &arr1,vector<int> &arr2){
  int n1= arr1.size();
  int n2 = arr2.size();

  if(n1>n2) return medianOfTwoSortedArrayBetter(arr2,arr1); // to perform the binary search on the smaller array, and this makes sure that arr1 is always the smaller arary

  int low = 0;
  int high = n1;
  int noOfElemenentsinLeft = (n1+n2+1)/2;
  int n = n1+n2;

  while(low<=high){
    int mid1 = low+(high-low)/2;
    int mid2 = noOfElemenentsinLeft - mid1;

    int l1 = INT_MIN, l2=INT_MIN;
    int r1 = INT_MAX, r2=INT_MAX;

    if(mid1<n1) r1= arr1[mid1];
    if(mid2<n2) r2= arr2[mid2];
    if(mid1-1>=0) l1 = arr1[mid1-1];
    if(mid2-1>=0) l2 = arr2[mid2-1];

    if(l1<=r2 && l2<=r1){
      if(n%2==1) return max(l1,l2);
      return (double)(max(l1,l2)+min(r1,r2)) / 2.0;
    }
    else if (l1>r2) high = mid1-1;
    else low = mid1+1; 
  }
return -1;
}



int main(){
  vector<int> arr1 = {1,3,4,7,10,12};
  vector<int> arr2 = {2,3,6,15}; 

  cout << medianOfTwoSortedArrayBetter(arr1,arr2); // TC = O(n1+n2)
  cout << medianOfTwoSortedArrayOptimal(arr1,arr2); // TC = O(min(logm,logn))
  cout << "\n";

  return 0;
}