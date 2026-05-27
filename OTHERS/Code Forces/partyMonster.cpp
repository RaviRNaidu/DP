#include<bits/stdc++.h>
using namespace std;

string checking(int n, string str){
    if(n%2 != 0) return "NO";
    int open = 0;
    int close = 0;
    for(int i=0;i<str.length();i++){
        if(str[i] == '('){
            open++;
        }
        else{
            close++;
        }
    }

    if(open == close) return "YES";
    return "NO";
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string str;
        cin>>str;

        string ans = checking(n, str);
        cout<<ans<<endl;
    }
    return 0;
}