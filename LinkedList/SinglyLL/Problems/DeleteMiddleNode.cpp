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


Node* deleteMiddleElementOptimal(Node* head){
        if(head -> next == NULL) return NULL;

        Node* slow = head;
        Node* fast = head;
        Node* prevSlow = head;

         while(fast && fast->next){
            prevSlow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prevSlow->next = slow->next;

        return head;
}

int main(){
  vector<int> arr = {1,3,4,7,1,2,6};
  Node* head = convertToLL(arr);

  // Prints all the elements in the LL
  travereLL(head);

  head = deleteMiddleElementOptimal(head); // O(len)
  travereLL(head);

  return 0;

}