#include<bits/stdc++.h>

using namespace std;

int main(){

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