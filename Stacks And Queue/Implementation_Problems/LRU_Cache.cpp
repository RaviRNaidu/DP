#include<bits/stdc++.h>
using namespace std;

class LRUCache{
    class Node{
        public:
        int key;
        int data;
        Node* next;
        Node* prev;

        public:
        Node(int key1,int data1, Node* next1, Node* prev1){
            int data = data1;
            int key = key1;
            Node* next = next1;
            Node* prev = prev1;
        }

        public:
        Node(int key1, int data1){
            int data = data1;
            int key = key1;
            Node* next = nullptr;
            Node* prev = nullptr;
        }
    };

    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    
    int cap;

    unordered_map<int,Node*> mpp;

    LRUCache(int capacity){
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void inseartAfterHead(Node* temp){      //TC -> O(1)
        Node* front = head->next;
        head->next = temp;
        temp->next = front;
        temp->prev = head;
        front->prev = temp;
    }

    void delNode(Node* node){               //TC -> O(1)
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = nullptr;
        node->prev = nullptr;
    }

    int get(int key){                           //TC -> O(1)
        if(mpp.find(key) != mpp.end()){
            Node* node = mpp[key];
            delNode(node);
            inseartAfterHead(node);
            return node->data;
        }
        else{
            return -1;
        }
    }

    void put(int key, int val){                 //TC -> O(1)
        if(mpp.find(key) != mpp.end()){
            Node* node = mpp[key];
            node->data = val;
            delNode(node);
            inseartAfterHead(node);
        }
        else{
            if(mpp.size() == cap){
                Node* deleteNode = tail->prev;
                mpp.erase(deleteNode->key);
                delNode(deleteNode);
            }
            Node* newNode = new Node(key,val);
            inseartAfterHead(newNode);
            mpp.insert({key,newNode});
        }
    }
};

// Driver code
// int main() {
//     // Create cache with capacity 2
//     LRUCache LRUCache(2);

//     // Put values in cache
//     put(1, 1);
//     put(2, 2);

//     // Get value for key 1
//     cout << cache.get(1) << endl; 

//     // Insert another key (evicts key 2)
//     cache.put(3, 3);

//     // Key 2 should be evicted
//     cout << cache.get(2) << endl; 

//     // Insert another key (evicts key 1)
//     cache.put(4, 4);

//     // Key 1 should be evicted
//     cout << cache.get(1) << endl; 

//     // Key 3 should be present
//     cout << cache.get(3) << endl; 

//     // Key 4 should be present
//     cout << get(4) << endl; 

//     return 0;
// }