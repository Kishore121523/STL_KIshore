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



int main(){
  Node* root = new Node(1);
  root->left = new Node(1);
  root->right = new Node(3);

  root->left->right = new Node(5);

  return 0;
}