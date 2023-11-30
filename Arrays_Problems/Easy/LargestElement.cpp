#include<bits/stdc++.h>

using namespace std;

// Sorting and printing last index = O(nlogn), not optimal
// O(n), optimal solution possible
int largestElement(vector<int> &arr, int n){
  int largest = arr[0];

  for(int i=0; i<n; i++){
    if(arr[i]>=largest) {
      largest = arr[i];
    }
  }

  return largest;
}

// Sorting and printing last before index = O(nlogn), not optimal
// O(n), optimal solution possible 
int secondLargestElement(vector<int> &arr, int n){
  int largest = arr[0];
  int secondLargest = INT_MIN;

  for(int i=1; i<n; i++){
    if(arr[i]>largest){
      secondLargest = largest;
      largest = arr[i];
    }
    else if(arr[i] < largest && arr[i] > secondLargest){
      secondLargest = arr[i];
    }
  }

  return secondLargest;
}

int main(){
  vector<int> arr = {5,65,3,234,5,67};
  int n = arr.size();

  cout<<largestElement(arr,n);
  cout << "\n";
  cout <<secondLargestElement(arr,n);
  return 0;
}