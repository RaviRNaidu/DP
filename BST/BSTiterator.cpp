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

class BSTiterator{
    private:
    stack<Node*> st;

    public:
    BSTiterator(Node* root){
        pushAll(root);
    }

    bool hasNext(){
        return !st.empty();
    }

    int next(){
        Node* temp = st.top();
        st.pop();
        pushAll(temp->right);
        return temp->data;
    }

    private:
    void pushAll(Node* root){
        while(root != NULL){
            st.push(root);
            root = root->left;
        }
    }
};

int main(){
    Node* root = new Node(8);
    root->left = new Node(5);
    root->right = new Node(10);
    root->left->left = new Node(3);
    root->left->right = new Node(6);
    root->right->left = new Node(9);
    root->right->right = new Node(12);
    return 0;
}
