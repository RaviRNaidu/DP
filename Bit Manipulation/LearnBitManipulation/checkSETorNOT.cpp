#include<bits/stdc++.h>
using namespace std;

// TC is o(1) cuz the computer performs bitwise operation extreamly fast

// using right shift
bool checking(int n, int i){
    if(n & (1<<i)){
        return true;
    }
    else{
        false;
    }
}

//using left shift
bool checkingg(int n, int i){
    if(((n>>i) & 1) == 1 ){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    int n, i;
    cin>>n;
    cout<<"enter the bit number: ";
    cin>>i;
    if(!checking(n,i)){
        cout<<"Not a set"<<endl;
    }
    else{
        cout<<"Is a Set"<<endl;
    }
    return 0;
}