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

//TC -> O(N * M) + N logN    SC -> O(N) + O(N)
Node* brute(vector<Node*> lists){
    vector<int> arr;
    for(int i=0;i<lists.size();i++){
        Node* temp = lists[i];
        while(temp != NULL){            //tc -> o(n*m)
            arr.push_back(temp->data);
            temp = temp->next;
        }
    }

    // n*m = N
    sort(arr.begin(),arr.end());        //N logN

    Node* NewHead = convertArray2LinkedList(arr);   //o(N)
    return NewHead;
}








//merge two sorted lists
Node* merge2SLists(Node* head1, Node* head2){
    Node* dummy = new Node(-1);
    Node* mover = dummy;
    while(head1 != NULL && head2 != NULL){
        if(head1->data < head2->data){
            mover->next = head1;
            mover = head1;
            head1 = head1->next;
        }
        else{
            mover->next = head2;
            mover = head2;
            head2 = head2->next;
        }
    }
    if(head1){
        mover->next = head1;
    }
    else mover->next = head2;
    return dummy->next;
}
// TC -> O(N1 + N2) + O(N1 + N2 + N3) + O((N1 + N2 + N3 + N4)
// N (2N + 3N + 4N......KN)
// N (1+2+3....K)
// N * (K * K+1/2)

//SC -> O(1)
Node* better(vector<Node*> lists){
    Node* head = lists[0];                  
    for(int i=1;i<lists.size();i++){
        head = merge2SLists(head, lists[i]);
    }
    return head;
}

//TC -> O(K LOG K) + O(N * K * LOG K)       SC -> O(K)
//OPERATION ON PRIORITY QUEUE TAKE LOG size of pq
Node* optimal(vector<Node*> lists){
    priority_queue<pair<int,Node*>,vector<pair<int,Node*>>,greater<pair<int,Node*>>> pq;
    //TC -> k log k
    for(int i=0;i<lists.size();i++){                // k
        if(lists[i]){
            pq.push({lists[i]->data, lists[i]});    // TC -> o(log k)
        }
    }

    Node* dummy = new Node(-1);
    Node* temp = dummy;
    // TC -> N * K * LOG N
    while(! pq.empty()){            //TC -> K*N
        auto it = pq.top();// LOG K
        pq.pop();//LOG K
        if(it.second->next){
            pq.push({it.second->next->data, it.second->next});//LOG K
        }
        temp->next = it.second;
        temp = temp->next;
    }
    return dummy->next;
}

int main(){
    vector<int> arr = {2,4,5};
    vector<int> arr2 = {1,5};
    vector<int> arr3 = {1,1,3,7};
    vector<int> arr4 = {8,11};
    Node* head1 = convertArray2LinkedList(arr);
    Node* head2 = convertArray2LinkedList(arr2);
    Node* head3 = convertArray2LinkedList(arr3);
    Node* head4 = convertArray2LinkedList(arr4);
    vector<Node*> lists = {head1, head2, head3, head4};
    Node* newHead = optimal(lists);
    print(newHead);
    return 0;
}
