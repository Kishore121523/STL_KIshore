#include<bits/stdc++.h>

using namespace std;

int countKeyChanges(string s) {
        int cnt = 0;
        for(int i=0; i<s.size(); i++){
            if(i!=s.size()-1)
            {   
                cout<< abs((int)s[i]-(int)s[i+1]) << "\n";
                if(abs((int)s[i]-(int)s[i+1]) != 32 && s[i] != s[i+1] ) {
                  cnt++;
            }
                
            }
    }
        return cnt;
    }

int main(){
  string s = "AaAaAaaA";
  cout << countKeyChanges(s);
  return 0;
}