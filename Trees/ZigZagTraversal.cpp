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
    vector<int> row;

    for(int i=0; i<size;i++){
      Node* newNode = nodesQueue.front();
      nodesQueue.pop();

      int indexToInsert = (leftToRight) ? i : (size-1-i);

      row[indexToInsert] = newNode->data;

      if(newNode->left != NULL) nodesQueue.push(newNode->left);
      if(newNode->right != NULL) nodesQueue.push(newNode->right);
      row.push_back(newNode->data);
    }

    leftToRight = !leftToRight;
     for(auto it2: row){
      cout << it2 << " ";
    }
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

  // for(auto it: res){
  //   for(auto it2: it){
  //     cout << it2 << " ";
  //   }
  // }

  return 0;
}