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

//DONE BY ME BAYACHH!!
bool solution1(Node* root,int target, vector<int> &arr){
    if(root == NULL) return false;

    arr.push_back(root->data);
    if(root->data == target){
        return true;
    }

    bool l = solution1(root->left,target,arr);
    if(l == true) return true;
    bool r = solution1(root->right,target,arr);

    if(l == true || r == true) return true;
    else{
        arr.pop_back();
        return false;
    }
}

bool solution(Node* root,int target, vector<int> &arr){
    if(root == NULL) return false;

    arr.push_back(root->data);
    if(root->data == target){
        return true;
    }

    if(solution(root->left,target,arr) || solution(root->right,target,arr)){
        return true;
    }

    arr.pop_back();
    return false;
}

vector<int> rootToLeaf(Node* root,int target){
    vector<int> ans;
    if(root == NULL) return ans;
    solution(root, target, ans);
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
    vector<int> ans = rootToLeaf(root,9);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
