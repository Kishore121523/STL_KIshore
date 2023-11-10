#include<bits/stdc++.h>

using namespace std;

void extractDigits(int n){
  while(n>0){
    cout << n%10 << " "; // 54321%10 = 1
    n = n/10; // n = 54321/10 = 5432
  }
}

int countingNumberOfDigits(int n){
  int count = 0;
  while(n>0){
    count += 1;
    n = n/10;
  }
  return count;
}

int countingNumberOfDigitsUsingLog(int n){
  int count = log10(n) + 1; // log10(54321) = will return a number starting with 4, so add 1
  return count;
}

int reversingNumber(int n){
  int revNo = 0;
  while(n>0){
    int lastDigit = n%10;
    revNo = (revNo*10)+lastDigit;
    n = n/10;
  }

  return revNo;
}

void checkPalindrome(int n){
  int duplicate = n;
  int revNum = 0;

  while(n>0){
    int lastDigit = n%10;
    revNum = (revNum*10) + lastDigit;
    n = n/10;
  }
  
  if (revNum == duplicate) cout << "true";
  else cout << "false";
}

int main() {

  // Extracting all the digits from a given number N, the digits will be extracted in reverse order
  extractDigits(54321);
  cout<<'\n';

  cout << countingNumberOfDigits(54321) << "\n";
  cout << countingNumberOfDigitsUsingLog(54321) << "\n";

  cout << reversingNumber(54321) << "\n";

  checkPalindrome(121);
  cout<<'\n';



  return 0;
}