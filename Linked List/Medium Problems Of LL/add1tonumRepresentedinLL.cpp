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

Node* reverseLL(Node* head){
    if(head == NULL || head->next == NULL) return head;
    Node* prev = NULL;
    Node* temp = head;
    while(temp != NULL){
        Node* next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    return prev;
}

//TC -> O(3N) SC -> O(1)
Node* add1toLL(Node* head){
    head = reverseLL(head);                  //o(n)
    Node* temp = head;
    int carry = 1;
    while(temp != NULL){                            //o(n)
        temp->data = temp->data + carry;
        if(temp->data < 10){
            carry = 0;
            break;
        }
        else{
            temp->data = 0;
            carry = 1;
        }
        temp = temp->next;
    }
    head = reverseLL(head);                     //o(n)
    if(carry == 1){
        Node* newNode = new Node(1);
        newNode->next = head;
        return newNode;
    }
    return head;
}





//OPTIMAL SOLUTIONN
//TC -> O(N)  SC -> O(N) it will be stored in my recursive stack space to get executed 
int carryHelper(Node* temp){
    if(temp == NULL){
        return 1;
    }
    int carry = carryHelper(temp->next);
    temp->data = temp->data + carry;
    if(temp->data < 10){
        return 0;
    }
    temp->data = 0;
    return 1;
    // else{
    //     temp->data = 0;
    //     carry = 1;
    // }
    // return carry;
}

Node* optimal(Node* head){
    int carry = carryHelper(head);
    if(carry == 1){
        Node* newNode = new Node(1);
        newNode->next = head;
        return newNode;
    }
    return head;
}

int main(){
    vector<int> arr = {9, 9};
    Node* head = convertArray2LinkedList(arr);
    Node* newHead = optimal(head);
    print(newHead);
    return 0;
}