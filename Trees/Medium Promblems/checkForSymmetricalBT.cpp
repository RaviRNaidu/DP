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

bool checking(Node* r1, Node* r2){
    if(r1 == NULL || r2 == NULL){
        return (r1 == r2);
    }

    if(r1->data != r2->data){
        return false;
    }

    return checking(r1->left,r2->right) && checking(r1 ->right,r2->left);
}

bool solution(Node* root){
    if(root == NULL) return true;
    return checking(root->left,root->right);
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    // root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(5);
    // root->right->right = new Node(5);
    int ans = solution(root);
    cout<<ans<<endl;
    return 0;
}
