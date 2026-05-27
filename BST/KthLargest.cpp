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

void recursion(Node* root, int &n){
    if(root != NULL){
        n++;
        recursion(root->left,n);
        recursion(root->right,n);
    }
}

int numNodes(Node* root){
    int n = 0;
    recursion(root,n);
    return n;
}

int KthSmallest(Node* root, int k){
    stack<Node*> st;
    int cnt = 0;
    while(true){
        if(root != NULL){
            st.push(root);
            root = root->left;
        }
        else{
            if(st.empty()) break;
            root = st.top();
            st.pop();
            cnt++;
            if(cnt == k){
                return root->data;
            }
            root = root->right;
        }
    }
    return -1;
}

int moriss(Node* root, int k){
    int n = numNodes(root);
    int sK = n - k + 1;
    int cnt = 0;
    Node* curr = root;
    while(curr != NULL){
        if(curr->left){
            Node* mover = curr->left;
            while(mover->right != NULL  && mover->right != curr){
                mover = mover->right;
            }
            if(mover->right == NULL){
                mover->right = curr;
                curr = curr->left;
            }
            else{
                mover->right = NULL;
                cnt++;
                if(cnt == sK){
                    return curr->data;
                }
                curr = curr->right;
            }
        }
        else{
            cnt++;
            if(cnt == sK){
                return curr->data;
            }
            curr = curr->right;
        }
    }
    return -1;
}







//for largest
int kthLargest(Node* root, int k){

    int cnt = 0;
    Node* curr = root;

    while(curr){

        if(curr->right){

            Node* mover = curr->right;

            while(mover->left != NULL && mover->left != curr){
                mover = mover->left;
            }

            if(mover->left == NULL){
                mover->left = curr;
                curr = curr->right;
            }
            else{
                mover->left = NULL;

                cnt++;
                if(cnt == k) return curr->data;

                curr = curr->left;
            }
        }
        else{
            cnt++;
            if(cnt == k) return curr->data;

            curr = curr->left;
        }
    }

    return -1;
}

int main(){
    Node* root = new Node(8);
    root->left = new Node(5);
    root->right = new Node(10);
    root->left->left = new Node(3);
    root->left->right = new Node(6);
    root->right->left = new Node(9);
    root->right->right = new Node(12);
    int ans = moriss(root,3);
    cout<<ans<<endl;
    return 0;
}
