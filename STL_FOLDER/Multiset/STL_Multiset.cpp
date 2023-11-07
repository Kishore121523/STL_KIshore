#include<bits/stdc++.h>

using namespace std;

int main(){

  // Similar to set but it will only obey sorted rule and not the unique element rule
  // Multiset stores duplicate values as well but in a sorted order

  multiset<int> mt;
  mt.insert(1); // {1}
  mt.insert(1); // {1,1}
  mt.insert(1); // {1,1,1}
  mt.insert(3); // {1,1,1,3}
  mt.insert(2); // {1,1,1,2,3}
  mt.insert(2); // {1,1,1,2,2,3}

  mt.erase(1); // {2,3} -> Erases all occurences of one

  int cnt = mt.count(1);
  cout << cnt << " "; // prints 0

  int cnt2 = mt.count(2);
  cout << cnt2 << " "; // prints 2

  mt.erase(mt.find(2)); // erases only one occurences, since find returns iterator which points to an address 

  mt.erase(mt.find(2), mt.find(2)+2); // erases first element and the elements before the position given

  return 0;
}