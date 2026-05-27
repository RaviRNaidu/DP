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

//  TC -> O(n * n log n + m * m log m)    SC -> O(N)
Node* brute(Node* head1, Node* head2){
    Node* temp1 = head1;
    Node* temp2 = head2;
    map<Node*, int> mpp;
    while(temp1 != NULL){           //tc -> o(n * n log n)
        mpp[temp1]++;
        temp1 = temp1->next;
    }

    while(temp2 != NULL){           //tc -> o(m * m log m)
        if(mpp.find(temp2) != mpp.end()){
            return temp2;
        }
        temp2 = temp2->next;
    }
    return NULL;
}


//TC -> O(N1 + N2 + MAX(N1,N2))      SC -> O(1)
//DONE BY ME
Node* better(Node* head1, Node* head2){
    Node* temp1 = head1;
    Node* temp2 = head2;
    int N1 = 0;
    int N2 = 0;
    while(temp1 != NULL){           // tc -> o(n1)
        N1 += 1;
        temp1 = temp1->next;
    }
    while(temp2 != NULL){           //tc -> o(n2)
        N2 += 1;
        temp2 = temp2->next;
    }
    
    int d = abs(N1 - N2);
    temp1 = head1;
    temp2 = head2;
    if(N1 > N2){
        while(d != 0){
            temp1 = temp1->next;
            d--;
        }
    }
    else{
        while(d != 0){
            temp2 = temp2->next;
            d--;
        }
    }

    while(temp1 != NULL){           //tc -> o(max(n1,n2))
        if(temp1 == temp2){
            return temp1;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return NULL;
}

// TC -> O(N1) + O(N2) + O(N1 - N2) + O(N2) => O(2N1) + O(N2)           SC -> O(1)
Node* functionn(Node* head1, Node* head2, int  d){
    Node* temp1 = head1;
    Node* temp2 = head2;
    while(d != 0){
        temp1 = temp1->next;
        d--;
    }

    while(temp1 != temp2){
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return temp1;
}

Node* better2(Node* head1, Node* head2){
    Node* temp1 = head1;
    Node* temp2 = head2;
    int N1 = 0;
    int N2 = 0;
    while(temp1 != NULL){           // tc -> o(n1)
        N1 += 1;
        temp1 = temp1->next;
    }
    while(temp2 != NULL){           //tc -> o(n2)
        N2 += 1;
        temp2 = temp2->next;
    }
    
    if(N1 > N2){
        return functionn(head1, head2, N1-N2);
    }
    else{
        return functionn(head2, head1, N2-N1);
    }
}

//TC -> O(N + M)   SC -> O(1)
Node* optimal(Node* head1, Node* head2){
    Node* temp1 = head1;
    Node* temp2 = head2;
    while(temp1 != temp2){
        temp1 = temp1->next;
        temp2 = temp2->next;

        if(temp1 == temp2) return temp1;

        if(temp1 == NULL) temp1 = head2;
        if(temp2 == NULL) temp2 = head1;
    }
    return temp1;
}