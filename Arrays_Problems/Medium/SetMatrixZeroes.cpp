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
  // To move across row 0 = matrix[0][...]
  // To move across col 0 = matrix[...][0]

  int noOfRows = matrix.size(); // no of columns
  int noOfCols = matrix[0].size(); // no of rows

  int col0 = 1;

  for(int i=0; i<noOfRows; i++){
    for(int j=0; j<noOfCols; j++){
      if(matrix[i][j] == 0){

        // marking 0 in the corresponding ith row
        matrix[i][0] = 0;

        if(j!=0){
          // marking 0 in the corresponding jth column if its not the first column (j=0)
          matrix[0][j] = 0;
        }else{
          col0 = 0;
        }
      }
    }
  }

  for(int i=1;i<noOfRows;i++){
    for(int j=1; j<noOfCols; j++){
      if(matrix[i][j] != 0){
        // check for corresponding 0th column and row which for the elements that are remaining
        if(matrix[0][j] == 0 || matrix[i][0] == 0){
          matrix[i][j] = 0; // set the element to 0 if its 1 and its corresponding 0th col or row is set to 0
        }
      }
    }
  }

  // if first element of the matrix is 0, then the entire first row will be 0
  if(matrix[0][0] == 0){
    for(int j=0; j<noOfCols; j++){
      matrix[0][j] = 0;
    }
  }

  // if the col0 is 0, then the entire first col will be 0
  if(col0 == 0){
    for(int i=0; i<noOfRows; i++){
      matrix[i][0] = 0;
    }
  }

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