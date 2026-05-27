#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    int value;
    int cnt;
    Node* next;
    Node* prev;

    Node(int key1, int value1){
        key = key1;
        value = value1;
        cnt = 1;
    }
};

struct List{
    int size;
    Node* head;
    Node* tail;
    List(){
        head = new Node(-1, -1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addFront(Node* node){
        Node* front = head->next;
        head->next = node;
        node->prev = head;
        node->next = front;
        front->prev = node;
        size++;
    }

    void removeNode(Node* temp){
        Node* back = temp->prev;
        Node* front = temp->next;
        back->next = front;
        front->prev = back;
        size--;

    }
};

class LFUCache{
    unordered_map<int, Node*> keyMap;
    unordered_map<int, List*> freqMap;
    int maxSizeCache;
    int minFreq;
    int curSize;

    public:
    LFUCache(int capacity){
        maxSizeCache = capacity;
        curSize = 0;
        minFreq = 0;
    }

    void updateFreqList(Node* node){

    }

    int get(int key){
        if(keyMap.find(key) != keyMap.end()){
            Node* node = keyMap[key];
            int val = node->value;
            updateFreqList(node);
            return val;
        }
        else{
            return -1;
        }
    }

    void put(int key, int value){
        if(maxSizeCache == 0){
            return;
        }
        if(keyMap.find(key) != keyMap.end()){
            Node* node = keyMap[key];
            node->value = value;
            updateFreqList(node);
        }
        else{
            
        }
    }
};