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

//TC -> O(log n) or O(H) cuz height is log n in BST
Node* search(Node* root, int n){
    while(root != NULL){
        if(root->data == n){
            return root;
        }
        else if(root->data < n){
            root = root->right;
        }
        else{
            root = root->left;
        }
    }
    return root;
}

Node* striver(Node* root, int n){
    while(root != NULL && root->data != n){
        root = n < root->data ? root->left : root->right; 
    }
    return root;
}

int main(){
    Node* root = new Node(8);
    root->left = new Node(5);
    root->right = new Node(12);
    root->left->left = new Node(4);
    root->left->right = new Node(7);
    root->right->left = new Node(10);
    root->right->right = new Node(14);
    root->left->right->left = new Node(6);
    root->right->right->left = new Node(13);
    Node* ans = striver(root,6);
    cout<<ans->data<<endl;
    return 0;
}
