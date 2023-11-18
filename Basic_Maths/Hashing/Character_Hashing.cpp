#include<bits/stdc++.h>

using namespace std;

int main(){
  // using ASCII a-97 and z-122
  string s = "abcdabehf";

  // pre compute
  int hash[26] = {0};
  for(int i=0; i<s.size(); i++){
    hash[s[i] - 'a'] += 1; // 'a' - 'a' = 0, 'b' - 'a' = 1 ...'z' - 'a' = 26
  }

  int q = 5;
  while(q--){
    char c;
    cin >> c;

  cout << c << " Appeared " << hash[c - 'a'] << " times" << "\n";

  }
  return 0;
}