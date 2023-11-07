#include<bits/stdc++.h>

using namespace std;

int main() {

  // Maps is a container which stores everything in (KEY, VALUES)
  // The key and value can be of any data type (int, double, pair etc)
  // MAPS STORES UNIQUE KEYS IN SORTED ORDER. DUPLICATE KEYS CANT BE INSERTED

  map<int, int> mp1;
  map<int, pair<int,int>> mp2;
  map<pair<int,int>, int> mp3;
  
  //map<int, int> mp1;
  mp1[1] = 2; // Key -> 1 and Value -> 2
  mp1.insert({2,4}); // map.insert({key, value})
  mp1.insert({4,8});
  mp1.insert({3,6});

  for(auto it: mp1){
    cout << it.first << " " << it.second << "\n";
  }

  //map<int, pair<int,int>> mp2;
  mp2[1] = make_pair(2,3);
  mp2.insert({2,{4,6}});
  mp2.insert({3, {6,9}});
  mp2[4] = {8,12};

  for(auto it: mp2){
    cout << it.first << " {" << it.second.first << ", " << it.second.second << "}" << "\n";
  }

  //map<pair<int,int>, int> mp3;
  mp3[{1,2}] = 3;
  mp3.insert({{1,3},4});
  mp3.insert({{1,5}, 6});

  for(auto it: mp3){
    cout << "{" << it.first.first << ", " << it.first.second << "} " << it.second << "\n";
  }

  // Accessing values 
  cout << mp1[2] << "\n"; // 4
  cout << mp2[1].first << ", " << mp2[1].second << "\n"; // 2, 3
  cout << mp3[{1,2}] << "\n"; // 3

  return 0;
}