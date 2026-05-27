#include<bits/stdc++.h>
using namespace std;

int precedence(char ch){
    if(ch == '^'){
        return 3;
    }
    else if((ch == '*') || (ch == '/')){
        return 2;
    }
    else if((ch == '+') || (ch == '-')){
        return 1;
    }
    else{
        return 0;
    }
}


// TC -> O(N) + O(N)    SC -> O(N) + O(N)
string InfixToPostfix(string s){
    stack<char> st;
    int n = s.length();
    string postfix = "";
    for(int i=0;i<n;i++){
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 0 && s[i] <= 9)){   //O(1)
            postfix += s[i];
        }
        else if(s[i] == '('){                                                                           //O(1)
            st.push(s[i]);
        }
        else if(s[i] == ')'){                                           //O(N) WORST CASE
            while(!st.empty() && st.top() != '('){
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && precedence(st.top()) >= precedence(s[i])){         //O(N) WORST CASE 
                postfix += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){                         //O(N) WORST CASE, EITHER ONE OF THEM WILL BE O(N)
        postfix += st.top();
        st.pop();
    }
    
    return postfix;
}

int main(){
    string s;
    cin>>s;
    string postfix = InfixToPostfix(s);
    cout<<postfix<<endl;
    return 0;
}