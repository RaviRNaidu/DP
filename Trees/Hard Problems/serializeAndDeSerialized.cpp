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

string serialize(Node* root){
    string s = "";
    if(root == NULL) return "";
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp != NULL) s.append(to_string(temp->data) + ',');
        else s.append("#,");
        if(temp != NULL){
            q.push(temp->left);
            q.push(temp->right);
        }
    }
    cout<<s<<endl;
    return s;
}

//TC -> O(N)    SC-> O(N)
Node* deserialize(string data){
    if(data.size() == 0) return NULL;
    stringstream s(data);
    string str;
    getline(s,str,',');
    Node* root = new Node(stoi(str));
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        //ADDING THE LEFT NODE
        getline(s,str,',');
        if(str == "#"){
            temp->left = NULL;
        }
        else{
            Node* lNode = new Node(stoi(str));
            temp->left = lNode;
            q.push(lNode);
        }

        //ADDING THE RIGHT NODE
        getline(s,str,',');
        if(str == "#"){
            temp->right = NULL;
        }
        else{
            Node* rNode = new Node(stoi(str));
            temp->right = rNode;
            q.push(rNode);
        }
    }
    return root;
}

void display(Node* root){
    if(root != NULL){
        cout<<root->data<<" ";
        display(root->left);
        display(root->right);
    }
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    string ans = serialize(root);
    Node* node = deserialize(ans);
    display(node);
    return 0;
}
