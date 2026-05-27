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

Node* flattening(Node* root,Node* &prev){
    if(root == NULL) return NULL;

    flattening(root->right,prev);
    flattening(root->left,prev);

    root->right = prev;
    root->left  = NULL;
    prev = root;

    return root;
}

//TC -> O(N)    SC->O(N)
Node* usingRecurssion(Node* root){
    Node* prev = NULL;
    return flattening(root,prev);
}




//TC -> O(N)    SC->O(N)
Node* usingStack(Node* root){
    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        Node* curr = st.top();
        st.pop();
        if(curr->right) st.push(curr->right);
        if(curr->left) st.push(curr->left);
        curr->right = st.empty() ? NULL : st.top();
        curr->left = NULL;
    }
    return root;
}

//TC -> O(N)    SC->O(1)
Node* usingMorriesTraversal(Node* root){
    Node* curr = root;
    while(curr != NULL){
        if(curr->left != NULL){
            Node* prev = curr->left;
            while(prev->right != NULL){
                prev = prev->right;
            }
            prev->right = curr->right;
            curr->right = curr->left;
        }
        curr = curr->right;
    }
}


void display(Node* root){
    while(root != NULL){
        cout<<root->data<<" ";
        root = root->right; 
    }
}

int main(){
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(6);
    root->right->right->left = new Node(7);
    Node* ans = usingStack(root);
    display(ans);
    return 0;
}
