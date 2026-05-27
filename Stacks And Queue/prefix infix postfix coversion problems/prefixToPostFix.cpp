#include<bits/stdc++.h>
using namespace std;


//TC -> O(N) + O(N) -> O(N)     SC -> O(N)
string PrefixToPostfix(string s){
    int n = s.length();
    stack<string> st;
    for(int i=n-1;i>=0;i--){
        if(isalnum(s[i])){
            st.push(string(1, s[i]));
        }
        else{
            string opr1 = st.top();
            st.pop();
            string opr2 = st.top();
            st.pop();
            string updated = opr1 + opr2 + s[i];
            st.push(updated);
        }
    }
    return st.top();
}

int main(){
    string s;
    cin>>s;
    string postfix = PrefixToPostfix(s);
    cout<<postfix<<endl;
    return 0;
}