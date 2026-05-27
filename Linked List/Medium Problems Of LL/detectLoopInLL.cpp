#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

void print(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    return;
}

Node* convertArray2LinkedList(vector<int> &arr){
    Node* Head = new Node(arr[0]);
    Node* Mover = Head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        Mover->next = temp;
        Mover = temp;
    }
    return Head;
}

//tc --> o(n * 2 log n)  why 2 log n because we are performing two operation and each operation takes long n if we use ordered map
//but if it is unordered then on best it will take o(1) ans on worst it might take o(n)
//sc --> o(n)
bool brute(Node* head){
    unordered_map<Node* , int> mpp;
    Node* temp = head;
    while(temp != NULL){
        if(mpp.find(temp) != mpp.end()){
            return true;
        }
        mpp[temp] = 1;
        temp = temp->next;
    }
    return false;
}

//tc--> o(n) not exactly but somewhere around o(n)   sc -> o(1)
bool optimal(Node* head){
    Node* fast = head;
    Node* slow = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
            return true;
        }
    }
    return false; 
}

int main(){
    vector<int> arr = {4, 3, 7, 8};
    Node* head = convertArray2LinkedList(arr);
    cout<<brute(head);
    return 0;
}