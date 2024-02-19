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

vector<int> topView(Node* root){
  //create a vector to store the answer
  vector<int> ans;
  if(root==NULL) return ans;

  // create a map and a queue data structures
  queue<pair<Node*, int>> q;
  map<int, int> mpp;

  // push the initial root node to the queue and the initial line number will be 0
  q.push({root,0});

  // iterate through each level of the tree
  while(!q.empty()){
    auto it = q.front();
    q.pop();

    // storing the node and the line number in seperate variables
    Node* node = it.first;
    int line = it.second;

    // pushing it into the map if the line is not available before in the map
    if(mpp.find(line) == mpp.end()) mpp[line] = node->data;
    
    // if left/right node is present push it to the queue
    if(node->left!=NULL){
      q.push({node->left, line-1});
    }
    if(node->right!=NULL){
      q.push({node->right, line+1});
    }
  }

  for(auto it: mpp){
    ans.push_back(it.second);
  }

  return ans;
}

vector<int> bottomView(Node* root){
  vector<int> ans;
  if(root==NULL) return ans;

  // create a queue and map
  queue<pair<Node*, int>> q;
  map<int, int> mpp;

  q.push({root,0});

  while(!q.empty()){
    auto it = q.front();
    q.pop();

    Node* node = it.first;
    int line = it.second;

    // if the same line sees another value when going further down in the tree, REPLACE that value for that line so we get the bottom most value in that line
    mpp[line] = node->data;

    if(node->left != NULL){
      q.push({node->left,line-1});
    }
    if(node->right != NULL){
      q.push({node->right,line+1});
    }
  }

   for(auto it: mpp){
    ans.push_back(it.second);
  }

  return ans;
}

int main(){
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);

  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  root->right->right = new Node(7);

  vector<int> topViewAns = topView(root); // TC and SC - O(N)

    for(auto it2: topViewAns){
      cout << it2 << " ";
    }

    cout << "\n";

    vector<int> bottomViewAns = bottomView(root); // TC and SC - O(N)

    for(auto it2: bottomViewAns){
      cout << it2 << " ";
    }

  return 0;
}