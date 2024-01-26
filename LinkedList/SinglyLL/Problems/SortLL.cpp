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

Node* sortLLNaive(Node* head){
  vector<int> arr;
  Node* temp = head;

  while(temp){
    arr.push_back(temp->data);
    temp = temp->next;
  }

  sort(arr.begin(),arr.end());
  temp = head;

  for(int i=0; i<arr.size(); i++){
    temp->data = arr[i];
    temp = temp->next;
  }

  return head;
}

Node* findMiddle(Node* head){
  Node* slow = head;
  Node* fast = head;
  Node* prevSlow = NULL;

  while(fast && fast->next){
    prevSlow = slow;
    slow = slow->next;
    fast = fast->next->next;
  }

  return prevSlow;
}

Node* merge2LL(Node* list1, Node* list2){
  Node* dummyNode = new Node(-1);
  Node* temp = dummyNode;

  while(list1 && list2){
    if(list1->data < list2->data){
      temp->next = list1;
      temp=list1;
      list1 = list1->next;
    }else{
      temp->next = list2;
      temp=list2;
      list2 = list2->next;
    }
  }
  if(list1) temp->next = list1;
  else temp->next = list2;

  return dummyNode->next;
}

Node* sortLLOptimal(Node* head){
  // using merge sort logic
  if(head==NULL||head->next==NULL) return head;

  Node* middle = findMiddle(head);
  Node* leftHead = head;
  Node* rightHead = middle->next;
  middle->next = NULL;

  leftHead = sortLLOptimal(leftHead);
  rightHead = sortLLOptimal(rightHead);

  head = merge2LL(leftHead, rightHead);

  return head;
}


int main(){
  vector<int> arr = {4,2,1,3};

  Node* head = convertToLL(arr);
  Node* head2 = convertToLL(arr);
  traverseLL(head);

  cout<<"\n";

  head = sortLLNaive(head); // TC is O(N+nlogn+N) and SC is O(N)
  traverseLL(head);
  cout<<"\n";

  head2 = sortLLOptimal(head); // O(NlogN) and O(1)
  traverseLL(head2);
  return 0;
}