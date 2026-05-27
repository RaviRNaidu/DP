#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

void print(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    return;
}

//converting the array to DLL
Node* convertArr2DLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i],nullptr,prev);
        prev->next = temp;
        prev  = temp;
    }
    return head;
}

//tc -> o(2n)  sc --> o(n)
Node* brute(Node* head){
    stack<int> st;
    Node* temp = head;
    while(temp != NULL){           //tc o(n)
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;
    while(temp != NULL){        //tc o(n)
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}


//tc -> o(n)  sc-> o(1)
Node* optimal(Node* head){
    if(head == NULL || head->next == NULL) return head;
    Node* current = head;
    Node* last = NULL;
    while(current != NULL){
        last = current->back;
        current->back = current->next;
        current->next = last;
        current = current->back;
    }
    return last->back;
}

int main(){
    vector<int> arr = {4, 3, 7, 5};
    Node* head = convertArr2DLL(arr);
    Node* newHead = optimal(head);
    print(newHead);
    return 0;
}