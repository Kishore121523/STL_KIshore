#include<bits/stdc++.h>

using namespace std;

void setMatrixToZeroBetter(vector<vector<int>> &matrix){

  int noOfRows = matrix.size(); // no of columns
  int noOfCols = matrix[0].size(); // no of rows

  vector<int> row(noOfRows,0);
  vector<int> col(noOfCols,0);

  for(int i=0; i<noOfRows; i++){
    for(int j=0; j<noOfCols; j++){
      if(matrix[i][j] == 0){
        row[i] = 1;
        col[j] = 1;
      }
    }
  }

  for(int i=0; i<noOfRows; i++){
    for(int j=0; j<noOfCols; j++){
      if(row[i] || col[j]){
        matrix[i][j] = 0;
      }
    }
  }

  for(int i=0; i<noOfRows; i++){
      for(int j=0; j<noOfCols; j++){
          cout << matrix[i][j];
      }
      cout << "\n";
    }
}

void setMatrixToZeroOptimal(vector<vector<int>> &matrix){

  int noOfRows = matrix.size(); // no of columns
  int noOfCols = matrix[0].size(); // no of rows



  for(int i=0; i<noOfRows; i++){
      for(int j=0; j<noOfCols; j++){
          cout << matrix[i][j];
      }
      cout << "\n";
    }
}

int main(){
  // find zero in the matrix and mark every element in that column and row as 0
  vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
  vector<vector<int>> matrix2 = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};

  setMatrixToZeroBetter(matrix); // TC = O(2*(n*m)) and SC = O(n) + O(m)
  setMatrixToZeroOptimal(matrix2); // 
  return 0;
}