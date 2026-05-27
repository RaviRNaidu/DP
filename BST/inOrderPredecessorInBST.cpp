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

void inorder(Node* root, vector<int> &arr){
    if(root != NULL){
        inorder(root->left,arr);
        arr.push_back(root->data);
        inorder(root->right,arr);
    }
}

int BS(vector<int> &arr, int target){
    int low = 0; int high = arr.size()-1;
    while(low <= high){
        int mid = low + high / 2;
        if(arr[mid] == target){
            return arr[mid-1];
        }
        else if(arr[mid] > target){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return -1;
}

//TC -> O(N + LOG N) SC -> O(N)
int brute(Node* root, int val){
    vector<int> ans;
    inorder(root, ans);
    return BS(ans, val);
}

//TC -> O(H)    SC -> O(1)
Node* optimal(Node* root, int val){
    Node* ans = NULL;
    while(root != NULL){
        if(root->data >= val){
            root = root->left;
        }
        else{
            ans = root;
            root = root->right;
        }
    }
    return ans;
}

int main(){
    Node* root = new Node(8);
    root->left = new Node(5);
    root->right = new Node(10);
    root->left->left = new Node(3);
    root->left->right = new Node(6);
    root->right->left = new Node(9);
    root->right->right = new Node(12);
    Node* ans = optimal(root,6);
    cout<<ans->data<<endl;
    return 0;
}
