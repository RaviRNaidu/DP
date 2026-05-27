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

//tc -> o(n+n/2) sc-> o(1)
Node* brute(Node* head){
    int cnt = 0;
    Node* temp = head;
    while(temp != NULL){
        cnt++;
        temp = temp->next;
    }

    int index = cnt/2;
    temp = head;
    while(temp != NULL){
        index--;
        if(index == 0){
            Node* delNode = temp->next;
            temp->next = temp->next->next;
            delete delNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}

// u can take a seperate variabe and remember the prev node or u can do like the other optimal also where u skip 1 step of slow
Node* optimal(Node* head){
    if(head->next == NULL) return NULL;
    Node* fast = head;
    Node* slow = head;
    Node* prev = NULL;
    while(fast != NULL && fast->next != NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = prev->next->next;
    slow->next = nullptr;
    free(slow);
    return head;
}

//tc -> o(n/2)  sc -> o(1)
Node* optimal2(Node* head){
    if(head->next == NULL) return NULL;
    Node* fast = head;
    Node* slow = head;
    fast = fast->next->next;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* delNode = slow->next; 
    slow->next = slow->next->next;
    delNode->next = nullptr;
    free(delNode);
    return head;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = convertArray2LinkedList(arr);
    Node* newHead = optimal2(head);
    print(newHead);
    return 0;
}