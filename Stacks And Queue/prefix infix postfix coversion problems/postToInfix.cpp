#include<bits/stdc++.h>
using namespace std;


//TC - > O(N) + O(N) CUZ WE ARE ADDING ALL THE STRINGS
//SC -> O(N)
string PostfixToInfix(string s){
    stack<string> st;
    int n = s.length();
    for(int i=0;i<n;i++){
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 0 && s[i] <= 9)){
            st.push(string(1, s[i]));
        }
        else{
            string opr2 = st.top();
            st.pop();
            string opr1 = st.top();
            st.pop();
            st.push("(" + opr1 + s[i] + opr2 + ")");
        }
    }

    return st.top();
}

int main(){
    string s;
    cin>>s;
    string infix = PostfixToInfix(s);
    cout<<infix<<endl;
    return 0;
}