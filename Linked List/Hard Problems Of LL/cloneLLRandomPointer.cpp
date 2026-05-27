#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* random;

    public:
    Node(int data1, Node* next1, Node* random1){
        data = data1;
        next = next1;
        random = random1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        random = nullptr;
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

//TC -> O(N) + O(N)         SC -> O(N) storing  O(N) creating new nodes
Node* brute(Node* head){
    Node* temp = head;
    map<Node*, Node*> mpp;
    while(temp != NULL){            // -> O(N)
        Node* newNode = new Node(temp->data);
        mpp[temp] = newNode;        // o(1) unordered map 
        temp = temp->next;
    }

    temp = head;
    while(temp != NULL){            // -> O(N)
        Node* copyNode = mpp[temp];
        copyNode->next = mpp[temp->next];
        copyNode->random = mpp[temp->random];
        temp = temp->next;
    }
    return mpp[head];
}

// TC -> O(3N)  SC -> O(N)
Node* optimal(Node* head){
    Node* temp = head;
    while(temp != NULL){
        Node* newNode = new Node(temp->data);
        newNode->next = temp->next;
        temp->next = newNode;
        temp = temp->next->next;
    }

    temp = head;
    while(temp != NULL){
        Node* copy = temp->next;
        if(temp->random == NULL){
            copy->random = NULL;
        }
        else{
            copy->random = temp->random->next;
        }
        temp = temp->next->next;
    }

    Node* dummy = new Node(-1);
    Node* mover = dummy;
    temp = head;
    while(temp != NULL){
        mover->next = temp->next;
        temp->next = temp->next->next;
        mover = mover->next;
        temp = temp->next;
    }
    return dummy->next;
}

void insertingInBetween(Node* head){
    Node* temp = head;
    while(temp != NULL){
        Node* nextElement = temp->next;
        Node* newNode = new Node(temp->data);

        newNode->next = nextElement;
        temp->next = newNode;

        temp = nextElement;
    }
}

void randomPointersChanging(Node* head){
    Node* temp = head;
    while(temp != NULL){
        Node* copy = temp->next;

        if(temp->random != NULL){
            copy->random = temp->random->next;
        }
        else{
            copy->random = NULL;
        }

        temp = temp->next->next;
    }
}

Node* changingNextPointers(Node* head){
    Node* dummy = new Node(-1);
    Node* mover = dummy;
    Node* temp = head;
    while(temp != NULL){
        mover->next = temp->next;
        temp->next = temp->next->next;
        mover = mover->next;
        temp = temp->next;
    }
    return dummy->next;
}

Node* optimalStriver(Node* head){
    insertingInBetween(head);
    randomPointersChanging(head);
    return changingNextPointers(head);
}
int main(){
    vector<int> arr = {1,2,3,4,5};
    Node* head = convertArray2LinkedList(arr);
    Node* newHead = brute(head);
    print(newHead); 
    return 0;
}