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

//TC -> O(H)    SC -> O(1)
Node* findingLCA(Node* root, Node* p, Node* q){
    while(root != NULL){
        if(root->data < p->data && root->data < q->data){
            root = root->right;
        }
        else if(root->data > p->data && root->data > q->data){
            root = root->left;
        }
        else{
            return root;
        }
    }
    return NULL;
}

Node* recursive(Node* root, Node* p, Node* q){
    if(root == NULL) return NULL;
    if(root->data < p->data && root->data < q->data){
        return recursive(root->right,p,q);
    }
    if(root->data > p->data && root->data > q->data){
        return recursive(root->left,p,q);
    }
    return root;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(5);
    root->right = new Node(10);
    root->left->left = new Node(3);
    root->left->right = new Node(6);
    root->right->left = new Node(9);
    root->right->right = new Node(12);
    Node* ans = recursive(root, root->left->left,root->right->right);
    cout<<ans->data<<endl;
    return 0;
}
