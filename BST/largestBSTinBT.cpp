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

class NodeVal{
    public:
    int maxSize;
    int maxNode;
    int minNode;

    NodeVal(int minNode1, int maxNode1, int size){
        this->minNode = minNode1;
        this->maxNode = maxNode1;
        this->maxSize = size;
    }
};

//checking is its valid or not
bool check(Node* root, int min, int max){
    if(root == NULL) return true;
    if(root->data <= min || root->data >= max) return false;
    return check(root->left, min, root->data) && check(root->right, root->data, max);
}
bool checkIfValid(Node* root){
    return check(root, INT_MIN, INT_MAX);
}

//counting the total nodes
void recursivee(Node* root, int& cnt){
    if(root == NULL){
        return;
    }
    recursivee(root->left, cnt);
    cnt = cnt + 1;
    recursivee(root->right, cnt);
}
int counting(Node* root){
    if(root == NULL) return 0;
    int cnt = 0;
    recursivee(root, cnt);
    return cnt;
}

int brute(Node* root){
    if(root == NULL) return 0;
}

//TC -> O(N)    SC->O(1)
NodeVal optimal(Node* root){
    if(root == NULL){
        return NodeVal(INT_MAX,INT_MIN,0);
    }

    auto left = optimal(root->left);
    auto right = optimal(root->right);

    if(left.maxNode < root->data && right.minNode > root->data){
        return NodeVal(min(root->data,left.minNode),max(root->data,right.maxNode), 1 + left.maxSize + right.maxSize);
    }
    else{
        return NodeVal(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }
}

int main(){
    Node* root = new Node(6);
    root->left = new Node(4);
    root->right = new Node(8);
    root->left->left = new Node(2);
    root->left->right = new Node(5);
    root->right->left = new Node(7);
    root->right->right = new Node(9);
    cout<<optimal(root).maxSize<<endl;
    return 0;
}