#include<bits/stdc++.h>

using namespace std;

set<int> findUnion(vector<int> &arr1, vector<int> &arr2){
  set<int> st;
  int n1 = arr1.size();
  int n2 = arr2.size();

  for(int i=0; i<n1; i++){
    st.insert(arr1[i]);
  }
  for(int i=0; i<n1; i++){
    st.insert(arr2[i]);
  }

  return st;
}

vector<int> findUnionOptimal(vector<int> &arr1, vector<int> &arr2){
  int i = 0;
  int j = 0;
  int n1 = arr1.size();
  int n2 = arr2.size();
  vector<int> unionArr;

  // When i and j are in the range of the array size given enter into the logic
  while(i<n1 && j<n2){
    if(arr1[i] <= arr2[j]){
      if(unionArr.size() == 0 || unionArr.back() != arr1[i]){
          unionArr.push_back(arr1[i]);
      }
      i++;
    }
    else{
      if(unionArr.size() == 0 || unionArr.back() != arr2[j]){
          unionArr.push_back(arr2[j]);
      }
      j++;
    }
  }

  // When arr1 comes to end, copy all the items in the arr2 to union array
  while(j<n2){
    if(unionArr.size()==0 || unionArr.back() != arr2[j]){
          unionArr.push_back(arr2[j]);
      }
      j++;
  }

  // When arr2 comes to end, copy all the items in the arr1 to union array
  while(i<n1){
    if(unionArr.size()==0 || unionArr.back() != arr1[i]){
          unionArr.push_back(arr1[i]);
      }
      i++;
  }

  return unionArr;
}

vector<int> findIntersectionOptimal(vector<int> &arr1, vector<int> &arr2){
  int n = arr1.size();
  int m = arr2.size();
  int i = 0;
  int j=0;

  vector<int> ans;

  while(i<n && j<n){
    if(arr1[i]<arr2[j]) i++;
    else if (arr2[j]<arr1[i]) j++;
    else{
      ans.push_back(arr1[i]);
      i++;
      j++;
    }
  }

  return ans;
}

int main(){
  vector<int> arr1 = {1,1,2,3,4,5};
  vector<int> arr2 = {2,3,4,4,5,6};
  // Union of two arrays above is [1,2,3,4,5,6]

  set<int> st = findUnion(arr1, arr2);

  for(auto it: st){
    cout << it << ", ";
  }

  cout << "\n";

  vector<int> unionArr;
  unionArr = findUnionOptimal(arr1,arr2); // Optimal approach O(n1+n2)

  for(auto it: unionArr){
    cout << it << ", ";
  }

  cout << "\n";

  vector<int> interSecArr;
  interSecArr = findIntersectionOptimal(arr1,arr2);
  for(auto it: interSecArr){
    cout << it << ", ";
  }

  cout << "\n";

  return 0;
}