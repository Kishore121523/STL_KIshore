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

Node* getLCA(Node* root, Node* p, Node* q){
  if(root == NULL || root == p || root == q){
    return root;
  }

  Node* left = getLCA(root->left,p,q);
  Node* right = getLCA(root->right,p,q);

  if(left == NULL){
    return right;
  }
  else if(right == NULL){
    return left;
  }
  else {
    return root;
  }
  
}



int main(){
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);

  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  root->right->right = new Node(7);

  Node* ans = getLCA(root, root->left->left , root->right->right); // TC and SC = O(N)
  cout << ans->data;

  return 0;
}