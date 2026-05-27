#include<bits/stdc++.h>
using namespace std;

class Node{
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

void print(Node* Newhead){
    while(Newhead != NULL){
        cout<<Newhead->data<<" ";
        Newhead = Newhead->next;
    }
}

Node* convertArr2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}


Node* addingELtoHEAD(Node* head, int num){

    // this is calling the second function
    
    // Node* temp = new Node(num); 
    // temp->next = head;
    // return temp;


    Node* temp = new Node(num, head);
    return temp;
}

Node* addtoLAST(Node* head, int num){
    if(head == NULL){
        return new Node(num);
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    Node* newel = new Node(num,nullptr);
    temp->next = newel;
    return head;
}

//tc ->o(1) best case and o(n) average and worst case
Node* addtoKposition(Node* head, int num, int k){
    if(head == NULL){
        if(k == 1){
            return new Node(num);
        }
    }
    if(k == 1){
        Node* temp = new Node(num,head);
        return temp;
    }
    int cnt = 0;
    Node* temp = head;
    while(temp != NULL){
        cnt++;
        if(cnt == k-1){
            Node* newel = new Node(num);
            newel->next = temp->next;
            temp->next = newel;
            break;
        }
        temp = temp->next;
    }
    return head;
}

// insert the num before the value k
Node* addbeforetheNUM(Node* head, int num, int k){
    if(head == NULL){
        return NULL;
    }
    if(head->data == k){
        Node* temp = new Node(num,head);
        return temp;
    }
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        if(temp->data == k){
            Node* newel = new Node(num,prev->next);
            prev->next = newel;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int num;
    cin>>num;
    int k;
    cin>>k;
    Node* head = convertArr2LL(arr);
    Node* newHead = addbeforetheNUM(head, num, k);
    print(newHead);
    return 0;
}