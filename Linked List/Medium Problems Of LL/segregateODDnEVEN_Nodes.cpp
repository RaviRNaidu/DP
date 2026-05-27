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

//DONE BY MEEEEEEEE
//tc ->o(2n) sc o(n)
Node* brute(Node* head){
    vector<int> arr1;
    vector<int> arr2;
    Node* first = head;
    Node* second = head->next;
    while(first != NULL && first->next != NULL){
        arr1.push_back(first->data);
        first = first->next->next;
    }
    if(first) arr1.push_back(first->data);

    while(second != NULL && second->next != NULL){
        arr2.push_back(second->data);
        second = second->next->next;
    }
    if(second) arr2.push_back(second->data);

    Node* temp = head;
    for(int i=0;i<arr1.size();i++){
        temp->data = arr1[i];
        temp = temp->next;
    }

    for(int j=0;j<arr2.size();j++){
        temp->data = arr2[j];
        temp = temp->next;
    }
    return head;
}

//tc -> o(2n)  sc -> o(n)
Node* bruteStriver(Node* head){
    if(head == NULL || head->next == NULL) return head;
    vector<int> arr;
    Node* temp = head;
    while(temp != NULL && temp->next != NULL){ //tc -> o(n/2)
        arr.push_back(temp->data);
        temp = temp->next->next;
    }
    if(temp) arr.push_back(temp->data);

    temp = head->next;
    while(temp != NULL && temp->next != NULL){ //tc -> o(n/2)
        arr.push_back(temp->data);
        temp = temp->next->next;
    }
    if(temp) arr.push_back(temp->data);

    temp = head;
    int i = 0;
    while(temp != NULL){        // tc ->o(n)
        temp->data = arr[i];
        i++;
        temp = temp->next;
    }
    return head;
}

//tc -> o(n/2)*2 = o(n)   sc -> o(1)
Node* optimal(Node* head){
    if(head == NULL || head->next == NULL) return head;
    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = head->next;
    while(even != NULL && even->next != NULL){
        odd->next = odd->next->next;
        odd = odd->next;
        even->next = even->next->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = convertArray2LinkedList(arr);
    Node* newHead = optimal(head);
    print(newHead);
    return 0;
}