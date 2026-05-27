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
int findingMaxPath(Node* root,int& maxi){
    if(root == NULL) return 0;

    int leftMax = max(0,findingMaxPath(root->left,maxi));
    int rightMax = max(0,findingMaxPath(root->right,maxi));

    maxi = max(maxi,root->data+leftMax+rightMax);

    return root->data + max(leftMax,rightMax);
}

int solution(Node* root){
    int maxi = INT_MIN;

    findingMaxPath(root,maxi);
    return maxi;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    int ans = solution(root);
    cout<<ans;
    return 0;
}
