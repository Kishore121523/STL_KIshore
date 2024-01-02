#include<bits/stdc++.h>

using namespace std;

bool linearSearch(vector<int> arr, int num){
  for(int i=0; i<arr.size(); i++){
    if(arr[i] == num){
      return true;
    }
  }
  return false;
}

int nextPermutationOptimalBrute(vector<int> arr){
  int n = arr.size();
  int longest = 1;

  for(int i=0; i<n; i++){
    int x = arr[i];
    int cnt = 1;

    while(linearSearch(arr,x+1) == true){
      x += 1;
      cnt += 1;
    }

    longest = max(longest, cnt);
  }

  return longest;
}

int nextPermutationOptimalBetter(vector<int> arr){
  if(arr.size() == 0) return 0;

  sort(arr.begin(), arr.end());

  int longest = 1;
  int cntCurrent = 0;
  int lastSmallerElement = INT_MIN;

  for(int i=0; i<arr.size(); i++){
    int currentElement = arr[i];

    if(currentElement-1 == lastSmallerElement){
      lastSmallerElement = currentElement;
      cntCurrent++;
    }
    else if(currentElement != lastSmallerElement){
      lastSmallerElement = currentElement;
      cntCurrent = 1;
    }

    longest = max(longest, cntCurrent);
  }

  return longest;

}

int nextPermutationOptimalOptimal(vector<int> arr){
  unordered_set<int> st;
  int longest = 1;

  if(arr.size() == 0) return 0;

  for(auto it: arr){
    st.insert(it);
  }

  for(auto it: st){
    if(st.find(it-1) == st.end()){
      int cnt = 1;
      int x = it;
      while(st.find(x+1) != st.end()){
        x += 1;
        cnt +=1;
      }
    longest = max(longest, cnt);
    }
  }

  return longest;
}

int main(){
  // {102,4,100,1,101,3,2,1,1} => return 4 because {1,2,3,4} is the longest consecutive sequence
  vector<int> arr = {15 ,6 ,2 ,1 ,16, 4, 2 ,29, 9, 12 ,8 ,5 ,14, 21 ,8 ,12, 17 ,16, 6 ,26 ,3 };
  cout << nextPermutationOptimalBrute(arr); // O(n^2)
  cout << "\n";

  cout << nextPermutationOptimalBetter(arr); // O(nlogn) + O(n)
  cout << "\n";

  cout << nextPermutationOptimalOptimal(arr); // O(n) + O(2n)
  cout << "\n";

  return 0;
}