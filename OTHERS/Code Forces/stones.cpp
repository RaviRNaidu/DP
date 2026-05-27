#include<bits/stdc++.h>
using namespace std;

int removal(int n, string s){
    int cnt = 0;
    int i = 0;
    while(i < n){
        int j = i+1;
        while(j < n){
            if(s[i] == s[j]){
                cnt++;
                j++;
            }
            else{
                i = j;
                break;
            }
        }
        if(j >= n) return cnt;
    }

    return cnt;
}

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    cout<<removal(n , s)<<endl;
    return 0;
}