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

Node* reversing(Node* head){
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        Node* nextNode = temp->next;
        temp->next = prev;
        prev = temp;
        temp = nextNode;
    }
    return prev;
}

Node* findKthNode(Node* head, int k){
    k -= 1;
    while(head != NULL && k > 0){
        k--;
        head = head->next;
    }
    return head;
}

//TC -> O(N) + O(N)   SC -> O(1)
Node* reversingKNode(Node* head, int k){
    Node* temp = head; 
    Node* prev = NULL;
    while(temp != NULL){
        Node* kthNode = findKthNode(temp, k);
        if(kthNode == NULL){
            if(prev)prev->next = temp;
            break;
        }

        Node* nextNode = kthNode->next;
        kthNode->next = nullptr;
        Node* newHead = reversing(temp);

        if(temp == head) {
            head = kthNode;
        }
        else{
            prev->next = kthNode;
        }

        prev = temp;
        temp = nextNode;
    }
    return head;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    Node* head = convertArray2LinkedList(arr);
    Node* newHead = reversingKNode(head, 3);
    print(newHead);
    return 0;
}

