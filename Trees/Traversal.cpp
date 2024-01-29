#include<bits/stdc++.h>
using namespace std;

class Node{
  public:
  int data;
  Node* left;
  Node* right;

  public:
  Node(int val){
    data = val;
    left = right = NULL;
  }
};

void preOrder(Node* root){
  if(root==NULL) return;

  cout << root->data;
  preOrder(root->left);
  preOrder(root->right);

}

void inOrder(Node* root){
  if(root==NULL) return;

  inOrder(root->left);
  cout << root->data;
  inOrder(root->right);

}

void postOrder(Node* root){
  if(root==NULL) return;

  inOrder(root->left);
  inOrder(root->right);
  cout << root->data;

}

int main(){
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);

  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(7);
  root->right->right = new Node(8);

  root->left->right->left = new Node(6); 
  root->right->right->left = new Node(9); 
  root->right->right->left = new Node(10); 

  preOrder(root); // TC and SC - O(N)
  cout << "\n";
  inOrder(root); // TC and SC - O(N)
  cout << "\n";
  postOrder(root); // TC and SC - O(N)
  cout << "\n";


  return 0;
}