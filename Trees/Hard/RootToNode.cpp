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

bool getPath (Node* root, vector<int> &arr, int x){
  if(!root) return false;

  arr.push_back(root->data);

  if(root->data == x) return true;
  // Iterate recursively through the entire tree until you find the x
  // If the node's data matches x, then return true and end the recursion
  if(getPath(root->left,arr,x) || getPath(root->right,arr,x)) return true;
  
  arr.pop_back();
  
  return false;
}



int main(){
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);

  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  root->right->right = new Node(7);

  int node = 4;
  vector<int> arr;

  getPath(root,arr,node); // TC and SC = O(N)

  for(auto it: arr){
      cout << it << " ";
  }
  return 0;
}