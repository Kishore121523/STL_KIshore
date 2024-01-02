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
  sort(arr.begin(), arr.end());
  int longest = 1;
  int cntCurrent = 0;
  int lastSmallerElement = INT_MIN;

  for(int i=0; i<arr.size(); i++){

  }

}

int main(){
  // {102,4,100,1,101,3,2,1,1} => return 4 because {1,2,3,4} is the longest consecutive sequence
  vector<int> arr = {102,4,100,1,101,3,2,1,1};
  cout << nextPermutationOptimalBrute(arr); // O(n^2)
  cout << "\n";

  cout << nextPermutationOptimalBetter(arr); // O(n^2)
  cout << "\n";

  return 0;
}