#include<bits/stdc++.h>

using namespace std;

int main(){

  // Stores everything in sorted order
  // Stores only unique values
  // Every function happens in log(n)
  // unordered set<int> ust; is another data structure similar to set but as the name suggests the elements are stored in no particular order. But every function has constant time complexity O(1) and the worst case goes to O(n) very rarely.

  set<int> st;
  st.insert(1); // {1}
  st.insert(2); // {1,2}
  st.insert(2); // {1,2}
  st.insert(4); // {1,2,4}
  st.insert(3); // {1,2,3,4}

  // "find" returns an iterator which points to the address of 3, not the actual value 
  auto it = st.find(3); 
  cout << *(it) << " ";

  // if an element is not in the set, it will return st.end() (an iterator which points to address which is right after the last element of the set)
  auto it2 = st.find(6);

  // Deletes the element and maintains the sorted order
  // NOTE: TAKES log(n)
  st.erase(3); // {1,2,4}

  int cnt = st.count(1); // If exist, returns 1 else 0 since no duplicates allowed

  auto it3 = st.find(4);
  st.erase(it3); // NOTE: TAKES CONSTANT TIME

  // {1,2,3,4,5} - {1,4,5}
  auto it4 = st.find(2);
  auto it5 = st.find(4);
  st.erase(it4, it5); // erases everything from 2 to element before 4 - [first, last)

  return 0;
}