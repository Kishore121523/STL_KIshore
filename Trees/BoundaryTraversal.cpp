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

bool isLeaf(Node* root){
  if(!root->left && !root->right) return true;
  else return false;
}

void addLeftBoundary(Node* root, vector<int> &res){
  Node* cur = root->left;
  while(cur){
    if(!isLeaf(cur)) res.push_back(cur->data);
    if(cur->left) cur = cur->left;
    else cur = cur->right;
  }
}

void addRightBoundary(Node* root, vector<int> &res){
  Node* cur = root->right;
  vector<int> temp;
  while(cur){
    if(!isLeaf(cur)) temp.push_back(cur->data);
    if(cur->right) cur = cur->right;
    else cur = cur->left;
  }

  for(int i=temp.size(); i>=0; i--){
    res.push_back(temp[i]);
  }

}

void addLeaves(Node* root, vector<int> &res){
  if(isLeaf(root)){
    res.push_back(root->data);
    return;
  }
  if(root->left) addLeaves(root->left, res);
  if(root->right) addLeaves(root->right, res);
}



vector<int> boundaryTraversal(Node* root){
  // left boundary traversal without leaf - leaf - right boundary traversal without leaf
  vector<int> res;
  if(!root) return res;
  if(!isLeaf(root)) res.push_back(root->data);
  addLeftBoundary(root,res);
  addLeaves(root,res);
  addRightBoundary(root,res);
  return res;
  
}



int main(){
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);

  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  root->right->right = new Node(7);

  vector<int> res = boundaryTraversal(root); // TC and SC - O(N)

  for(auto it: res){
    cout << it << " ";
  }

  return 0;
}