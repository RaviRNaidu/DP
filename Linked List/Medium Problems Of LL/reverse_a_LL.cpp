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

//tc -> o(2n)  sc -> o(n)
Node* brute(Node* head){
    stack<int> st;
    Node* temp = head;
    while(temp != NULL){
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp != NULL){
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}

//this is a optimal soution using iteration
//tc -> o(n)  sc -> o(1)
Node* optimal(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

//this is optimal solution using recursion
//tc -> o(n)  sc -> o(n) cuz it is the recursive stack space where it will store the function in stack space
Node* recursion(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* newHead = recursion(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = nullptr;
    return newHead; 
}

int main(){
    vector<int> arr = {4, 3, 7, 8};
    Node* head = convertArray2LinkedList(arr);
    Node* newHead = recursion(head);
    print(newHead);
    return 0;
}