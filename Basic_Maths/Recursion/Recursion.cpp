#include <bits/stdc++.h>

using namespace std;

void printNUmber(int n){
  if(n == 4) return; // Base condition to stop the recursion
  cout << n << ", ";
  n++;
  printNUmber(n); // Recursive call
}

void printName(int i,int n){
  if(i>n) return;
  cout << "Kishore" << ", ";
  printName(i+1,n);

}

void printNumber(int i,int n){
  if(i>n) return;
  cout << i << ", ";
  printNumber(i+1, n);
}

void printNumberReverse(int i, int n){
  if(n<i) return;
  cout << n << ", ";
  printNumberReverse(i, n-1);
}

void printNumberBackTrack(int i, int n){
  if(n<i) return;
  printNumberBackTrack(i, n-1);
  cout << n << ", ";
}

void printNumberReverseBackTrack(int i, int n){
  if(i>n) return;
  printNumberReverseBackTrack(i+1, n);
  cout << i << ", ";
}


int main(){
  // Recursion is a defined as a function calling itself, until a specific condition is mentioned.
  printNUmber(0);
  cout << "\n";

  // Printing name 5 times using recursion, time complexity is O(n)
  printName(1,5);
  cout << "\n";

  // Print linearly from M to N
  printNumber(1,10);
  cout << "\n";

  // Print reverse from M to N
  printNumberReverse(1,10);
  cout << "\n";

  // Print linearly from M to N using backtracking
  printNumberBackTrack(1,10);
  cout << "\n";

  // Print reverse from M to N using backtracking
  printNumberReverseBackTrack(1,10);




  return 0;
}