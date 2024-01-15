#include<bits/stdc++.h>

using namespace std;

bool isPalindrome(string &s){
  int start = 0;
  int end = s.size() - 1;

  while(start <= end){
    if(!isalnum(s[start])){
      start++;
      continue;
    }
    if(!isalnum(s[end])){
      end--;
      continue;
    }

    if(tolower(s[start])!=tolower(s[end])) return false;
    
    start++;
    end--;
  }

  return true;
}


int main(){
  string s = "A man, a plan, a canal: Panama";

  cout << isPalindrome(s); // TC = O(log2N)
  cout << "\n";

  return 0;
}