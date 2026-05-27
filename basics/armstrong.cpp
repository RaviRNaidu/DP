#include<bits/stdc++.h>
using namespace std;

int counter(int n){
    int counter=0;
    while(n>0){
        counter = counter+1;
        n=n/10;
    }
    return counter;
}
// int armstrong(int n){
//     int dup=n;
//     int ans=0;
//     while(n>0){
//         int id=n%10;
//         ans = ans+(id*3);
//         n = n/10;
//     }
//     if(ans==dup) cout<< "true";
//     else cout<< "false";
// }

int main(){
    int n;
    cin>>n;
    int k = to_string(n).length();
    // int armAns=counter(n);
    int dup=n;
    int ans=0;
    while(n>0){
        int id=n%10;
        ans = ans+(pow(id,k));
        n = n/10;
    }
    if(ans==dup) cout<< "true";
    else cout<< "false";
    return 0;
}