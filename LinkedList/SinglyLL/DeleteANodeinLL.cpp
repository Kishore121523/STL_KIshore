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

Node* deleteTail(Node* head){
  if(head==NULL || head->next == NULL) return NULL;
  Node* temp = head;
  while(temp->next->next != NULL){
    temp = temp->next;
  }
  free(temp->next);
  temp->next = NULL;
  return head;

}

Node* deleteKthElement(Node* head, int k){
  if(head == NULL) return NULL;
  if(k==1){
    head = head->next;
    return head;
  }

  int cnt = 0;
  Node* temp = head;
  Node* prev = NULL;

  while(temp != NULL){
    cnt++;
    if(cnt==k){
      prev->next = prev->next->next;
      free(temp);
      return head;
    }
    prev = temp;
    temp = temp->next;
  }
}

int main(){
  vector<int> arr = {2,5,6,7,8,9};
  Node* head = convertToLL(arr);

  // Prints all the elements in the LL
  travereLL(head);

  // Deleting head node
  head = deleteHead(head);
  travereLL(head);

  //deleteTail
  head = deleteTail(head);
  travereLL(head);

  //delete kth element
  int val = 3;
  head = deleteKthElement(head,val);
  travereLL(head);


  return 0;

}