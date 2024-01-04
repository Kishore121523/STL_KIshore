#include<bits/stdc++.h>

using namespace std;

vector<int> rotateMatrixBy90Brute(vector<vector<int>> &matrix){

  int noOfRows = matrix.size();
  int noOfCols = matrix[0].size();

  int top = 0;
  int right = noOfCols - 1;
  int left = 0;
  int bottom = noOfRows - 1;
  vector<int> ans;

  while(left<=right && top <=bottom){

      //left to right
      for(int i = left; i<=right; i++){
        ans.push_back(matrix[top][i]);
      }
      top++;

      //top to bottom
      for(int i = top; i<=bottom; i++){
        ans.push_back(matrix[i][right]);
      }
      right--;

      if(top <= bottom){
        //right to left
        for(int i=right; i>=left; i--){
          ans.push_back(matrix[bottom][i]);
        }
        bottom--;
      }

      if(left<=right){
        //bottom to top
        for(int i = bottom; i>=top; i--){
          ans.push_back(matrix[i][left]);
        }
        left++;
      }
  }

  return ans;
}

int main(){
  // find zero in the matrix and mark every element in that column and row as 0
  vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
  vector<int> ans;

  ans = rotateMatrixBy90Brute(matrix); // TC = O(n*n) and SC = O(n*n)

  for(auto it: ans){
    cout << it << " ";
  }
  return 0;
}