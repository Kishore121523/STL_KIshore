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

int maxPath(Node* node, int &maxi){
if(node == NULL) return 0;

  int lh = max(0, maxPath(node->left,maxi));
  int rh = max(0,maxPath(node->right,maxi));

  maxi = max(maxi, lh+rh+node->data);

  return (node->data) + max(lh,rh);
}

int maximumPathSumOptimal (Node* root){
  // Longest path between any 2 nodes and the path need not necessarily pass through root
  int maxi = INT_MIN;
  maxPath(root, maxi);
  return maxi;
}


int main(){
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);

  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  root->right->right = new Node(7);

  cout << maximumPathSumOptimal(root);
  cout << "\n";
  
} 