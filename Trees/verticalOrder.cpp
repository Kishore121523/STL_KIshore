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

vector<vector<int>> verticalTraversal (Node* root){
        map<int, map<int, multiset<int>>> mpp;
        queue < pair < Node* , pair < int, int >>> q;
        vector<vector<int>> ans;

        if(root == NULL) return ans;

        q.push({root,{0,0}});

        while(!q.empty()){
            auto it  = q.front();
            q.pop();

            Node* node = it.first;
            int x = it.second.first;
            int y = it.second.second;

            mpp[x][y].insert(node->data );

            if(node->left){
                q.push({node->left,{x-1,y+1}});
            }
            if(node->right){
                q.push({node->right,{x+1,y+1}});
            }
        }

    for (auto p: mpp) {
        vector < int > col;
        for (auto q: p.second) {
        col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}



int main(){
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(2);

  root->left->left = new Node(3);
  root->left->right = new Node(4);
  root->right->left = new Node(4);
  root->right->right = new Node(3);

   vector<vector<int>> ans = verticalTraversal(root); // TC and SC = O(N)

   for(auto it: ans){
    for(auto i: it){
      cout << i << " ";
    }
   }
  return 0;
}