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
int maxDepth(Node* root){
    if(root == NULL) return 0;

    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);

    return 1 + max(lh,rh);
}

//TC -> O(N)*O(N) = O(N^2) cuz we need to calculate the height for each node
bool brute(Node* root){
    if(root == NULL) return true;

    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);

    if(abs(rh-lh) > 1) return false;

    bool left = brute(root->left);
    bool right = brute(root->right);

    if(!left || !right) return false;

    return true;
}











int check(Node* root){
    if(root == NULL) return 0;

    int lh = check(root->left);
    if(lh == -1) return -1;
    int rh = check(root->right);
    if(rh == -1) return -1;

    if(abs(lh-rh) > 1) return -1;
    return 1 + max(lh,rh);
}

//TC -> O(N)   SC -> O(N)
bool optimal(Node* root){
    int val = check(root);
    if(val != -1){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->right->left = new Node(7);
    int ans = optimal(root);
    cout<<ans;
    return 0;
}
