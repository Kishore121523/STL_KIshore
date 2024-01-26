#include<bits/stdc++.h>

using namespace std;

class Node{
  public:
  int data;
  Node* next;

  public:
  Node(int data1, Node* next1){
    data = data1;
    next = next1;
  }

  public:
  Node(int data1){
    data = data1;
    next = nullptr;
  }
};

Node* convertToLL(vector<int> &arr){
  Node* head = new Node(arr[0]);
  Node* mover = head;

  for(int i=1; i<arr.size(); i++){
    Node* newNode = new Node(arr[i]);
    mover->next = newNode;
    mover = newNode;
  }

  return head;
}

void traverseLL(Node* head){
  Node* temp = head;

  while(temp){
    cout << temp->data << " ";
    temp = temp->next;                                                       
  }
}
int main(){
  vector<int> arr = {4,2,1,3};
  Node* head = convertToLL(arr);

  traverseLL(head);
  return 0;
}