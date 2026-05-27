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


//HERE I AM NORMALIZING before processing the level
//But your children indices are normalized using front later, 
//so the queue will contain normalized indices in the next iteration.
int solution(Node* root){
    int ans = 0;
    if(root == NULL) return ans;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        int n = q.size();
        int front = q.front().second;
        int last = q.back().second;
        ans = max(ans, (last - front) + 1);
        for(int i=0;i<n;i++){
            auto t = q.front();
            q.pop();
            if(t.first->left != NULL){
                q.push({t.first->left,((2 * t.second) + 1) - front});
            }
            if(t.first->right != NULL){
                q.push({t.first->right,((2 * t.second) + 2) - front});
            }
        }
    }
    return ans;
}

//Normalize inside the loop
//TC -> O(N)    SC-> O(N)
int striver(Node* root){
    int ans = 0;
    if(root == NULL) return ans;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        int n = q.size();
        int min = q.front().second;
        int first, last;
        for(int i=0;i<n;i++){
            int cur_it = q.front().second - min;
            Node* temp = q.front().first;
            q.pop();
            if(i == 0) first = cur_it;  
            if(i == n-1) last = cur_it;
            if(temp->left != NULL){
                q.push({temp->left,(2 * cur_it) + 1});
            }
            if(temp->right != NULL){
                q.push({temp->right,(2 * cur_it) + 2});
            }
        }
        ans = max(ans, last - first + 1);
    }
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
    root->right->right->right = new Node(9);
    root->left->left->left = new Node(10);
    int ans = solution(root);
    cout<<ans<<endl;
    return 0;
}
