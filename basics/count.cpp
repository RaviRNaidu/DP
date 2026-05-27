#include<bits/stdc++.h>
using namespace std;

void countDigit(int n) {
        int counter=0;
        while (n>0){
            counter=counter+1;
            n=n/10;
        }
        cout<<"Number of Digits in N: "<<counter;
    }
    
void reverse(int n){
    int revNum = 0;
    while(n!=0){
        int i=n%10;
        if(revNum > INT_MAX / 10 || (revNum == INT_MAX / 10 && i > 7)) // overflow
        revNum = (revNum * 10)+ i;
        n = n/10;
    }
    cout<<"reversed order is: "<<revNum;
}

int main(){
    int n;
    cout<<"enter the number: "<<endl;
    cin>>n;
    reverse(n);
    return 0;
}