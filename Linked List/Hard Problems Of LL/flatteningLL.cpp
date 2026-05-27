#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* child;

    public:
    Node(int data1, Node* next1, Node* child1){
        data = data1;
        next = next1;
        child = child1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        child = nullptr;
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

// O(N*M)*2 + N* M LOG N*M      SC -> O(N * M) * 2
Node* brute(Node* head){
    Node* temp = head;
    vector<int> arr;
    while(temp != NULL){
        Node* t2 = temp;
        while(t2 != NULL){
            arr.push_back(t2->data);
            t2 = t2->child;
        }
        temp = temp->next;
    }

    sort(arr.begin(), arr.end());

    Node* dummy = new Node(-1);
    Node* mover = dummy;
    for(int i=0;i<arr.size();i++){
        Node* newNode = new Node(arr[i]);
        mover->child = newNode;
        mover = newNode;
    }
    return dummy->child;
}

Node* mergeTwoList(Node* l1, Node* l2){
    Node* Dummy = new Node(-1);
    Node* mover = Dummy;
    while(l1 != NULL && l2 != NULL){
        if(l1->data < l2->data){
            mover->child = l1;
            mover = l1;
            l1 = l1->child;
        }
        else{
            mover->child = l2;
            mover = l2;
            l2 = l2->child;
        }
        mover->next = nullptr;

        if(l1 != NULL){
            mover->child = l1;
        }
        if(l2 != NULL){
            mover->child = l2;
        }

        return Dummy->child;
    }
}

Node* optimalRecurssion(Node* head){
    if(head == NULL || head->next == NULL) return head;
    Node* mergedList = optimalRecurssion(head->next);
    head = mergeTwoList(head, mergedList);
    return head;
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    Node* head = convertArray2LinkedList(arr);
    Node* newHead = optimalRecurssion(head);
    print(newHead); 
    return 0;
}