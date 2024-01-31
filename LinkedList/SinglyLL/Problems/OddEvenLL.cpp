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

Node* oddEvenNaive(Node* head){
  if(head == NULL ||head->next==NULL) return head;
  
  Node* temp = head;
  vector<int> arr;

  while(temp && temp->next){
    arr.push_back(temp->data);
    temp = temp->next->next;
  }

  if(temp){
    arr.push_back(temp->data);
  }

  temp = head->next;

  while(temp && temp->next){
    arr.push_back(temp->data);
    temp = temp->next->next;
  }

  if(temp){
    arr.push_back(temp->data);
  }

  int i = 0;
  temp = head;

  while(temp){
    temp->data = arr[i];
    i++;
    temp = temp->next;
  }

  return head;
  
}

Node* oddEvenOptimal(Node* head){
  if(head == NULL ||head->next==NULL) return head;
  
  Node* tempOdd = head;
  Node* tempEven = head->next;
  Node* secondNode = head->next;

  while(tempEven && tempEven->next){
    tempOdd->next = tempOdd->next->next;
    tempOdd = tempOdd->next;
    tempEven->next = tempEven->next->next;
    tempEven = tempEven->next;
  }

  // This is to link last node of ODD to first node of EVEN
  tempOdd->next = secondNode;

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
  vector<int> arr = {1,2,3,4,5};
  Node* head = convertToLL(arr);
  Node* head2 = convertToLL(arr);

  head = oddEvenNaive(head); // O(2N)
  traverseLL(head);

  cout << "\n";

  head2 = oddEvenOptimal(head2); // O(N)
  traverseLL(head2);

  return 0;

}