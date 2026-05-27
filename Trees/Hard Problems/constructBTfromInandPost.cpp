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

Node* creatingTree(vector<int> &postOrder,int postSt,int postEnd, vector<int> &inOrder, 
                    int inSt, int inEnd, unordered_map<int, int> &mpp){
    if(postSt > postEnd || inSt > inEnd) return NULL;
    
    Node* root = new Node(postOrder[postEnd]);
    int inIndx = mpp[postOrder[postEnd]];
    int numLeft = inIndx - inSt;

    root->left = creatingTree(postOrder,postSt,postSt + numLeft - 1,inOrder,inSt,inIndx - 1,mpp);
    root->right = creatingTree(postOrder,postSt + numLeft,postEnd - 1, inOrder, inIndx + 1, inEnd,mpp);

    return root;
}

Node* constructTree(vector<int> &postOrder, vector<int> &inOrder){
    if(postOrder.size() != inOrder.size()){
        return NULL;
    }
    unordered_map<int, int> mpp;
    for(int i=0;i<postOrder.size();i++){
        mpp[postOrder[i]] = i;
    }

    int n = postOrder.size();
    Node* root = creatingTree(postOrder,0,n-1,inOrder,0,n-1,mpp);
    return root;
}

void display(Node* root){
    if(root != NULL){
        display(root->left);
        display(root->right);
        cout<<root->data<<" ";
    }
    return;
}

int main(){
    vector<int> postOrder = {4, 5, 2, 6, 3, 1};
    vector<int> inOrder = {4, 2, 5, 1, 6, 3};
    Node* root = constructTree(postOrder,inOrder);
    display(root);
    return 0;
}
