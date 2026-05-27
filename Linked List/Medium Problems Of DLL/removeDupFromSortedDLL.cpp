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

//DONE BY ME AND IT WORKS SUPERR FINEE
//TC -> O(N) SC -> O(1) 
Node* optimal1(Node* head){
    Node* temp = head;
    int el = -1;
    while(temp != NULL){
        if(temp->data == el){
            Node* prev = temp->back;
            Node* front = temp->next;
            if(prev) prev->next = front;
            if(front) front->back = prev;
            delete temp;
            temp = front;
        }
        else{
            el = temp->data;
            temp = temp->next;
        }
    }
    return head;
}

// TC -> O(N)       SC -> O(1)
Node* optimal2(Node* head){
    Node* temp = head;
    while(temp != NULL && temp->next != NULL){
        Node* nextNode = temp->next;
        while(nextNode != NULL && nextNode->data == temp->data){
            Node* dup = nextNode;
            nextNode = nextNode->next;
            free(dup);
        }
        temp->next = nextNode;
        if(nextNode != NULL)nextNode->back = temp;
        temp = temp->next;
    }
    return head;
}

int main(){
    vector<int> arr = {1,1,1,2,3,3,4};
    Node* head = convertArr2DLL(arr);
    Node* newHead = optimal2(head);
    print(newHead);
    return 0;
}