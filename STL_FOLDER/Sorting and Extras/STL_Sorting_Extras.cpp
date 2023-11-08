#include<bits/stdc++.h>

using namespace std;


 bool comp(pair<int,int> p1, pair<int,int> p2) {
    if(p1.second < p2.second) return true; // condition 1 true, hence keep it the same
    if(p1.second > p2.second) return false; // false, then internally they swap
    
    // if second element of two pairs are same then compare first element 
    if(p1.first > p2.first) return true;
    return false;

  };

int main() {

  // Sorting in arrays
  int arr[4] = {1,5,3,8};

  sort(arr, arr+4); // for array

  for(auto it: arr){
    cout << it << " "; // {1,3,5,8}
  }

  cout << "\n";

  // Sorting in vectors
  vector<int> v1;
  v1.push_back(5);
  v1.push_back(1);
  v1.push_back(3);
  v1.push_back(10);

  sort(v1.begin(), v1.end()); // for vectors

  for (auto it: v1) {
    cout << it << " "; // {1,3,5,10}
  }

  cout << "\n";

  // Sorting in descending order
  sort(v1.begin(), v1.end(), greater<int>());

  for (auto it: v1) {
    cout << it << " "; // {10,5,3,1}
  }

  cout << "\n";

  // Sorting for a specific range in an vector or array
  sort(v1.begin()+2, v1.begin()+4);

  for (auto it: v1) {
    cout << it << " "; // {10,5,1,3}
  }

  cout << "\n";

  // Sorting in a specific way
  // 1) Sort the given array of pairs in order of ascending second element
  // 2) If the second element is same, then sort it descending first element
  // {{4,1}, {2,1}, {1,2}}
  pair<int,int> a[] = {{1,2}, {2,1}, {4,1}};

  sort(a, a + 3, comp); // comp - comparator function written above

  for (auto it: a){
    cout <<"{" << it.first << "," <<it.second << "}"<<" ";
  }

  cout << "\n";

  // Counting number of 1's or set bits 
  int num = 7; // binary of 7 is 111
  int cnt = __builtin_popcount(num);
  cout << cnt << "\n"; // returns 3 (number of 1's or how many set bits are there in 32 bits)
  
  // For long long data type
  long long num2 = 165786536478;
  int cnt2 = __builtin_popcountll(num2);
  cout << cnt2 << "\n"; // returns 19 (which means there are 19 1's among 32 digits)

  // Printing all permutation of a string using STL
  string s = "123";
  sort(s.begin(), s.end()); // it is important to sort the string before permuting to get all possible permuation available.
  do{
    cout << s << "\n";
  } while(next_permutation(s.begin(), s.end()));
  
  // Max element in an array
  int maxi = *max_element(arr, arr+3);
  int maxi2 = *max_element(v1.begin(), v1.end());
  cout << maxi << "\n" << maxi2;
  
  return 0;
}