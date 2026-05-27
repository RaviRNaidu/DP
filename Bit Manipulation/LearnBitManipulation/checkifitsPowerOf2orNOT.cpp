#include<bits/stdc++.h>
using namespace std;

//using left shift
bool check(int n){
    if((n & (n-1)) == 0){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    int n;
    cin>>n;
    if(check(n) == 1){
        cout<<"Yes it is a set bit"<<endl;
    }
    else{
        cout<<"No it not a set bit"<<endl;
    }
    return 0;
}