#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    string url;
    Node* forward;
    Node* back;

    public:
    Node(string url1, Node* forward1, Node* back1){
        url = url1;
        forward = forward1;
        back = back1;
    }

    public:
    Node(string url1){
        url = url1;
        forward = nullptr;
        back = nullptr;
    } 
};

class Browser{
    Node* current;

    public:
    Browser(string &homepage){
        current = new Node(homepage);
    }

    void visit(string url){
        Node* newNode = new Node(url);
        current->forward = newNode;
        newNode->back = current;
        current = newNode;
    }

    string back(int steps){
        while(steps > 0){
            if(current->back){
                current = current->back;
            }
            else{
                break;
            }
            steps--;
        }
        return current->url;
    }

    string forward(int steps){
        while(steps > 0){
            if(current->forward){
                current = current->forward;
            }
            else{
                break;
            }
            steps--;
        }
        return current->url;
    }
};