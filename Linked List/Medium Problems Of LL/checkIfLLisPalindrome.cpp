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

// done by ME and it works super fine
bool brute1(Node* head){
    vector<int> arr;
    Node* temp = head;
    while(temp != NULL){
        arr.push_back(temp->data);
        temp = temp->next;
    }

    int n = arr.size();
    for(int i=0;i<=n/2;i++){
        if(arr[i] != arr[n-i-1]){
            return false;
        }
    }
    return true;
}

//done by striver
//tc --> o(2n) sc --> o(n)
bool brute(Node* head){
    stack<int> st;
    Node* temp = head;
    while(temp != NULL){
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;
    while(temp != NULL){
        if(temp->data != st.top()){
            return false;
        }
        st.pop();
        temp = temp->next;
    }
    return true;
}

Node* reversee(Node* head){
    if(head == NULL || head->next == NULL) return head;
    Node* current = head;
    Node* prev = NULL;
    while(current != NULL){
        Node* front = current->next;
        current->next = prev;
        prev = current;
        current = front;
    }
    return prev;
}

 //tc -> o(2n)  sc -->o(1)
bool optimal(Node* head){
    if(head == NULL || head->next == NULL) return true;
    Node* fast = head;
    Node* slow = head;
    while(fast->next != NULL && fast->next->next != NULL){   //tc -> o(n/2)
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* newHead = reversee(slow->next);  //tc -> o(n/2)
    Node* first = head;
    Node* second = newHead;
    while(second != NULL){                  //tc -> o(n/2)
        if(first->data != second->data){
            reversee(newHead);                //tc -> o(n/2)
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reversee(newHead);
    return true;
}

int main(){
    vector<int> arr = {1, 1, 2, 1};
    Node* head = convertArray2LinkedList(arr);
    cout<<optimal(head);
    return 0;
}