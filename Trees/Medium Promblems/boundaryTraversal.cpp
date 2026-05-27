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

bool isLeaf(Node* node){
    return (node->left == NULL && node->right == NULL);
}

void addLeftBoundary(Node* root, vector<int> &res){
    Node* curr = root->left;
    while(curr){
        if(!isLeaf(curr)) res.push_back(curr->data);
        if(curr->left != NULL) curr = curr->left;
        else curr = curr->right;
    }
}

//MINE CHECK ONCE
void addLeadNod(Node* root, vector<int> &res){
    if(root == NULL) return;

    if(isLeaf(root)) res.push_back(root->data);

    addLeadNod(root->left,res);
    addLeadNod(root->right,res);
}

//striver
void addLeadNode(Node* root, vector<int> &res){

    if(isLeaf(root)){
        res.push_back(root->data);
        return;
    }

    if(root->left) addLeadNode(root->left,res);
    if(root->right) addLeadNode(root->right,res);
}

void addRightBoundary(Node* root, vector<int> &res){
    vector<int> temp;
    Node* curr = root->right;
    while(curr){
        if(!isLeaf(curr)) temp.push_back(curr->data);
        if(curr->right != NULL) curr = curr->right;
        else curr = curr->left;
    }

    for(int i=temp.size()-1;i>=0;i--){
        res.push_back(temp[i]);
    }
}


//TC -> O(H) + O(H) + O(N)  SC -> O(N)
vector<int> solution(Node* root){
    vector<int> res;
    if(root == NULL) return res;
    if(!isLeaf(root)) res.push_back(root->data);

    addLeftBoundary(root,res);
    addLeadNode(root,res);
    addRightBoundary(root,res);
    
    return res;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    vector<int> ans = solution(root);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
