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

Node* findtail(Node* head, int k){
    int cnt = 1;
    while(head != NULL){
        if(cnt == k) return head;
        cnt++;
        head = head->next;
    }
    return head;
}

//TC -> O(2N)       SC -> O(1)
Node* rotate(Node* head, int k){
    if(head == NULL || k == 0) return head;
    Node* tail = head;
    int len = 1;
    while(tail->next != NULL){
        tail = tail->next;
        len += 1;
    }

    if(k % len == 0) return head;
    k = k % len;

    //attach the tail to the head
    tail->next = head;
    int el = len - k;
    Node* lastNode = findtail(head, el); // id el is 1 then it might have to traverse till the last node soo o(n)

    head = lastNode->next;
    lastNode->next = NULL;

    return head;
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    Node* head = convertArray2LinkedList(arr);
    Node* newHead = rotate(head, 2);
    print(newHead); 
    return 0;
}