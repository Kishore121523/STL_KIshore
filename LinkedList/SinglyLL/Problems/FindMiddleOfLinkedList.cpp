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

Node* findMiddleNaive(Node* head){
  if(head -> next == NULL) return head;

  Node* temp = head;
  int cnt = 0;

  while(temp){
    cnt++;
    temp = temp->next;
  }

  temp=head;

  for(int i=0;i<cnt/2; i++){
    temp = temp->next;
  }

  return temp;
}

Node* findMiddleOptimal(Node* head){
  if(head -> next == NULL) return head;

  //tortoise and hare algorithm
  Node* slow = head;
  Node* fast = head;

  while(fast && fast->next){
    slow = slow->next;
    fast = fast->next->next;

  }

  return slow;

}

void travereLL(Node* head){
  Node* temp = head;

  while(temp){
    cout << temp->data << " ";
    temp = temp->next;
  }
}


int main(){
  vector<int> arr = {2,5,6,7,9,10};
  Node* head = convertToLL(arr);
  Node* head2 = convertToLL(arr);

  head = findMiddleNaive(head);
  travereLL(head);

  cout << "\n";

  head2 = findMiddleOptimal(head2);
  travereLL(head2);

  return 0;

}