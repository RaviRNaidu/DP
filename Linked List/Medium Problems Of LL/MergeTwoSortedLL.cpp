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

//TC -> o(n) + o(m) + o(N logN) + o(N)     SC -> o(N) + o(N)
Node* brute(Node* head1, Node* head2){
    vector<int> arr;
    Node* temp1 = head1;
    Node* temp2 = head2;
    while(temp1 != NULL){          //o(n)
        arr.push_back(temp1->data);
        temp1 = temp1->next;
    }
    while(temp2 != NULL){           //o(m)                 n+m = N
        arr.push_back(temp2->data);
        temp2 = temp2->next;
    }

    sort(arr.begin(),arr.end());          //o(N log N)

    Node* head = convertArray2LinkedList(arr);  //O(N)
    return head;
}

// TC -> O(N + M)   SC -> O(1)
Node* optimal(Node* head1, Node* head2){
    Node* DummyNode = new Node(-1);
    Node* Mover = DummyNode;
    Node* temp1 = head1;
    Node* temp2 = head2;
    while(temp1 != NULL && temp2 != NULL){
        if(temp1->data <= temp2->data){
            Mover->next = temp1;
            Mover = temp1;
            temp1 = temp1->next;
        }
        else{
            Mover->next = temp2;
            Mover = temp2;
            temp2 = temp2->next;
        }
    }
    if(temp1){
        Mover->next = temp1;
    }
    else Mover->next = temp2;
    
    return DummyNode->next;
}

int main(){
    vector<int> arr1 = {1, 2};
    vector<int> arr2 = {3, 5, 6};
    Node* head1 = convertArray2LinkedList(arr1);
    Node* head2 = convertArray2LinkedList(arr2);
    Node* newHead = optimal(head1, head2);
    print(newHead);
    return 0;
}