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

vector<vector<int>> zigZag(Node* root){
  vector<vector<int>> result;
  if(root == NULL){
    return result;
  }

  queue<Node*> nodesQueue;
  nodesQueue.push(root);

  bool leftToRight = true;

  while(!nodesQueue.empty()){
    int size = nodesQueue.size();
    vector<int> row(size);

    // traversing all the nodes in a specific level of the tree
    for(int i=0; i<size;i++){
      // Create a new Node and assign it with the front element
      Node* newNode = nodesQueue.front();
      nodesQueue.pop();

      // If lefttoRight is true then add the element from front else add the element from back in reverse order
      int indexToInsert = (leftToRight) ? i : (size-1-i);

      row[indexToInsert] = newNode->data;

      // Push the current nodes children nodes if any to the queue
      if(newNode->left != NULL) nodesQueue.push(newNode->left);
      if(newNode->right != NULL) nodesQueue.push(newNode->right);
    }

    // After a level is completed, switch the leftToRight bool value accordingly
    leftToRight = !leftToRight;
    result.push_back(row);
  }

return result;
}



int main(){
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);

  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  root->right->right = new Node(7);

  vector<vector<int>> res = zigZag(root); // TC and SC - O(N)

  for(auto it: res){
    for(auto it2: it){
      cout << it2 << " ";
    }
  }

  return 0;
}