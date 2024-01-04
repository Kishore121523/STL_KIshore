#include<bits/stdc++.h>

using namespace std;

void rotateMatrixBy90Brute(vector<vector<int>> &matrix){
  // [0][0] -> [0][3], [0][1] -> [1][3], [0][2] -> [2][3], [0][3] -> [3][3]

  int n = matrix.size();

  vector<vector<int>> ans(n,vector<int>(n));

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      ans[j][n-1-i] = matrix[i][j];
    }
  }

    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
          cout << ans[i][j] << " ";
      }
      cout << "\n";
  }

}
void rotateMatrixBy90Better(vector<vector<int>> &matrix){

  int n = matrix.size();

}

void rotateMatrixBy90Optimal(vector<vector<int>> &matrix){

  int noOfRows = matrix.size(); // no of columns
  int noOfCols = matrix[0].size(); // no of rows

}

int main(){
  // find zero in the matrix and mark every element in that column and row as 0
  vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
  vector<vector<int>> matrix2 = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};

  rotateMatrixBy90Brute(matrix); // TC = O(n*n) and SC = O(n*n)
  rotateMatrixBy90Better(matrix); // TC = O(2*(n*m)) and SC = O(n) + O(m)
  rotateMatrixBy90Optimal(matrix); // 
  return 0;
}