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
  
  if (revNum == duplicate) cout << "true - Palindrome";
  else cout << "false - Not Palindrome";
}

void checkArmstrongNumber(int n){
  int sum = 0;
  int duplicate = n;

  while(n>0){
    int lastDigit = n%10;
    sum = sum + (lastDigit*lastDigit*lastDigit);
    n = n/10;
  }  

  if(sum == duplicate) cout << "true - Armstrong Number";
  else cout << "false - Not Armstrong Number";
}

void findDivisors(int n) {
  vector<int> arr;
  // O(sqrt(n)), the loop runs for sqrt(n) times
  for (int i = 1; i*i <= n; i++){
    if(n%i == 0) arr.push_back(i); // stores 1,2,3,4,6
    if(n/i != i) arr.push_back(n/i); // stores 36, 18, 12, 9
  }

  sort(arr.begin(), arr.end()); // O(no_of_factors * log(no_f_factors))

  //O(no_of_factors)
  for(auto it: arr){
    cout << it << ", ";
  }
}

int main() {

  // Extracting all the digits from a given number N, the digits will be extracted in reverse order
  extractDigits(54321);
  cout<<'\n';

  cout << countingNumberOfDigits(54321) << "\n";
  cout << countingNumberOfDigitsUsingLog(54321) << "\n";

  // Reverse and print a given number
  cout << reversingNumber(54321) << "\n";

  //Palindrom check
  checkPalindrome(121);
  cout<<'\n';

  //Armstrong Numbers - 371 - 3^3 + 7^3 + 1^3 = 371. Hence 371 is armstrong number
  checkArmstrongNumber(371);
  cout<<'\n';

  //Print all divisors - What are all the numbers that divide the given number
  // 36 - 1,2,3,4,6,9,12,18,36
  findDivisors(36);
  cout<<'\n';





  return 0;
}