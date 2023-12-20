#include<bits/stdc++.h>

using namespace std;

vector<string> summaryRanges(vector<int>& arr) {
        vector<string> resArr;

        int i =0;
        int n = arr.size();
        
        while(i<n){
        int start = arr[i];
        int end = 0;
        string res = "";
          for(int j=i; j<n; j++){
              if(arr[j+1] - arr[j] == 1){
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

        return resArr;
    }

int main(){
  vector<int> arr = {-1};
  vector<string> res;
  res = summaryRanges(arr);

  for(auto it: res){
    cout << "[" << it  << "],";
  }
  return 0;
}