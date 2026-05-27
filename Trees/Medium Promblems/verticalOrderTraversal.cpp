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

    public:
    Node(int data1, Node* left1, Node* right1){
        data = data1;
        left = left1;
        right = right1;
    }
};

//TC -> O(N * LOG N) SC -> O(3N)
vector<vector<int>> vertical(Node* root){
    vector<vector<int>> ans;
    if(root == NULL) return ans;
    queue<pair<Node*,pair<int,int>>> q;
    map<int,map<int,multiset<int>>> mpp;
    q.push({root,{0,0}});
    while(!q.empty()){
        Node* temp = q.front().first;
        int vertical = q.front().second.first;
        int level = q.front().second.second;
        q.pop();
        mpp[vertical][level].insert(temp->data);
        if(temp->left != NULL) q.push({temp->left,{vertical-1,level+1}});
        if(temp->right != NULL) q.push({temp->right,{vertical+1,level+1}});
    }
    for(auto it : mpp){
        vector<int> col;
        for(auto i : it.second){
            col.insert(col.end(),i.second.begin(),i.second.end());
        }
        ans.push_back(col);
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
    vector<vector<int>> ans = vertical(root);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
