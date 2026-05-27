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

//tc -> o(2n + n log n)   sc -> o(n)
Node* brute(Node* head){
    if(head == NULL || head->next == NULL) return head;
    vector<int> arr;
    Node* temp = head;
    while(temp != NULL){              //tc -> o(n)
        arr.push_back(temp->data);
        temp = temp->next;
    }

    sort(arr.begin(),arr.end());    // tc -> o(n log n)
    int i = 0;
    temp = head;
    while(temp != NULL){            //tc -> o(n)
        temp->data = arr[i];
        i++;
        temp = temp->next;
    }
    return head;
}











// recursion depth is log n
// TC -> O(log n) * (n + n/2)       SC -> o(log n) for recursive stack space
Node* findMiddle(Node* head){
    Node* slow = head;
    Node* fast = head->next;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* mergeLL(Node* head1, Node* head2){
    Node* dummy = new Node(-1);
    Node* temp = dummy;
    while(head1 != NULL && head2 != NULL){
        if(head1->data < head2->data){
            temp->next = head1;
            temp = head1;
            head1 = head1->next;
        }
        else{
            temp->next = head2;
            temp = head2;
            head2 = head2->next;
        }
    }

    if(head1) temp->next = head1;
    else temp->next = head2;

    return dummy->next;
}

Node* optimal(Node* head){
    if(head == NULL || head->next == NULL) return head;

    Node* middle = findMiddle(head);        //tc -> o(n/2)
    Node* lefthead = head;                  
    Node* rightHead = middle->next;
    middle->next = NULL;

    lefthead = optimal(lefthead);
    rightHead = optimal(rightHead);

    return mergeLL(lefthead, rightHead);
}

int main(){
    vector<int> arr = {5, 6, 1, 2, 1};
    Node* head = convertArray2LinkedList(arr);
    Node* newHead = optimal(head);
    print(newHead);
    return 0;
}