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

int findLeftHeight(Node* root){
    int ans = 0;
    while(root){
        ans++;
        root = root->left;
    }
    return ans;
}

int findRightHeight(Node* root){
    int ans = 0;
    while(root){
        ans++;
        root = root->right;
    }
    return ans;
}

//TC -> O((LOG N)^2)    SC -> O(LOG N / H)
int cntNodes(Node* root){
    if(root == NULL) return 0;

    int lh = findLeftHeight(root);
    int rh = findRightHeight(root);

    if(lh == rh){
        return (1<<lh) - 1;
    }

    return 1 + cntNodes(root->left) + cntNodes(root->right);
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    int ans = cntNodes(root);
    cout<<ans<<endl;
    return 0;
}
