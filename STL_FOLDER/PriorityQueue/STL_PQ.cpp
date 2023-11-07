#include<bits/stdc++.h>

using namespace std;

int main() {

  // Max heap - The element which has the largest value stays at the top
  // Not a linear data structure, inside this a tree data structure is maintained
  // Push -> log(n), Top -> O(1), Pop -> log(n)

  priority_queue<int> pq;
  pq.push(5); // {5}
  pq.push(2); // {5,2}
  pq.push(8); // {8,5,2}
  pq.push(10); // {10,8,5,2}

  cout << pq.top() << " "; // 10

  pq.pop();

  cout << pq.top() << " "; // 8

  // Minimum heap - The element which has the lowest values stays at the top 
  priority_queue<int, vector<int>, greater<int>> mpq;
  mpq.push(5); // {5}
  mpq.push(2); // {2,5}
  mpq.push(8); // {2,5,8}
  mpq.push(10); // {2,5,8,10}

  cout << mpq.top() << " "; // 2
  return 0;
}