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

void preOrder(Node* root){
  if(root==NULL) return;

  cout << root->data;
  preOrder(root->left);
  preOrder(root->right);

}

void inOrder(Node* root){
  if(root==NULL) return;

  inOrder(root->left);
  cout << root->data;
  inOrder(root->right);

}

void postOrder(Node* root){
  if(root==NULL) return;

  inOrder(root->left);
  inOrder(root->right);
  cout << root->data;

}

vector<vector<int>> levelOrder(Node* root){
  vector<vector<int>> ans;
  if(root == NULL) return ans;
  queue<Node*> q;

  q.push(root);

  while(!q.empty()){
    int size = q.size();
    vector<int> level;

    for(int i=0;i<size;i++){
      Node* node = q.front();
      q.pop();
      if(node->left != NULL) q.push(node->left);
      if(node->right != NULL) q.push(node->right);
      level.push_back(node->data);
    }
    ans.push_back(level);
  }
  return ans;
}

void isBalanced(Node* root) {
        int numberOfNodes = 0;

        vector<vector<int>> ans;

        if(root==NULL) cout << "True";

        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            vector<int> level;
            int size = q.size();
            
            for(int i=0;i<size; i++){
                Node* node = q.front();
                q.pop();
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
                level.push_back(node->data);
                numberOfNodes+=1;
            }
            ans.push_back(level);
        }

        int levelNum = ans.size();

        cout << levelNum;
        cout << "\n";
        cout << numberOfNodes;
        cout << "\n";
        cout << ceil(log2(numberOfNodes)+1);
        cout << "\n";
        if(levelNum <= floor(log2(numberOfNodes)+1)) cout << "True";
        else cout << "False";
}

int main(){
  Node* root = new Node(3);
  root->left = new Node(9);
  root->right = new Node(20);

  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  // root->right->right = new Node();
  root->right->left->left = new Node(8);

  // root->left->right->left = new Node(6); 
  // root->right->right->left = new Node(9); 
  // root->right->right->right = new Node(10); 

  preOrder(root); // TC and SC - O(N)
  cout << "\n";
  inOrder(root); // TC and SC - O(N)
  cout << "\n";
  postOrder(root); // TC and SC - O(N)
  cout << "\n";

  vector<vector<int>> ans;
  ans = levelOrder(root); // TC and SC - O(N)
  for(auto it: ans){
    for(auto its: it){
      cout << its;
    }
  }
  cout << "\n";

  isBalanced(root);


  return 0;
}