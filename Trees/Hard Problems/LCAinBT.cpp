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

bool finding(Node* root, int val, vector<int>& arr){
    if(root == NULL) return false;

    arr.push_back(root->data);
    if(root->data == val){
        return true;
    }

    if(finding(root->left,val,arr) || finding(root->right,val,arr)){
        return true;
    }

    arr.pop_back();
    return false;
}

vector<int> findThePath(Node* root, int target){
    vector<int> ans;
    finding(root,target,ans);
    return ans;
}

//TC -> O(2N + H)   SC -> O(H) + O(2N)
int brute(Node* root, int p, int q){
    vector<int> arr1 = findThePath(root,p);
    vector<int> arr2 = findThePath(root,q);

    int n = arr1.size();
    int m = arr2.size();
    if(m > n) n = m;
    int ans = -1;
    for(int i=0;i<n;i++){
        if(arr1[i] == arr2[i]){
            ans = arr1[i];
        }
    }
    return ans;
}

//TC -> O(N)    SC->O(N)
//DONE BY ME
Node* optimal(Node* root, Node* p, Node* q){
    if(root == NULL) return NULL;
    //striver just combined all which one base case OBSERVE
    if(root == p || root == q) return root;

    Node* l = optimal(root->left,p,q);
    Node* r = optimal(root->right,p,q);

    if(l == NULL && r == NULL) return NULL;
    if(l != NULL && r == NULL) return l;
    if(l == NULL && r != NULL) return r;
    if(l != NULL && r != NULL) return root;
}

//TC -> O(N)    SC->O(N)
Node* striver(Node* root, Node* p, Node* q){
    if(root == NULL || root == p || root == q){
        return root;
    }

    Node* l = optimal(root->left,p,q);
    Node* r = optimal(root->right,p,q);

    if(l == NULL){
        return r;
    }
    else if(r == NULL){
        return l;
    }
    else{
        return root;
    }
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    Node* ans = striver(root,root->left,root->right->right);
    cout<<ans->data<<endl;
    return 0;
}
