#include<bits/stdc++.h>
using namespace std;

int sum=0;
void print(int n){
    if(n==0){
        cout<<"the sum of natural numbers is: "<<sum;
        return;
    }
    sum = sum + n;
    n--;
    print(n);
}
// using loops
// void loops(int n){
//     int sum=0;
//     for(int i=1;i<=n;i++){
//         sum = sum+i;
//     }
//     cout<<"the sum of natural numbers is: "<<sum;
// }

void param(int i,int sum){
    if(i<1){
        cout<<sum;
        return;
    } 
    param(i-1,sum+i);
}

int funct(int n){
    if(n==0) {
        return 0;
    }
    return n+funct(n-1);
}

int main(){
    int n;
    cin>>n;
    cout<<funct(n);
    return 0;
}