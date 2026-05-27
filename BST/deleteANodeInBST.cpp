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

Node* findLastRight(Node* root){
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}

Node* healper(Node* root){
    if(root->left == NULL){
        return root->right;
    }
    else if(root->right == NULL){
        return root->left;
    }
    Node* rightchild = root->right;
    Node* leftRight = findLastRight(root->left);
    leftRight->right = rightchild;
    return root->left;
}

Node* deleteNode(Node* root, int el){
    if(root == NULL) return NULL;
    if(root->data == el){
        return healper(root);
    }
    Node* curr = root;
    while(curr != NULL){
        if(curr->data > el){
            if(curr->left != NULL && curr->left->data == el){
                curr->left = healper(curr->left);
                break;
            }
            else{
                curr = curr->left;
            }
        }
        else{
            if(curr->right != NULL && curr->right->data == el){
                curr->right = healper(curr->right);
                break;
            }
            else{
                curr = curr->right;
            }
        }
    }
    return root;
}

void display(Node* root){
    if(root != NULL){
        cout<<root->data<<" ";
        display(root->left);
        display(root->right);
    }
}

int main(){
    Node* root = new Node(8);
    root->left = new Node(5);
    root->right = new Node(12);
    root->left->left = new Node(2);
    root->left->right = new Node(7);
    root->right->left = new Node(10);
    root->right->right = new Node(13);
    root->left->left->left = new Node(1);
    root->left->left->right = new Node(3);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(8);
    root->left->right->left->left = new Node(4);
    display(root);
    Node* ans = deleteNode(root, 5);
    display(ans);
    return 0;
}
