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
int ceill(Node* root, int val){
    int ans = -1;
    while(root != NULL){
        if(root->data == val){
            ans = root->data;
            return ans;
        }
        if(root->data < val){
            root = root->right;
        }
        else{
            ans = root->data;
            root = root->left;
        }
    }
    return ans;
}

int main(){
    Node* root = new Node(8);
    root->left = new Node(5);
    root->right = new Node(12);
    root->left->left = new Node(4);
    root->left->right = new Node(7);
    root->right->left = new Node(10);
    root->right->right = new Node(14);
    root->left->right->left = new Node(6);
    root->right->right->left = new Node(13);
    int ans = ceill(root, 9);
    cout<<ans<<endl;
    return 0;
}
