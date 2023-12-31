#include<bits/stdc++.h>

using namespace std;

void findLeadersInArrayBrute(vector<int> &arr){
  vector<int> ans;

  for(int i=0; i<arr.size(); i++){
    bool leader = true;

    for(int j = i+1; j<arr.size(); j++){
      if(arr[i]<arr[j]){
        leader = false;
        break;
      } 
    }

    if(leader == true){
      ans.push_back(arr[i]);
    }
  }

  for(auto it:ans){
    cout << it <<", ";
  }
}

void findLeadersInArrayOptimal(vector<int> &arr){
  int maxi = INT_MIN;
  int n = arr.size();

  vector<int> ans;

  for(int i=n-1;i>=0;i--){
    if(arr[i] > maxi){
      maxi = arr[i];
      ans.push_back(arr[i]);
    }
  }

   for(auto it:ans){
    cout << it <<", ";
  }
}

int main(){
  // {10,22,12,3,0,6} => [22,12,6] are the leaders since all the elements to the right of it are smaller than it
  vector<int> arr = {10,22,12,3,0,6};

  findLeadersInArrayBrute(arr);
  cout << "\n";
  findLeadersInArrayOptimal(arr);

  return 0;
}