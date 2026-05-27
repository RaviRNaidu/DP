#include<bits/stdc++.h>
using namespace std;


//TC -> O(N) + O(N) -> O(N)     SC -> O(N)
string PostToPrefix(string s){
    int n = s.length();
    stack<string> st;
    for(int i=0;i<n;i++){
        if(isalnum(s[i])){
            st.push(string(1, s[i]));
        }
        else{
            string opr1 = st.top();
            st.pop();
            string opr2 = st.top();
            st.pop();
            string updated = s[i] + opr2 + opr1;
            st.push(updated);
        }
    }
    return st.top();
}

int main(){
    string s;
    cin>>s;
    string prefix = PostToPrefix(s);
    cout<<prefix<<endl;
    return 0;
}