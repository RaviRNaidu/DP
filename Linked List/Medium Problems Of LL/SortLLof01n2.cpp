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

// //tc -> o(2n + n log n)   sc -> o(n)
// Node* brute(Node* head){
//     if(head == NULL || head->next == NULL) return head;
//     vector<int> arr;
//     Node* temp = head;
//     while(temp != NULL){              //tc -> o(n)
//         arr.push_back(temp->data);
//         temp = temp->next;
//     }

//     sort(arr.begin(),arr.end());    // tc -> o(n log n)
//     int i = 0;
//     temp = head;
//     while(temp != NULL){            //tc -> o(n)
//         temp->data = arr[i];
//         i++;
//         temp = temp->next;
//     }
//     return head;
// }

//tc -> o(2n) sc -> o(1)
Node* brute1(Node* head){
    if(head == NULL || head->next == NULL) return head;
    Node* temp = head;
    int cnt0 = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    while(temp != NULL){            // o(n)
        if(temp->data == 0){
            cnt0++;
        }
        else if (temp->data == 1){
            cnt1++;
        }
        else{
            cnt2++;
        }
        temp = temp->next;
    }

    temp = head;
    while(temp != NULL){            //o(n)
        if(cnt0 != 0){
            temp->data = 0;
            cnt0--;
        }
        else if(cnt1 != 0){
            temp->data = 1;
            cnt1--;
        }
        else if(cnt2 != 0){
            temp->data = 2;
            cnt2--;
        }
        temp = temp->next;
    }
    return head;
}

//DONE MY MEEE and IT ONLY WORKS IF IT IS HAS ALL THE THREE ELEMENTS (1, 2, 0) even if any 1 is missing it wont work
Node* optimal(Node* head){
    Node* temp = head;
    Node* prev0 = NULL;
    Node* prev1 = NULL;
    Node* prev2 = NULL;
    Node* first0 = NULL;
    Node* first1 = NULL;
    Node* first2 = NULL;
    while(temp != NULL){
        if(temp->data == 0){
            if(prev0 == NULL){
                prev0 = temp;
                first0 = prev0;
            }
            else{
                prev0->next = temp;
                prev0 = temp;
            }
        }
        else if(temp->data == 1){
            if(prev1 == NULL){
                prev1 = temp;
                first1 = prev1;
            }
            else{
                prev1->next = temp;
                prev1 = temp;
            }
        }
        else{
            if(prev2 == NULL){
                prev2 = temp;
                first2 = prev2;
            }
            else{
                prev2->next = temp;
                prev2 = temp;
            }
        }
        temp = temp->next;
    }
    prev0->next = first1;
    prev1->next = first2;
    prev2->next = nullptr;
    return first0;
}

Node* optimalStriver(Node* head){
    if(head == NULL || head->next == NULL) return head;
    
    Node* zeroHead = new Node(-1);
    Node* oneHead = new Node(-1);
    Node* twoHead = new Node(-1);
    
    Node* zero = zeroHead;
    Node* one = oneHead;
    Node* two = twoHead;

    Node* temp = head;

    while(temp != NULL){
        if(temp->data == 0){
            zero->next = temp;
            zero = zero->next;
        }
        else if(temp->data == 1){
            one->next = temp;
            one = one->next;
        }
        else{
            two->next = temp;
            two = two->next;
        }
        temp = temp->next;
    }
    // if(oneHead->next == NULL){
    //     zero->next = twoHead->next;
    // }
    // if(oneHead->next != NULL)zero->next = oneHead->next;
    // if(twoHead->next != NULL)one->next = twoHead->next;

    zero->next = (oneHead->next != NULL) ? (oneHead->next) : twoHead->next;
    one->next = twoHead->next;
    two->next = NULL;

    Node* newHead = zeroHead->next;

    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return newHead;
}

int main(){
    vector<int> arr = {1, 0, 2, 0, 1};
    Node* head = convertArray2LinkedList(arr);
    Node* newHead = optimalStriver(head);
    print(newHead);
    return 0;
}