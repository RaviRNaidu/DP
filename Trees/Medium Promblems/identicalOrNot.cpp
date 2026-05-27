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
bool striver(Node* p,Node* q){
    if(p == NULL || q == NULL){
        return (p == q);
    }

    return (p->data == q->data) && striver(p->left,q->left) && striver(p->right,q->right);
}

bool solution(Node* p, Node* q){
    if(p == NULL || q == NULL){
        return (p == q);
    }

    if(p->data != q->data) return false;

    return solution(p->left,q->left) && solution(p->right,q->right);
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    int ans = solution(root,root);
    cout<<ans;
    return 0;
}
