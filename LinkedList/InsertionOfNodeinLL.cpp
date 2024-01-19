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

void travereLL(Node* head){
  // Traversing LL
  Node* temp = head;
  while(temp){
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << "\n";
}

Node* convertToLL(vector<int> &arr){
  Node* head = new Node(arr[0]);
  Node* mover = head;

  for(int i=1; i<arr.size(); i++){
    Node* temp = new Node(arr[i]);
    mover->next = temp;
    mover = temp;
  }

  return head;
}

Node* insertInHead(Node* head, int val){
  Node* newHead = new Node(val);
  newHead->next = head;

  return newHead;
}

Node* insertInTail(Node* head, int val){
  if(head == NULL) return new Node(val);
  Node* temp = head;

  //Stop at last index
  while(temp->next != NULL){
      temp = temp->next;
  }
  Node* newLast = new Node(val);
  temp->next = newLast;

  return head;
}
int main(){
  vector<int> arr = {2,5,6,7};
  Node* head = convertToLL(arr);

  // Prints all the elements in the LL
  travereLL(head);

  // Inserting a new node in head
  int val1 = 5;
  head = insertInHead(head, val1);
  travereLL(head);

  // Inserting a new node in head
  int val2 = 15;
  head = insertInTail(head, val2);
  travereLL(head);



  return 0;

}