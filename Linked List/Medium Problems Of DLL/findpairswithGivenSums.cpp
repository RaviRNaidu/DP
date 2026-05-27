#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

void print(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    return;
}

Node* convertArr2DLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i],nullptr,prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

//TC -> O(N^2) near about n square sc -> o(1)
vector<vector<int>> brute(Node* head, int sum){
    vector<vector<int>> ans;
    Node* temp = head;
    while(temp != NULL){
        Node* temp2 = temp->next;
        while(temp2 != NULL && temp->data + temp2->data <= sum){
            if(temp->data + temp2->data == sum){
                ans.push_back({temp->data,temp2->data});
            }
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
    return ans;
}


// TC -> O(2N)     SC -> O(1)
vector<vector<int>> optimal(Node* head, int sum){
    vector<vector<int>> ans;
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    Node* right = temp;
    Node* left = head;
    while(right->data >= left->data){
        if(left->data + right->data == sum){
            ans.push_back({left->data,right->data});
            left = left->next;
            right = right->back;
        }
        else if(left->data + right->data < sum){
            left = left->next;
        }
        else{
            right = right->back;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9};
    int sum;
    cin>>sum;
    Node* head = convertArr2DLL(arr);
    vector<vector<int>> ans = optimal(head,sum);
    for(auto it:ans){
        for(auto ab:it){
            cout<<ab<<" ";
        }
    }
    return 0;
}