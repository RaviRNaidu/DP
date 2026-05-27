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

//TC -> O(N) SC -> O(N)
//DONE BY ME
vector<vector<int>> zigZag(Node* root){
    vector<vector<int>> ans;
    if(root == NULL) return ans;
    int flag = 0;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        vector<int> zig;
        for(int i=0;i<n;i++){
            Node* temp = q.front();
            q.pop();
            if(temp->left != NULL) q.push(temp->left);
            if(temp->right != NULL) q.push(temp->right);
            zig.push_back(temp->data);
        }
        if(flag == 0){
            ans.push_back(zig);
            flag = 1;
        }
        else{
            reverse(zig.begin(),zig.end());
            ans.push_back(zig);
            flag = 0;
        }
    }
    return ans;
}

//TC -> O(N) SC -> O(N)
vector<vector<int>> striver(Node* root){
    vector<vector<int>> ans;
    if(root == NULL) return ans;
    bool leftToRight = true;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        vector<int> zig(n);
        for(int i=0;i<n;i++){
            Node* temp = q.front();
            q.pop();

            int index = (leftToRight) ? i : (n - i - 1);

            zig[index] = temp->data;

            if(temp->left != NULL) q.push(temp->left);
            if(temp->right != NULL) q.push(temp->right);
        }
        leftToRight = !leftToRight;
        ans.push_back(zig);
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
    vector<vector<int>> ans = striver(root);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
