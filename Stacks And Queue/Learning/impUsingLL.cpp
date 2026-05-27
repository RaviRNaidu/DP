#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }

    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
};

class stackzz{
    Node* top = new Node(NULL);
    int size = 0;

    void push(int x){
        Node* newNode = new Node(x);
        newNode->next = top;
        top = newNode;
        size++;
    }

    int pop(){
        int del = top->data;
        Node* rem = top;
        top = top->next;
        free(rem);
        size--;
        return del;
    }

    int top(){
        return top->data;
    }

    int size(){
        return size;
    }
};

class queuezz{
    Node* front = NULL;
    Node* rear = NULL;
    int size = 0;

    void push(int x){
        Node* newNode = new Node(x);
        if(rear == NULL && front == NULL){
            rear = front = newNode;
        }
        else{
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    void pop(){
        if(rear == front){
            Node* temp = front;
            free(temp);
            rear = front = NULL;
        }
        else{
            Node* temp = front;
            front = front->next;
            free(temp);
        }
        size--;
    }

    int top(){
        if(front == NULL){
            cout<<"empty"<<endl;
            return -1;
        }
        else return front->data;
    }

    int size(){
        return size;
    }
};

class stackUsingQueues{
    queue<int> q;

    void push(int x){
        int sizee = q.size();
        if(sizee == 0){
            q.push(x);
        }
        else{
            q.push(x);
            while(q.front() != x){
                int el = q.front();
                q.push(el);
                q.pop();
            }
        }
    }

    void pop(){
        q.pop();
    }

    int top(){
        return q.front();
    }

    int size(){
        return q.size();
    }
};

class queueUsingStack{
    stack<int> st1;
    stack<int> st2;
    int size = 0;

    //TC -> O(2N)
    void push(int x){
        int n = st1.size();
        while(st1.size()){
            st2.push(st1.top());
            st1.pop();
        }

        st1.push(x);

        while(st2.size()){
            st1.push(st2.top());
            st2.pop();
        }
    }

    void pop(){
        st1.pop();
    }

    int front(){
        st1.top();
    }

    int size(){
        st1.top();
    }

};

class queueUsingStack{
    stack<int> st1;
    stack<int> st2;
    int size = 0;

    //TC -> O(1)
    void push(int x){
        st1.push(x);
    }

    //TC -> o(N) ->ocacionally 
    void pop(){
        if(st2.empty() != 0){
            st2.pop();
        }
        else{
            while(st1.size()){
                st2.push(st1.top());
                st1.pop();
            }
            st2.pop();
        }
    }

    //TC -> o(N) ->ocacionally 
    void top(){
        if(st2.empty() != 0){
            st2.top();
        }
        else{
            while(st1.size()){
                st2.push(st1.top());
                st1.pop();
            }
            st2.top();
        }
    }
};

