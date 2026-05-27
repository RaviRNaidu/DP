#include<bits/stdc++.h>
using namespace std;

struct Node {
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

//storing the first element along with pointer pointing to null
int main(){
    vector<int> arr = {2,3,4,5};
    Node* y = new Node(arr[2], nullptr);
    cout << y;
    return 0;
}

//converting the whole array to linked list and printing the head/starting point of LL
int main(){
    vector<int> arr = {2,3,4,5}; 
    Node* head = convertArray2LinkedList(arr);
    cout<<head->data;
    return 0;
}

//traversing in the LL and also printing the whole LL
//tc --> o(n)
int main(){
    vector<int> arr = {2,3,4,5}; 
    Node* head = convertArray2LinkedList(arr);
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data<<" ";
        temp = temp->next;
    }
    return 0;
}