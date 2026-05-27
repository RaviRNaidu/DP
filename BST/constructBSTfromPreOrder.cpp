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

void display(Node* root){
    if(root != NULL){
        display(root->left);
        cout<<root->data<<" ";
        display(root->right);
    }
}

Node* brute(vector<int> &arr){
    int n = arr.size();
    Node* root = new Node(arr[0]);
    for(int i=1;i<n;i++){
        Node* curr = root;
        while(curr != NULL){
            if(arr[i] < curr->data){
                if(curr->left != NULL){
                    curr = curr->left;
                }
                else{
                    curr->left = new Node(arr[i]);
                    break;
                }
            }
            else{
                if(curr->right != NULL){
                    curr = curr->right;
                }
                else{
                    curr->right = new Node(arr[i]);
                    break;
                }
            }
        }
    }
    return root;
}

Node* buildTree(vector<int> &arr, int &i, int bound){
    if(i == arr.size() || arr[i] > bound) return NULL;
    Node* root = new Node(arr[i]);
    i++;
    root->left = buildTree(arr,i,root->data);
    root->right = buildTree(arr,i,bound);

    return root;
}

Node* optimal(vector<int> &arr){
    int i = 0;
    return buildTree(arr, i, INT_MAX);
}

int main(){
    vector<int> arr = {8,5,1,7,10,12};
    Node* ans = optimal(arr);
    display(ans);
    return 0;
}
