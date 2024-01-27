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


Node* add2LL(Node* l1, Node* l2){
  Node* dummy = new Node(-1);
  Node* curr = dummy;

  Node* t1= l1;
  Node* t2 = l2;

  int carry = 0;
  int sum = 0;

  while(t1 || t2){
    sum = carry;
    if(t1) sum+= t1->data;
    if(t2) sum+= t2->data;

    Node* newNode = new Node(sum%10);
    carry = sum/10;

    curr->next = newNode;
    curr = newNode;

    if(t1) t1 = t1->next;
    if(t2) t2 = t2->next;

  }

  if(carry){
    Node* newNode1 = new Node(carry);
    curr->next = newNode1;

  }

  return dummy->next;
}

int main(){
  vector<int> arr = {3,5,7};
  vector<int> arr2 = {5,2,4};
  Node* l1 = convertToLL(arr);
  Node* l2 = convertToLL(arr2);;

  Node* head = add2LL(l1,l2); // O(max(n1,n2))
  travereLL(head);

  return 0;

}