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

//deleting the head of the DLL
Node* deleteingHEAD(Node* head){
    if(head == NULL || head->next == nullptr) return NULL;
    Node* temp = head;
    head = head->next;
    head->back = nullptr;
    temp->next = nullptr;
    delete temp;
    return head;
}

//deleting the tail of the DLL
// Node* deleteingTAIL(Node* head){
//     if(head == NULL || head->next == nullptr) return NULL;
//     Node* temp = head;
//     Node* prev = NULL;
//     while(temp->next != NULL){
//         prev = temp;
//         temp = temp->next;
//     }
//     prev->next = nullptr;
//     temp->back = nullptr;
//     delete temp;
//     return head;
// }
//u dont have to store the prev cuz u can straight away get the previous by doing the back


Node* deleteingTAIL(Node* head){
    if(head == NULL || head->next == nullptr) return NULL;
    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    Node* newTail = tail->back;
    newTail->next = nullptr;
    tail->back = nullptr;
    delete tail;
    return head;
}

//me and this is wrong WRONGG
// Node* deleteingTAIL(Node* head, int k){
//     if(head == NULL) return NULL;
//     if(head->next == nullptr){
//         if(k == 1){
//             return NULL;
//         }
//     }
//     if(k == 1){
//         Node* temp = head->next;
//         temp->back = nullptr;
//         head->next = nullptr;
//         delete head;
//         return temp;
//     }
//     Node* temp = head;
//     int cnt = 0;
//     while(temp != NULL){
//         cnt++;
//         if(cnt == k){
//             Node* prev = temp->back;
//             Node* nexxt = temp->next;
//             prev->next = temp->next;
//             nexxt->back = temp->back;
//             temp->back = nullptr;
//             temp->next = nullptr;
//             delete temp;
//             return head;
//         }
//         temp = temp->next;
//     }
// }

//deleting the kth element/node in DLL
Node* deletingKthElement(Node* head, int k){
    if(head == NULL) return NULL;

    Node* temp = head;
    int cnt = 0;
    while(temp != NULL){
        cnt++;
        if(cnt == k){
            break;
        }
        temp = temp->next;
    }

    if(temp == NULL) return head;

    Node* prev = temp->back;
    Node* front = temp->next;

    if(prev == NULL && front == NULL){
        return NULL;
    }

    else if(prev == NULL){
        return deleteingHEAD(head);
    }

    else if(front == NULL){
        return deleteingTAIL(head);
    }
    
    prev->next = front;
    front->back = prev;
    
    temp->back = nullptr;
    temp->next = nullptr;
    
    delete temp;
    return head;
}

// me
//check yt for strivers
Node* deletingElement(Node* head, int k){
    if(head == NULL) return NULL;
    if(head->next == NULL) return head;
    Node* temp = head;
    while(temp != NULL){
        if(temp->data == k){
            if(temp->next == NULL){
                return deleteingTAIL(head);
            }
            else{
                Node* prev = temp->back;
                Node* front = temp->next;
                prev->next = front;
                front->back = prev;
                temp->back = nullptr;
                temp->next = nullptr;
                delete temp;
                return head;
            }
        }
        temp = temp->next;
    }
    return head;
}

int main(){
    vector<int> arr = {4, 3, 7, 5};
    Node* head = convertArr2DLL(arr);
    Node* newHead = deletingElement(head, 10);
    print(newHead);
    return 0;
}