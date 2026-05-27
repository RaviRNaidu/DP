#include<bits/stdc++.h>
using namespace std;

//TC -> O(3N) + O(K)  SC -> O(2N)
string removing(string str, int k){
    stack<char> st;
    string ans = "";
    int n = str.length();
    if(n == k){
        return "0";
    }
    for(int i=0;i<n;i++){                                                           //TC -> O(N)
        while(!st.empty() && k > 0 && (st.top() - '0') > (str[i]) - '0'){
            st.pop();
            k--;
        }
        st.push(str[i]);
    }

    while(k > 0){                                                                   //TC -> O(K)
        st.pop();
        k--;
    }

    if(st.empty()){
        return "0";
    }

    while(!st.empty()){
        ans += st.top();
        st.pop();
    }

    while(ans.length() != 0 && ans.back() == '0'){                                  //TC -> O(N)
        ans.pop_back();
    }

    reverse(ans.begin(),ans.end());

    if(ans.empty()) return "0";

    return ans;
}

int main(){
    int k;
    cin>>k;
    string str;
    cin>>str;
    string ans = removing(str, k);
    cout<<ans<<endl;
    return 0;
}