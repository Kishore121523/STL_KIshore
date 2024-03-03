#include<bits/stdc++.h>

using namespace std;

class Node{
  public:
  int data;
  Node* left;
  Node* right;

  public:
  Node(int data1){
    data = data1;
    left = right = NULL;
  }

};

bool isSymmentricFoo(Node* left, Node* right){
  if(left == NULL || right == NULL) return left==right;
  if(left->data != right->data) return false;

  //Move left and right simulataneously
  return isSymmentricFoo(left->left, right->right) && isSymmentricFoo(left->right, right->left); 
}

bool isSymmentric(Node* root){
  return root==NULL || isSymmentricFoo(root->left, root->right);
}


int main(){
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(2);

  root->left->left = new Node(3);
  root->left->right = new Node(4);
  root->right->left = new Node(4);
  root->right->right = new Node(3);

  cout << isSymmentric(root); // TC and SC = O(N)
  return 0;
}