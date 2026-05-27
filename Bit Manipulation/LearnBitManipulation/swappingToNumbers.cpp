#include<bits/stdc++.h>
using namespace std;


//using temp
void swappingg(int a, int b){
    int temp = a;
    a = b;
    b = temp;
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
}

//without using extra variable
void swapusingXOR(int a, int b){
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
}

int main(){
    int a,b;
    cin>>a;
    cin>>b;
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    cout<<"after swapping : "<<endl;
    swapusingXOR(a,b);
    return 0;
}