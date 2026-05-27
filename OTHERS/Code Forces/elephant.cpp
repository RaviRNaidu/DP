#include<bits/stdc++.h>
using namespace std;

int finding(int n){
    int cnt = 0;
    while(n > 0){
        if(n >= 5){
            cnt++;
            n = n - 5;
            continue;
        }
        if(n >= 4){
            cnt++;
            n = n - 4;
            continue;
        }
        if(n >= 3){
            cnt++;
            n = n - 3;
            continue;
        }
        if(n >= 2){
            cnt++;
            n = n - 2;
            continue;
        }
        if(n >= 1){
            cnt++;
            n = n - 1;
            continue;
        }
    }
    return cnt;
}

int main(){
    int n;
    cin>>n;
    cout<<finding(n)<<endl;
    return 0;
}