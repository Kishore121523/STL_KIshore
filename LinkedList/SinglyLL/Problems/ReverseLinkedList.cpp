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

Node* reverseLLNaive(Node* head){
 Node* temp = head;
  stack<int> st;

  while(temp){
    st.push(temp->data);
    temp = temp->next;
  }

  temp = head;
  while(temp){
    temp->data = st.top();
    st.pop();
    temp = temp->next;
  }

  return head;
}

Node* reverseLLOptimal(Node* head){
  Node* temp = head;
  Node* prev = NULL;

  while(temp){
    Node* front = temp->next;
    temp->next = prev;
    prev = temp;
    temp = front;
  }

  return prev;
  
}

void traverseLL(Node* head){
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

  head = reverseLLNaive(head); // O(2N)
  traverseLL(head);

  cout << "\n";

  head2 = reverseLLOptimal(head2); // O(N)
  traverseLL(head2);

  return 0;

}