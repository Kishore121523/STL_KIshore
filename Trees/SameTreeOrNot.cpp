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

bool sameTreeOrNot(Node* root,Node* root2){
  if(root==NULL||root2==NULL){
    return root==root2;
  }

  return (root->data == root2->data) && sameTreeOrNot(root->left, root2->left) && sameTreeOrNot(root->right, root2->right);
}

// Same tree or Not check code
int main(){
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);

  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  root->right->right = new Node(7);

  Node* root2 = new Node(1);
  root2->left = new Node(2);
  root2->right = new Node(3);

  root2->left->left = new Node(4);
  root2->left->right = new Node(5);
  root2->right->left = new Node(6);
  root2->right->right = new Node(7);

  cout << sameTreeOrNot(root,root2);// TC = O(N)
  cout << "\n";
  
} 

