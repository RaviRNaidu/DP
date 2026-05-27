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

//TC -> o(n)    sc-> o(n) if its a skew tree
int maxDepth(Node* root,int& diameter){
    if(root == NULL) return 0;

    int lh = maxDepth(root->left,diameter);
    int rh = maxDepth(root->right,diameter);

    diameter = max(diameter,lh+rh);

    return 1 + max(lh,rh);
}

//TC -> O(N)    SC->O(N)
int optimal(Node* root){
    int diameter = 0;

    maxDepth(root, diameter);
    return diameter;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    int ans = optimal(root);
    cout<<ans;
    return 0;
}
