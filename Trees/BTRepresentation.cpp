#include<bits/stdc++.h>
using namespace std;

// Creating a class called as Node which acts a user defined variable for creating the structure of the tree
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

int main(){
  Node* root = new Node(1);
  root->left = new Node(1);
  root->right = new Node(3);

  root->left->right = new Node(5);

  return 0;
}