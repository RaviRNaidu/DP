#include<bits/stdc++.h>
using namespace std;

//TC - > O(N) + O(N) CUZ WE ARE ADDING ALL THE STRINGS
//SC -> O(N)
string PrefixToInfix(string s){
    int n = s.length();
    stack<string> st;
    for(int i=n-1;i>=0;i--){
        if(isalnum(s[i])){
            st.push(string(1,s[i]));
        }
        else{
            string opr1 = st.top();
            st.pop();
            string opr2 = st.top();
            st.pop();
            string updated = "(" + opr1 + s[i] + opr2 + ")";
            st.push(updated);
        }
    }

    return st.top();
}


int main(){
    string s;
    cin>>s;
    string infix = PrefixToInfix(s);
    cout<<infix<<endl;
    return 0;
}