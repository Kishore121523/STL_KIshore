#include<bits/stdc++.h>

using namespace std;

class Node{
  public:
  int data;
  Node* next;

  // constructor - special type of member function which is called when a new object is created
  public:
  Node(int data1, Node* next1){
    data = data1;
    next = next1;
  }
};


int main(){
  vector<int> arr = {2,5,6,7};
  Node* y = new Node(arr[0], nullptr); // "new" keyword gives the pointer to the memory location 
  cout << y << "\n"; // 0x148e06100 - prints the memory location
  cout << y->data << "\n"; // 2
  cout << y->next << "\n"; // 0x0

  Node y1 = Node(arr[0], nullptr); // without "new" keyword it just creates an object
  cout << y1.data << "\n"; // 2
  cout << y1.next << "\n"; // 0x0
  return 0;
}