#include<bits/stdc++.h>
using namespace std;

int factorial=1;
void print(int i,int n){
    if(i>n){
        cout<<"the factorial is: "<<factorial;
        return;
    }
    factorial = factorial*i;
    print(i+1,n); 
}

int main(){
    int n;
    cin>>n;
    print(1,n);
}