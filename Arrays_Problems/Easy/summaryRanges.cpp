#include<bits/stdc++.h>

using namespace std;

vector<string> summaryRanges(vector<int>& arr) {
vector<string> resArr;

        int i = 0;
        int n = arr.size();
        arr.push_back(INT16_MIN);
        
        while(i<n){

          int start = arr[i];
          int end = arr[i];
          string res = "";
    
          if(n!=1)
          {
            for(int j=i; j<n; j++){
                if(arr[j] == arr[j+1] - 1){
                  start = arr[i]; 
                }
                else{
                  i = j+1;
                  end = arr[j]; 
                  break;
                } 
              }

              if(start==end){
                  res += to_string(start);
                  resArr.push_back(res);
              }
                else{
                  res += to_string(start);
                  res += "->";
                  res += to_string(end);
                  resArr.push_back(res);
                }
            }
            
            if(n==1){
              res += to_string(start);
              resArr.push_back(res);
              i++;
            }       
        }

        return resArr;
    }

int main(){
  vector<int> arr = {-2147483648,-2147483647,2147483647};
  vector<string> res;
  res = summaryRanges(arr);

  for(auto it: res){
    cout << "[" << it  << "],";
  }
  return 0;
}