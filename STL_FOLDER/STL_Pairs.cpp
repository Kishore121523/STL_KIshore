#include<bits/stdc++.h>

using namespace std;

int main(){

  // To store 2 values in a variable
  pair<int, int> p2 = {1, 3};
  cout << p2.first << " " << p2.second;

  cout << "\n";

  // To store 3 values in a variable
  pair<int, pair<int, int>> p3 = {1, {2,3}};
  cout << p3.first << " " << p3.second.first << " " << p3.second.second;

  cout << "\n";

  // Declaring a array in pair
  pair<int, int> arr[] = {{1,2}, {3,4}, {4,5}};
  cout << arr[0].first << " " << arr[1].second;


  return 0;
}