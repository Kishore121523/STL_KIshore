#include <bits/stdc++.h>

using namespace std;

int main(){
  // Stack work in LIFO - Last in first out
  // Indexing is not allowed
  // Only three main function - push, pop, top
  // All operations are O(n), constant time
  stack<int> st;
  st.push(1);
  st.push(2);
  st.push(3);
  st.push(4);
  st.emplace(5);

  cout << st.top() << " "; // 5

  st.pop();

  cout << st.top() << " "; // 4

  cout << st.size() << " "; // 4
  cout << st.empty() << " "; // 0

  cout << "\n";

  stack<int> st2;
  st.swap(st2);

  return 0;
}