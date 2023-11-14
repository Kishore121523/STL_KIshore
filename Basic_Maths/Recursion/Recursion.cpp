#include <bits/stdc++.h>

using namespace std;

void printNUmber(int n){

  if(n == 4) return; // Base condition to stop the recursion
  cout << n << ", ";
  n++;
  printNUmber(n); // Recursive call
}

int main(){
  // Recursion is a defined as a function calling itself, until a specific condition is mentioned.
  printNUmber(0);

  return 0;
}