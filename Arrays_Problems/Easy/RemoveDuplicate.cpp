#include<bits/stdc++.h>

using namespace std;

void removeDuplicateUsingSet(vector<int> &arr, int n){
  set<int> st;
  for(int i=0; i<n; i++){
    st.insert(arr[i]);
  }

  int index = 0;
  for(auto it: st){
    arr[index] = it;
    index++;
  }
  cout << "Number of unique elements in the array: " << st.size() << "\n";
}

int removeDuplicateUsingTwoPointer(vector<int> &arr, int n){
  int currentElementIndex = 0;

  for(int i=1; i<n; i++){
    if(arr[i] != arr[currentElementIndex]){
      arr[currentElementIndex+1] = arr[i];
      currentElementIndex++;
    }
  }
  return currentElementIndex+1;
}

int main(){
  vector<int> arr = {1,1,2,2,2,3,3};
  vector<int> arr2 = {1,2,2,2,3,4,5,5,5,5,5,6,7,8,8,8};
  int n = arr.size();
  int n1 = arr2.size();

  removeDuplicateUsingSet(arr, n); // brute force - O(nlogn) + O(n)
  for(auto it:arr){
    cout << it;
  }
  cout << "\n";

 cout << "Number of unique elements in the array: " << removeDuplicateUsingTwoPointer(arr2, n1); // Optimal approach - O(n)

  
  return 0;
}