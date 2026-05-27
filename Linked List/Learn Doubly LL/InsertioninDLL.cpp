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

//converting the array to DLL
Node* convertArr2DLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i],nullptr,prev);
        prev->next = temp;
        prev  = temp;
    }
    return head;
}

//inserting the el before the head
Node* InsertionBeforeHead(Node* head, int el){
    Node* newel = new Node(el, head, nullptr);
    head->back = newel;
    return newel;
}

//inserting the el before the tail
Node* InsertionBeforTail(Node* head, int el){
    if(head->next == NULL){
        return InsertionBeforeHead(head, el);
    }
    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    Node* prev = tail->back;
    Node* newel = new Node(el, tail, prev);
    tail->back = newel;
    prev->next = newel;
    return head;
}

//insert before kth element
Node* InsertionBeforK(Node* head, int el, int k){
    if(head == NULL) return NULL;
    if(k == 1){
        return InsertionBeforeHead(head, el);
    }
    int cnt = 0;
    Node* temp = head;
    while(temp != NULL){
        cnt++;
        if(cnt == k){
            Node* prev = temp->back;
            Node* newel = new Node(el, temp, prev);
            temp->back = newel;
            prev->next = newel;
            break;
        }
        temp = temp->next;
    }
    return head;
}

//insert before element
Node* InsertionBeforEl(Node* head, int el, int num){
    Node* temp = head;
    while(temp != NULL){
        if(temp->data == num){
            break;
        }
        temp = temp->next;
    }
    if(temp == NULL) return head;
    Node* prev = temp->back;
    Node* newel = new Node(el, temp, prev);
    temp->back = newel;
    prev->next = newel;
    return head;
}

int main(){
    vector<int> arr = {4, 3, 7, 5};
    Node* head = convertArr2DLL(arr);
    Node* newHead = InsertionBeforEl(head, 10, 77);
    print(newHead);
    return 0;
}