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


//TC -> O(N/2)
string reversing(string s){
    int n = s.length();
    for(int i=0;i<n/2;i++){
        char temp = s[i];
        s[i] = s[n-i-1];
        s[n-i-1] = temp;

        if(s[i] == '('){
            s[i] = ')';
        }
        else if(s[i] == ')'){
            s[i] = '(';
        }

        if(s[n - i - 1] == '('){
            s[n - i - 1] = ')';
        }
        else if(s[n - i - 1] == ')'){
            s[n - i - 1] = '(';
        }
    }
    return s;
}


// TC -> O(N) + O(N) + O(N/2) + O(N/2) -> O(3N)    SC -> O(N) + O(N)
string InfixToPostfix(string s){
    stack<char> st;
    s = reversing(s);       // TC -> O(N/2)
    int n = s.length();
    string prefix = "";
    for(int i=0;i<n;i++){
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 0 && s[i] <= 9)){   // TC -> O(1)
            prefix += s[i];
        }
        else if(s[i] == '('){       // TC -> O(1)
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            while(!st.empty() && st.top() != '('){              // TC -> O(N)
                prefix += st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            if(s[i] == '^'){
                while(!st.empty() && precedence(st.top()) >= precedence(s[i])){     // TC -> O(N)
                    prefix += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
            else{
                while(!st.empty() && precedence(st.top()) > precedence(s[i])){      // TC -> O(N)
                    prefix += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
    }
    while(!st.empty()){             // TC -> O(N)
        prefix += st.top();
        st.pop();
    }
    prefix = reversing(prefix);     // TC -> O(N/2)
    return prefix;
}

int main(){
    string s;
    cin>>s;
    string prefix = InfixToPostfix(s);
    cout<<prefix<<endl;
    return 0;
}