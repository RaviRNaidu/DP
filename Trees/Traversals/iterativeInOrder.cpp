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

//TC -> O(N) SC -> O(N) BUT THE CORRECT ANS IS O(H) H-HEIGHT OF THE TREE (SKEW TREE)
vector<int> iterativeInOrder(Node* root){
    vector<int> ans;
    if(root == NULL) return ans;
    stack<Node*> st;
    while(true){
        if(root != NULL){
            st.push(root);
            root = root->left;
        }
        else{
            if(st.empty()) break;
            root = st.top();
            st.pop();
            ans.push_back(root->data);
            root = root->right;
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
    vector<int> ans = iterativeInOrder(root);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
