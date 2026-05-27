#include <bits/stdc++.h>
using namespace std;

void print1(int n){
    int i,j;
    for(i = 0;i<n;i++){
        for (j = 0;j<n;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}

void print4(int n){
    int i,j;
    for(i=1;i<=n;i++){
        for ( j=1; j<=i; j++){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}
void print5(int n){
    int i,j;
    for(i=1;i<=n;i++){
        for ( j=n; j>=i; j--){
            cout<<"*";
        }
        cout<<endl;
    }
}
void print6(int n){
    int i,j;
    for(i=n;i>=1;i--){
        for ( j=1; j<=i; j++){
            cout<<j<<"";
        }
        cout<<endl;
    }
}
void print7(int n){
    int i,j;
    for(i=0;i<n;i++){
        for ( j=0; j<n-i-1; j++){
            cout<<" ";
        }
        for(j=0;j<2*i+1;j++){
            cout<<"*";
        }
        for(j=0; j<n-i-1; j++){
            cout<<" ";
        }
        cout<<endl;
    }
}
void print8(int n){
    int i,j;
    for(i=0;i<n;i++){
        for ( j=0; j<i; j++){
            cout<<" ";
        }
        for(j=0;j<2*n-(2*i+1);j++){
            cout<<"*";
        }
        for(j=0; j<i; j++){
            cout<<" ";
        }
        cout<<endl;
    }
}
void print9(int n){
    int i,j;
    for(i=0;i<n;i++){
        for ( j=0; j<n-i-1; j++){
            cout<<" ";
        }
        for(j=0;j<2*i+1;j++){
            cout<<"*";
        }
        for(j=0; j<n-i-1; j++){
            cout<<" ";
        }
        cout<<endl;
    }
    for(i=0;i<n;i++){
        for ( j=0; j<i; j++){
            cout<<" ";
        }
        for(j=0;j<2*n-(2*i+1);j++){
            cout<<"*";
        }
        for(j=0; j<i; j++){
            cout<<" ";
        }
        cout<<endl;
    }
}
void print10(int n){
    int i,j;
    for(i=1;i<=n;i++){
        for(j=0;j<i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    print10(n);
}