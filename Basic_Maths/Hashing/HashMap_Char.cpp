#include<bits/stdc++.h>

using namespace std;

int main(){
  // unordered_map<int,int> mpp; // can also use unordered_map for this problem
  // Map - ordered - O(log n), Unordered Map - Best and avg = O(1) - Worst O(n)

  string s = "ababcdez";
  
  map<char,int> mpp;
  for(int i=0;i<s.size();i++){
    mpp[s[i]]++;
  }

  for(auto it: mpp){
    cout << it.first << "->" << it.second << "\n";
  }

  char q=5;
  while(q--){
    cin >> q;
    cout << q << " appeared " << mpp[q] << " times" << "\n";
  }


  return 0;
}