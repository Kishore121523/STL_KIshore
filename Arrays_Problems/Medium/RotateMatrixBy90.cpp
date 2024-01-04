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

void reverseArr(vector<int> &arr, int n){
  int p1=0; 
  int p2 = n-1;

  while(p1<p2){
    swap(arr[p1], arr[p2]);
    p1++;
    p2--;
  }
}

void rotateMatrixBy90Optimal(vector<vector<int>> &matrix){
  // Transpose and reverse every row
  int n = matrix.size();

  // Transpose
  for(int i=0; i<n-1; i++){
    for(int j=i+1; j<n; j++){
        swap(matrix[i][j], matrix[j][i]);
      }
  }

  // Reverse every row
  for(int i=0; i<n;i++){
    reverseArr(matrix[i], n);
  }

  for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
          cout << matrix[i][j] << " ";
      }
      cout << "\n";
  }
}


int main(){
  // find zero in the matrix and mark every element in that column and row as 0
  vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};

  rotateMatrixBy90Brute(matrix); // TC = O(n*n) and SC = O(n*n)
  cout<<"\n";
  rotateMatrixBy90Optimal(matrix); // TC = O(n/2*n/2) + O(n*n/2) and SC = No extra space
  return 0;
}