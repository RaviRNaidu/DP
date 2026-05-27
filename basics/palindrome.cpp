#include<bits/stdc++.h>
using namespace std;

// void palindrome(int n){
//     cin>>n;
//     int num=n%10;
// }

int main(){
    int n;
    cin>>n;
    int revNum=0;
    int orgNum=n;
    while(n>0){
        int p=n%10;
        revNum=(revNum*10)+p;
        n=n/10;
    }
    if(revNum==orgNum) cout<< "True";
    else cout<< "False";
}