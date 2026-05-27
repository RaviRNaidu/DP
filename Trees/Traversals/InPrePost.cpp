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
vector<int> InPrePost(Node* root){
    vector<int> preOrder;
    vector<int> inOrder;
    vector<int> postOrder;
    if(root == NULL) return preOrder;
    stack<pair<Node*,int>> st;
    st.push({root,1});
    while(!st.empty()){
        root = st.top().first;
        int num = st.top().second;
        if(num == 1){
            preOrder.push_back(root->data);
            st.top().second++;
            if(root->left != NULL) st.push({root->left,1});
        }
        else if(num == 2){
            inOrder.push_back(root->data);
            st.top().second++;
            if(root->right != NULL) st.push({root->right,1});
        }
        else{
            postOrder.push_back(root->data);
            st.pop();
        }
    }
    for(int i=0;i<preOrder.size();i++){
        cout<<preOrder[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<inOrder.size();i++){
        cout<<inOrder[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<postOrder.size();i++){
        cout<<postOrder[i]<<" ";
    }
    cout<<endl;
    return preOrder;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    vector<int> ans = InPrePost(root);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
