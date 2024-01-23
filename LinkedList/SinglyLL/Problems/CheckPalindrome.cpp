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

bool palindromNaive(Node* head){
        Node* temp = head;
        stack<int> st;

        while(temp){
            st.push(temp->data);
            temp = temp->next;
        }

        temp = head;

        while(temp){
            if(temp->data == st.top()){
                st.pop();
                temp = temp->next;
            }else{
                return false;
            }
        }
        return true;
}

Node* reverseLL(Node* head){
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

bool palindromOptimal(Node* head){
  Node* slow = head;
  Node* fast = head;

  while(fast->next && fast->next->next){
    slow = slow->next;
    fast = fast->next->next;
  }

  Node* newHead = reverseLL(slow->next);

 return true;
}




int main(){
  vector<int> arr = {1,2,3,3,2,1};
  Node* head = convertToLL(arr);
  Node* head2 = convertToLL(arr);

  cout << palindromNaive(head); // O(2N)

  cout << "\n";

  cout << palindromOptimal(head2); // O(N)

  return 0;

}