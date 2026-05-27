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

//IT IS AN AMOTISED N COMPLEXITY (1+2+1+...) ALL THE ITERATION TOGETHER MAKE O(N)
//TC-> O(2N) SC -> O(1)
vector<int> morriesTraversal(Node* root){
    vector<int> ans;
    if(root == NULL) return ans;
    Node* curr = root;
    while(curr != NULL){
        if(curr->left == NULL){
            ans.push_back(curr->data);
            curr = curr->right;
        }
        else{
            Node* mover = curr->left;
            while(mover->right != NULL && mover->right != curr){
                mover = mover->right;
            }
            if(mover->right == NULL){
                mover->right = curr;
                curr = curr->left;
            }
            else{
                mover->right = NULL;
                ans.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return ans;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    vector<int> ans = morriesTraversal(root);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
