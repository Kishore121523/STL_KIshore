#include<bits/stdc++.h>
using namespace std;

class Node{
  public:
  int data;
  Node* left;
  Node* right;

  public:
  Node(int data){
    data = data;
    left = right = NULL;
  }

};

void preOrder(Node* root){


}

void inOrder(Node* root){


}

int main(){
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);

  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  root->right->right = new Node(7);

  // root->left->right->left = new Node(6); 
  // root->right->right->left = new Node(9); 
  // root->right->right->right = new Node(10); 

  preOrder(root); // TC and SC - O(N)
  cout << "\n";
  inOrder(root); // TC and SC - O(N)

  cout << "\n";


  return 0;
}