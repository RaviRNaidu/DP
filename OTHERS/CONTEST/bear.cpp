#include<bits/stdc++.h>
using namespace std;

int finding(int a, int b){
    int cnt = 0;
    while(a <= b){
        a = a * 3;
        b = b * 2;
        cnt++;
    }
    return cnt;
}

int main(){
    int a, b;
    cin>>a>>b;
    cout<<finding(a,b)<<endl;
    return 0;
}