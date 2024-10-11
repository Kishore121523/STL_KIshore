#include<bits/stdc++.h>
using namespace std;

int fib(int n, vector<int> &dp){
  // base case for fib
  if(n<=1) return n;

  // check if the subproblem has been already computed before the recursion call
  if(dp[n] != -1) return dp[n];

  // store the answer in the respective index of the DP array whenever the recursion returns with a result
  return dp[n] = fib(n-1, dp) + fib(n-2, dp);
}

int main(){
  // This will be the nth fib number to be found
  int n;
  cin >> n;

  // for DP, we need to put init an array for memoisation
  vector<int> dp(n+1, -1); // init array with size n+1 and -1 as values

  cout << fib(n,dp);
}