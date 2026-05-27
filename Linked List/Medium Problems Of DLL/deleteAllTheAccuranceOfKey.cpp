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

//TC -> O(N)    SC -> O(1)
Node* deleting(Node* head, int key){
    Node* temp = head;
    Node* prev = NULL;
    Node* nextnode = NULL;
    while(temp != NULL){
        if(temp->data == key){
            if(temp == head){
                head = head->next;
            }
            prev = temp->back;
            nextnode = temp->next;
            if(prev) prev->next = nextnode;
            if(nextnode) nextnode->back = prev;
            delete temp;
            temp = nextnode;
        }
        else temp = temp->next;
    }
    return head;
}

int main(){
    vector<int> arr = {10, 4, 10, 10, 6, 10};
    int key;
    cin>>key;
    Node* head = convertArr2DLL(arr);
    Node* newHead = deleting(head, key);
    print(newHead);
    return 0;
}