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

void markParent(Node* root, unordered_map<Node*, Node*> &mpp){
    queue<Node*> q;
    if (root == NULL) return;
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
}

//striver
Node* markParentStriver(Node* root, unordered_map<Node*, Node*> &mpp, int start){
    queue<Node*> q;
    Node* target = NULL;
    if (root == NULL) return NULL;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp->data == start){
            target = temp;
        }
        if(temp->left){
            mpp[temp->left] = temp;
            q.push(temp->left);
        }
        if(temp->right){
            mpp[temp->right] = temp;
            q.push(temp->right);
        }
    }
    return target;
}

Node* findingNode(Node* root, int start){
    if(root == NULL) return NULL;

    if(root->data == start){
        return root;
    }
    Node* l = findingNode(root->left,start);
    if(l) return l;
    return findingNode(root->right,start);
}


//TC -> O(N) + O(N) THIS IS IF U FIND THE START NODE WHILE MARKING PARENT. IF NOT O(N) WILL BE ADDED
//SC -> O(N) IF U WANT INCLUDE THE QUEUE N ALL
int solution(Node* root, int start){
    Node* stPoint = findingNode(root, start);
    if(stPoint == NULL) return 0;
    unordered_map<Node*, Node*> parentPt;
    markParent(root,parentPt);
    unordered_map<Node*, bool> visited;
    queue<Node*> q;
    q.push(stPoint);
    visited[stPoint] = true;
    int time = 0;
    while(!q.empty()){
        int n = q.size();
        bool flag = false;
        for(int i=0;i<n;i++){
            Node* temp = q.front();
            q.pop();
            if(temp->left && !visited[temp->left]){
                q.push(temp->left);
                visited[temp->left] = true;
                flag = true;
            }
            if(temp->right && !visited[temp->right]){
                q.push(temp->right);
                visited[temp->right] = true;
                flag = true;
            }
            if(parentPt.count(temp) && !visited[parentPt[temp]]){
                q.push(parentPt[temp]);
                visited[parentPt[temp]] = true;
                flag = true;
            }
        }
        if(flag)time++;
    }
    return time;
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
    int ans = solution(root,5);
    cout<<ans<<endl;
    return 0;
}
