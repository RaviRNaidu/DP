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

bool recursion(Node* root, long min, long max){
    if(root == NULL) return true;
    if(root->data <= min || root->data >= max) return false;
    return recursion(root->left, min, root->data) && recursion(root->right,root->data, max);
}

//TC -> O(N)    SC->O(1)
bool checking(Node* root){
    return recursion(root, LLONG_MIN, LLONG_MAX);
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(5);
    root->right = new Node(10);
    root->left->left = new Node(3);
    root->left->right = new Node(6);
    root->right->left = new Node(9);
    root->right->right = new Node(12);
    int ans = checking(root);
    cout<<ans<<endl;
    return 0;
}
