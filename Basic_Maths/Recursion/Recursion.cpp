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

void sumOfNNumbers(int i, int sum){
  if(i<1){
    cout << sum;
    return;
  }
  sumOfNNumbers(i-1, sum+i);
}

int sumOfNNumbers2(int n){
  if (n==0) return 0; //sum of first 0 numbers is 0 - base case
  return n + sumOfNNumbers2(n-1);
}

int factorial(int n){
  if(n==0) return 1; // 0 factorial is 1 - base case
  return n * factorial(n-1);
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
  cout << "\n";

  // Sum of first N numbers in paramaterised way
  sumOfNNumbers(5,0);
  cout << "\n";

  // Sum of N numbers
  cout << sumOfNNumbers2(5) << "\n";

  // Factorial of N
  cout << factorial(5) << "\n";


  return 0;
}