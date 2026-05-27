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

//tc --> o(n) + o(n/2)   sc -> o(1)
Node* brute(Node* head){
    int cnt = 0;
    Node* temp = head;
    while(temp != NULL){
        cnt++;
        temp = temp->next;
    }
    int k = (cnt/2)+1;
    temp = head;
    while(temp != NULL){
        k--;
        if(k == 0){
            break;
        }
        temp = temp->next;
    }
    return temp;
}

Node* optimal(Node* head){
    Node* fast = head;
    Node* slow = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main(){
    vector<int> arr = {4, 3, 7, 8};
    Node* head = convertArray2LinkedList(arr);
    Node* newHead = optimal(head);
    print(newHead);
    return 0;
}
