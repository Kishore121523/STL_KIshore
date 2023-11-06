#include<bits/stdc++.h>

using namespace std;

int main(){

  // List is similar to vector but they will give you front operations as well
  list<int> ls;
  ls.push_back(2);
  ls.emplace_back(4);

  ls.push_front(3);
  ls.emplace_front(5);

  for(auto it: ls){
    cout << it << " "; // {5 3 2 4}
  }

  // begin, end, rbegin, rend, clear, insert, size, swap all are same as vectors
  return 0;
}
