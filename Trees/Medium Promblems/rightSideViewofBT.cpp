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


//TC -> O(N) this can also be o(n * log n) for the map 
//SC -> O(N) for map
vector<int> topView(Node* root){
    vector<int> ans;
    if(root == NULL) return ans;
    map<int,int> mpp;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        Node* temp = q.front().first;
        int level = q.front().second;
        q.pop();
        mpp[level] = temp->data;

        if(temp->left != NULL) q.push({temp->left,level+1});
        if(temp->right != NULL) q.push({temp->right,level+1});
    }

    for(auto it:mpp){
        ans.push_back(it.second);
    }
    return ans;
}

//TC -> O(N)    SC -> O(H) height of the tree
void solution(Node* root, int level, vector<int> &arr){
    if(root == NULL) return;

    if(arr.size() == level){
        arr.push_back(root->data);
    }
    solution(root->right,level+1,arr);
    solution(root->left,level+1,arr);
}

//THE MOST OPTIMALLLLLL USING RECURSION!!!!!!!
vector<int> optimal(Node* root){
    vector<int> ans;
    solution(root,0,ans);

    return ans;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->right->right = new Node(7);
    vector<int> ans = topView(root);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
