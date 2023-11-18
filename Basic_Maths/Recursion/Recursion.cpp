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

void reverseArray(vector<int>& a, int l, int r) {
  if(l>=r) return;
  swap(a[l],a[r]);
  reverseArray(a, l+1,r-1);
}

void reverseArray2(vector<int>& a, int i, int n){
  if(i>=n/2) return;
  swap(a[i],a[n-i-1]);
  reverseArray2(a, i+1, n);
}

bool checkPalindrome(string s, int i, int n){
  if(i>=n/2) return true;
  if(s[i] != s[n-i-1]) return false;
  return checkPalindrome(s,i+1,n);  
}

int fibonacci(int n){
  if(n<=1) return n; // fib(0) its 0 an f(1) its 1.
  return fibonacci(n-1) + fibonacci(n-2);
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

  // Reverse an array using 2 pointers
  vector<int> arr = {1,3,2,5,4};
  reverseArray(arr, 0, arr.size() - 1);

  for(auto it: arr){
    cout << it << ", ";
  }
  cout <<"\n";

  // Reverse an array using 1 pointer
  vector<int> arr2 = {1,5,3,7,6};
  reverseArray2(arr2, 0, arr2.size());

  for(auto it: arr2){
    cout << it << ", ";
  }
  cout <<"\n";

  // Palindrome check - MADAM when reversed spells MADAM
  string s = "madam";
  cout << checkPalindrome(s, 0, s.size()) << "\n";

  // Fibonacci - exponential time complexity 
  cout << fibonacci(6) << "\n";

  return 0;
}