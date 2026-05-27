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

unordered_map<Node*,Node*> markParent(Node* root){
    queue<Node*> q;
    unordered_map<Node*,Node*> mpp;
    if(root == NULL) return mpp;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        for(int i=0;i<n;i++){
            Node* temp = q.front();
            q.pop();
            if(temp->left){
                mpp[temp->left] = temp;
                q.push(temp->left);
            }
            if(temp->right){
                mpp[temp->right] = temp;
                q.push(temp->right);
            }
        }
    }
    return mpp;
}

vector<int> solution(Node* root, Node* target, int k){
    vector<int> ans;
    unordered_map<Node*, Node*> mpp = markParent(root);
    unordered_map<Node*, bool> visited;
    queue<Node*> q;
    q.push(target);
    visited[target] = true;
    int dist = 0;
    while(!q.empty()){
        int n = q.size();
        if(dist == k) break;
        for(int i=0;i<n;i++){
            Node* temp = q.front();
            q.pop();
            if(temp->left && !visited[temp->left]){
                q.push(temp->left);
                visited[temp->left] = true;
            }
            if(temp->right && !visited[temp->right]){
                q.push(temp->right);
                visited[temp->right] = true;
            }
            if(mpp.count(temp) && !visited[mpp[temp]]){
                q.push(mpp[temp]);
                visited[mpp[temp]] = true;
            }
        }
        dist++;
    }
    while(!q.empty()){
        ans.push_back(q.front()->data);
        q.pop();
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
    root->left->right->left = new Node(12);
    root->left->right->right = new Node(13);
    vector<int> ans = solution(root,root->left,2);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
