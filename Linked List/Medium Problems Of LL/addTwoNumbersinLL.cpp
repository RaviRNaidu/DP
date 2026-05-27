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

// tc -> o(max(n1,n2))   sc -> o(max(n1,n2))
Node* adding(Node* head1, Node* head2){
    Node* dummyNode = new Node(-1);
    Node* curr = dummyNode;
    Node* temp1 = head1;
    Node* temp2 = head2;
    int carry = 0;
    while(temp1 != NULL || temp2 != NULL){
        int sum = carry;
        if(temp1 != NULL) sum += temp1->data;
        if(temp2 != NULL) sum += temp2->data;
        Node* newNode = new Node(sum % 10);
        carry = sum / 10;

        curr->next = newNode;
        curr = newNode;
        
        if(temp1) temp1 = temp1->next;
        if(temp2) temp2 = temp2->next;
    }

    if(carry != 0){
        Node* newNode = new Node(carry);
        curr->next = newNode;
    }

    return dummyNode->next;
}

int main(){
    vector<int> arr1 = {1, 2, 4};
    vector<int> arr2 = {3, 5, 6};
    Node* head1 = convertArray2LinkedList(arr1);
    Node* head2 = convertArray2LinkedList(arr2);
    Node* newHead = adding(head1, head2);
    print(newHead);
    return 0;
}