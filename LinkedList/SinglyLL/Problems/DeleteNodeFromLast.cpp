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


Node* deleteFromLast(Node* head, int n){
   if(head == NULL) return head;
        if(head->next == NULL && n>0) return NULL;

        int cnt = 0;
        Node* temp = head;

        while(temp){
            cnt++;
            temp = temp->next;
        }

        if(cnt==n){
          Node* newHead = head->next;
          return newHead;
        }

        int res = (cnt - n);
        temp = head;

        while(temp){
            res--;
            if(res == 0){
              break;
            }
            temp = temp->next;
        }

        Node* delNode = temp;
        temp->next = temp->next->next;
        free(delNode);

        return head;
}

Node* deleteFromLastOptimal(Node* head, int n){
    if(head == NULL) return head;
    if(head->next == NULL && n>0) return NULL;

    Node* fast = head;

    for(int i=0; i<n; i++){
      fast=fast->next;
    }

    Node* slow = head;

     if(fast == NULL){
      return head->next;
    }

    while(fast->next){
      slow = slow->next;
      fast = fast->next;
    }

   

    slow->next = slow->next->next;
    

    return head;
}

int main(){
  vector<int> arr = {1,2};
  Node* head = convertToLL(arr);
  Node* head2 = convertToLL(arr);

  // Prints all the elements in the LL
  travereLL(head);

  //delete kth element
  int val = 2;
  head = deleteFromLast(head,val); //TC = O(2*len(N))
  travereLL(head);

  //delete kth element
  val = 2;
  head = deleteFromLastOptimal(head2,val); // O(len)
  travereLL(head);

  return 0;

}