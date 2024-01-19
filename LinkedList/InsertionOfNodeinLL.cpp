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

Node* insertAtK(Node* head, int k, int val3){
  if(head==NULL){
    if(k==1){ 
      Node* newHead = new Node(val3);
      return newHead;
    }else{
      return head;
    }
  }

  if(k==1){
    Node* newHead = new Node(val3);
    newHead->next = head;
    return newHead;
  }

  Node* temp = head;
  int cnt = 0;

  while(temp != NULL){
    cnt++;
    if(cnt == k-1){
      Node* newNode = new Node(val3);
      newNode->next = temp->next;
      temp->next = newNode;
      break;
    }
    temp = temp->next;
  }

  return head;
}

Node* insertEleBeforeEle(Node* head, int ele, int val4){
  if(head==NULL) return NULL;

  if(head->data == val4){
    Node* newHead = new Node(ele);
    newHead->next = head;
    return newHead;
  }

  Node* temp = head;
  while(temp->next != NULL){
    if(temp->next->data == val4){
      Node* newEle = new Node(ele);
      newEle->next = temp->next;
      temp->next = newEle;
      break;
    }
  temp = temp->next;
  }
  return head;
}


int main(){
  vector<int> arr = {2,5,6,7};
  Node* head = convertToLL(arr);

  // Prints all the elements in the LL
  travereLL(head);

  // Inserting a new node in head
  int val1 = 25;
  head = insertInHead(head, val1);
  travereLL(head);

  // Inserting a new node to tail
  int val2 = 15;
  head = insertInTail(head, val2);
  travereLL(head);

  // Inserting a new node at kth position
  int k = 4, val3 = 22;
  head = insertAtK(head, k, val3);
  travereLL(head);

  // Inserting ele before val4
  int ele = 4, val4 = 25;
  head = insertEleBeforeEle(head, ele, val4);
  travereLL(head);





  return 0;

}