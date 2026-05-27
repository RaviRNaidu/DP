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

Node* creatingTree(vector<int> &preOrder,int preSt,int preEnd, vector<int> &inOrder, 
                    int inSt, int inEnd, unordered_map<int, int> &mpp){
    if(preSt > preEnd || inSt > inEnd) return NULL;
    
    Node* root = new Node(preOrder[preSt]);
    int inIndx = mpp[preOrder[preSt]];
    int numLeft = inIndx - inSt;

    root->left = creatingTree(preOrder,preSt + 1,preSt + numLeft,inOrder,inSt,inIndx - 1,mpp);
    root->right = creatingTree(preOrder,preSt + numLeft + 1,preEnd, inOrder, inIndx + 1, inEnd,mpp);

    return root;
}

Node* constructTree(vector<int> &preOrder, vector<int> &inOrder){
    unordered_map<int, int> mpp;
    for(int i=0;i<inOrder.size();i++){
        mpp[inOrder[i]] = i;
    }

    int n = preOrder.size();
    Node* root = creatingTree(preOrder,0,n-1,inOrder,0,n-1,mpp);
    return root;
}

void display(Node* root){
    if(root != NULL){
        cout<<root->data<<" ";
        display(root->left);
        display(root->right);
    }
    return;
}

int main(){
    vector<int> preOrder = {3, 9, 20, 15, 7};
    vector<int> inOrder = {9, 3, 15, 20, 7};
    Node* root = constructTree(preOrder,inOrder);
    display(root);
    return 0;
}
