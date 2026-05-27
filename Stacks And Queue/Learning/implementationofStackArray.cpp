#include<bits/stdc++.h>
using namespace std;

class stackImp{
    int top = -1;
    int st[10];

    void push(int x){
        if(top >= 10){
            cout<<"stack is full"<<endl;
        }
        else{
            top++;
            st[top] = x;
        }
    }

    int top(){
        if(top == -1){
            return -1;
        }
        else{
            return st[top];
        }
    }

    void pop(){
        if(top == -1){
            cout<<"stack is empty"<<endl;
        }
        else{
            top--;
        }
    }

    int size(){
        return (top + 1);
    }
};

class queueImp{
    int size = 10;
    int currSize = 0;
    int front = -1;
    int rear = -1;
    int q[4];

    void push(int x){
        if(front == (rear + 1) % 4){
            cout<<"queue is full"<<endl;
        }
        if(currSize == 0){
            front = 0;
            rear = 0;
        }
        else{
            rear = (rear + 1) % 4;
        }
        q[rear] = x;
        currSize += 1;
    }

    int top(){
        if(currSize == 0){
            return -1;
        }
        else{
            return q[front];
        }
    }

    int pop(){
        if(currSize == 0){
            cout<<"queue is empty"<<endl;
        }
        int del = q[front];
        if(currSize == 1){
            front = rear = -1;
        }
        else{
            front = (front + 1) % 4;
        }
        currSize -= 1;
        return del;
    }

    int size(){
        return currSize;
    }
};
