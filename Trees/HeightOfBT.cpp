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

int findHeight (Node* root){
  if(root == NULL) return 0;

  int lh = findHeight(root->left);
  int rh = findHeight(root->right);

  return 1+max(lh,rh);
}

int dfsHeight(Node* root){  
  // For every node, height(left) - height(right) <=1
  if(root == NULL) return 0;

  int lh = dfsHeight(root->left);
  if(lh==-1) return -1; // if anything returns  -1 then break
  int rh = dfsHeight(root->right);
  if(rh==-1) return -1; // if anything returns  -1 then break

  if(abs(lh-rh) > 1) return -1;

  return 1+max(lh,rh);
}

bool checkBalanced(Node* root){
  return dfsHeight(root)!=-1;
}

int main(){
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);

  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  root->right->right = new Node(7);

  cout << findHeight(root); // TC and SC - O(N)
  cout << "\n";
  cout << checkBalanced(root); // TC and SC - O(N) * O(N)
  cout << "\n";
} 