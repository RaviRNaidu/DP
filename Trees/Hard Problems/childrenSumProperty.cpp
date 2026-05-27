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

//TC -> O(N)    SC -> O(H)
void striver(Node* root){
    if(root == NULL){
        return;
    }
    int child = 0;
    if(root->left != NULL){
        child += root->left->data;
    }
    if(root->right != NULL){
        child += root->right->data;
    }
    if(root->data > child){
        if(root->left){
            root->left->data = root->data;
        }
        else if(root->right){
            root->right->data = root->data;
        }
    }
    else{
        root->data = child;
    }

    striver(root->left);
    striver(root->right);

    int total = 0;
    if(root->left) total += root->left->data;
    if(root->right) total += root->right->data;
    if(root->left || root->right) root->data = total;
    return;
}

//TC -> O(N)    SC -> O(N)
void solution(Node* root){
    if(root->left == NULL || root->right == NULL){
        return;
    }
    int left = root->left->data;
    int right = root->right->data;
    if(root->data > (left + right)){
        root->left->data = root->data;
        root->right->data = root->data;
    }
    else{
        root->data = left + right;
    }
    solution(root->left);
    solution(root->right);
    left = root->left->data;
    right = root->right->data;
    root->data = left + right;
    return;
}

void display(Node* root){
    if(root != NULL){
        display(root->left);
        cout<<root->data<<" ";
        display(root->right);
    }
}

int main(){
    Node* root = new Node(50);
    root->left = new Node(7);
    root->right = new Node(8);
    root->left->left = new Node(25);
    root->left->right = new Node(12);
    root->right->left = new Node(9);
    root->right->right = new Node(3);
    striver(root);
    display(root);
    return 0;
}
