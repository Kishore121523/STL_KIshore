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

int height(Node* node, int &diameter){
if(node == NULL) return 0;

  int lh = height(node->left,diameter);
  int rh = height(node->right,diameter);

  diameter = max(diameter,lh+rh);

  return 1+max(lh,rh);
}

int maximumPathSumOptimal (Node* root, int maxi){
  // Longest path between any 2 nodes and the path need not necessarily pass through root
  int diameter = 0;
  height(root, diameter);
  return diameter;
}


int main(){
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);

  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  root->right->right = new Node(7);

  cout << maximumPathSumOptimal(root,0); // TC - O(N^2)
  cout << "\n";
  
} 