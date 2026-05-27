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

class solution{
    public:
    Node* firstOcc;
    Node* withFirst;
    Node* secondOcc;
    Node* prev;

    private:
    void recursion(Node* root){
        if(root == NULL) return;

        recursion(root->left);
        if(prev != NULL && root->data < prev->data){

            if(firstOcc == NULL){
                firstOcc = prev;
                withFirst = root;
            }
            else{
                secondOcc = root;
            }
        }
        prev = root;

        recursion(root->right);
    }

    public:
    void recoverTree(Node* root){
        firstOcc = withFirst = secondOcc = NULL;
        prev = new Node(INT_MIN);
        recursion(root);
        if(firstOcc && secondOcc){
            swap(firstOcc->data, secondOcc->data);
        }
        else if(firstOcc && withFirst){
            swap(firstOcc->data, withFirst->data);
        }
    }

};

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    solution(root);
    return 0;
}











//ME
// void recursion(Node* root){
//         if(root != NULL){
//             recursion(root->left);
//             if(prev->data > root->data && firstOcc == NULL){
//                 firstOcc = prev;
//                 withFirst = root;
//             }
//             else{
//                 secondOcc = root;
//             }
//             prev = root;
//             recursion(root->right);
//         }
//     }