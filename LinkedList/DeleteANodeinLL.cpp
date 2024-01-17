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

Node* deleteHead(Node* head){
  if(head==NULL) return head;
  Node* temp = head;
  head = head->next;
  free(temp);
  return head;
}

int main(){
  vector<int> arr = {2,5,6,7};
  Node* head = convertToLL(arr);

  // Prints all the elements in the LL
  travereLL(head);

  // Deleting head node
  head = deleteHead(head);
  travereLL(head);


  return 0;

}