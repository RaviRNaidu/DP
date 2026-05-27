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

//TC ->o(log n) sc -> o(1)
Node* insert(Node* root, int key){
    Node* keyNode = new Node(key);
    Node* prev = NULL;
    Node* temp = root;
    while(temp != NULL){
        prev = temp;
        if(temp->data > key){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }

    if(prev->data > key){
        prev->left = keyNode;
    }
    else{
        prev->right = keyNode;
    }
    return root;
}


//TC -> O(log base2 N)
Node* striver(Node* root, int key){
    Node* keyNode = new Node(key);
    if(root == NULL) return keyNode;
    Node* temp = root;
    while(true){
        if(temp->data > key){
            if(temp->left != NULL) temp = temp->left;
            else{
                temp->left = keyNode;
                break;
            }
        }
        else{
            if(temp->right != NULL) temp = temp->right;
            else{
                temp->right = keyNode;
                break;
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
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    Node* ans = striver(root, 5);
    display(ans);
    return 0;
}
