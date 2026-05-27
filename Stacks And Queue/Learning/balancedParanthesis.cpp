#include<bits/stdc++.h>
using namespace std;

//TC -> O(N) SC-> O(N)
bool checking(string s){
    stack<char> st;
    int n = s.length();
    for(int i=0;i<n;i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            st.push(s[i]);
        }
        else{
            if(st.empty()){
                return false;
            }
            char pop = st.top();
            st.pop();
            if((s[i] == ')' && pop == '(') ||
               (s[i] == '}' && pop == '{') ||
               (s[i] == ']' && pop == '[')){
                continue;
            }
            else{
                return false;
            }
        }
    }
    if(st.empty()){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    string s;
    cin>>s;
    int n = checking(s);
    cout<<n<<endl;
    return 0;
}