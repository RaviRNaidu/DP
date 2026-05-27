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

Node* deleteHead(Node* head){
    if(head == NULL || head->next == NULL) return NULL;
    Node* temp = head;
    head = head->next;
    temp->next = nullptr;
    delete temp;
    return head;
}

Node* deleteTail(Node* head){
    if(head == NULL || head->next == NULL) return NULL;
    Node* temp = head;
    Node* prev = NULL;
    while( temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }
    prev->next = nullptr;
    delete temp;
    return head;
}

//me
//tc o(n + n-num)  sc -> o(1)
Node* brute(Node* head, int n){
    if(head == NULL) return NULL;
    if(head->next == NULL){
        if(n == 1){
            return NULL;
        }
    }
    if(n == 1){
        return deleteTail(head);
    }
    Node* temp = head;
    int length = 0;
    while(temp != NULL){      //tc -> o(n)
        length += 1;
        temp = temp->next;
    }
    int index = length - n + 1;
    if(index == 1){
        return deleteHead(head);
    }
    temp = head;
    Node* prev = NULL;
    while(temp != NULL){               //tc -> o(n)
        index--;
        if(index == 0){
            prev->next = temp->next;
            temp->next = nullptr;
            delete temp;
            return head;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}


//tc ->O(L)+O(L-N) sc -> o(1)
Node* brute1(Node* head, int n){
    if (head == NULL) {
        return NULL;
    }
    int cnt = 0;
    Node* temp = head;

    // Count the number of nodes in the linked list
    while (temp != NULL) {
        cnt++;
        temp = temp->next;
    }

    // If N equals the total number of
    // nodes, delete the head
    if (cnt == n) {
        Node* newhead = head->next;
        delete (head);
        return newhead;
    }

    // Calculate the position of the node to delete (res)
    int res = cnt - n;
    temp = head;

    // Traverse to the node just before the one to delete
    while (temp != NULL) {
        res--;
        if (res == 0) {
            break;
        }
        temp = temp->next;
    }

    // Delete the Nth node from the end
    Node* delNode = temp->next;
    temp->next = temp->next->next;
    delete (delNode);
    return head;
}


//tc -> o(len) sc -> o(1)
Node* optimal(Node* head, int n){
    Node* fast = head;
    for(int i=0;i<n;i++){
        fast = fast->next;
    }
    if(fast == NULL){
        Node* temp = head;
        head = head->next;
        temp->next = nullptr;
        free(temp);
        return head;
    }
    Node* slow = head;
    while(fast->next != NULL){
        slow = slow->next;
        fast = fast->next;
    }
    Node* deleteNode = slow->next;
    slow->next = slow->next->next;
    deleteNode->next = nullptr;
    free(deleteNode);
    return head;
}

Node* practice(Node* head, int n){
    if(head == NULL) return NULL;
    if(head->next == NULL){
        if(n == 1){
            return NULL;
        }
    }
    if(n == 1){
        return deleteTail(head);
    }
    Node* temp = head;
    int cnt = 0;
    while(temp != NULL){
        cnt += 1;
        temp = temp->next;
    }

    if(n == cnt){
        Node* del = head;
        head = head->next;
        free(del);
        return head;
    }

    int index = cnt - n;
    temp = head;
    while(temp != NULL && index != 0){
        index--;
        temp = temp->next;
    }
    Node* delNode = temp->next;
    temp->next = temp->next->next;
    free(delNode);
    return head;
}

int main(){
    vector<int> arr = {5, 4, 3, 2, 1};
    Node* head = convertArray2LinkedList(arr);
    Node* newHead = practice(head, 4);
    print(newHead);
    return 0;
}