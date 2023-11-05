#include<bits/stdc++.h>

using namespace std;

int main(){

  // In normal arrays if we create an array of size 5, it will be giving us array with 5 possible indexes (0 ot 4). 
  // The size of this array can't be modified later on since arrays are constant in size. Vector is a container that is dynamic in nature, that is we can always increase the size of the vector when needed.
  // If there is an requirement where we do not know the size of a particular data structure that is required, then use VECTOR.

  vector<int> v; // Creates an empty container

  v.push_back(1); // Inserts 1 
  v.emplace_back(2); // Similar to push back(faster than push back). Dynamically increases its size and puts 2 after 1 in the container.
  v.emplace_back(3);
  v.emplace_back(4);
  v.emplace_back(5);

  vector<pair<int,int>> v2;
  v2.push_back({1,2}); // Needs curly braces
  v2.emplace_back(1,2); // Doesn't need curly braces

  // Creating a container of elements which is already filled with a default value
  vector<int> v3(5,1000); // {100, 100, 100, 100, 100}
  vector<int> v4(5); // {0, 0, 0, 0, 0} - it can be 0 or garbage value depends on compiler

  // To copy a vector into another vector
  vector<int> v5(5,20);
  vector<int> v6(v5);

  // Even if we predefine the vector during initialisation, later using push_back or emplace_back we can dynamically add more elements.

  // Accessing elements in a vector
  cout << v[0] << " " << v.back(); // similar indexing as array

  cout << "\n";

  // Printing the entire vector using an iterator
  for(vector<int>::iterator it = v.begin(); it!=v.end(); it++){
      cout << *(it) << " ";
    }
  
  cout << "\n";
  
  // Using auto data type
  for(auto it = v.begin(); it!=v.end(); it++){
    cout << *(it) << " ";
  }

  cout << "\n";

  // Using for each loop
  for (auto it: v){
    cout << it << " ";
  }

  cout << "\n";

  //Deletion in a vector. {1,2,3,4,5} -> {1,3,4,5}
  v.erase(v.begin() + 1);
  for (auto it: v){
    cout << it << " ";
  }

  cout << "\n";

  //Deletes begin+1 and begin+2 (not begin+3) = [start, end). {1,3,4,5} -> {1,5}
  v.erase(v.begin() + 1, v.begin() + 3);
  for (auto it: v){
    cout << it << " ";
  }

  cout << "\n";

  // Insert a element in the begining. {1, 5} -> {300, 1, 5}
  v.insert(v.begin(), 300);
  for(auto it: v){
    cout << it << " ";
  }

  cout << "\n";

  // Insert a element in the begining. {300, 1, 5} -> {300, 400, 400, 1, 5}
  v.insert(v.begin()+1, 2, 400);
  for(auto it: v){
    cout << it << " ";
  }

  cout << "\n";

  // Insert one vector inside another vector. {300, 400, 400, 1, 5} -> {50, 50, 300, 400, 400, 1, 5}
  vector<int> copy(2,50);
  v.insert(v.begin(), copy.begin(), copy.end());
  for(auto it: v){
    cout << it << " ";
  }

  cout << "\n";

  // Finding the size of the vector
  cout << v.size(); // 7

  cout << "\n";

  // Pop Last Element -> {50, 50, 300, 400, 400, 1, 5} -> {50, 50, 300, 400, 400, 1}
  v.pop_back();
  for(auto it: v){
    cout << it << " ";
  }

  cout << "\n";

  // Swapping two vectors
  for(auto it: v3){
    cout << it << " ";
  }
   cout << "\n";
  for(auto it: v5){
    cout << it << " ";
  }
  
  cout << "\n";

  v3.swap(v5);

  for(auto it: v3){
    cout << it << " ";
  }
   cout << "\n";
  for(auto it: v5){
    cout << it << " ";
  }
  cout << "\n";

  //Erase entire vector
  v.clear();
  cout << v.empty(); // returns 1 
  cout << "\n";
  v.push_back(1);
  cout << v.empty(); // returns 0







  


  return 0;
}