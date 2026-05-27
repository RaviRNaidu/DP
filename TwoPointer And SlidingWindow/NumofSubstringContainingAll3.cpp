#include<bits/stdc++.h>
using namespace std;

//TC -> O(N*N) SC -> O(3)
int brute(string s){
    int n = s.length();
    int ans = 0;
    for(int i=0;i<n;i++){
        set<char> st;
        for(int j=i;j<n;j++){
            st.insert(s[j]);
            if(st.size() == 3){
                ans++;
            }
        }
    }
    return ans;
}

//TC -> O(N*N) SC -> O(3)
int brutestriver(string s){
    int n = s.length();
    int ans = 0;
    for(int i=0;i<n;i++){
        int hash[3] = {0};
        for(int j=i;j<n;j++){
            hash[s[j] - 'a'] = 1;
            if(hash[0] + hash[1] + hash[2] == 3){
                ans++;
            }
        }
    }
    return ans;
}

//JUST A SMALL OPTIMIZATION CAN IMPROVE FOR FEW TESTCASES BUT FOR WORST CASE IT WONT
int brutestriver2(string s){
    int n = s.length();
    int ans = 0;
    for(int i=0;i<n;i++){
        int hash[3] = {0,0,0};
        for(int j=i;j<n;j++){
            hash[s[j] - 'a'] = 1;
            if(hash[0] + hash[1] + hash[2] == 3){
                ans = ans + (n-j);
                break;
            }
        }
    }
    return ans;
}


//TC -> O(N)    SC->o(1)
int optimal(string s){
    int n = s.length();
    int lastSeen[3] = {-1,-1,-1};
    int cnt = 0;
    for(int i=0;i<n;i++){
        lastSeen[s[i] - 'a'] = i;
        if(lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1){
            int val = min(lastSeen[0],lastSeen[1]);
            cnt = cnt + (1 + min(lastSeen[2],val));
        }
    }
    return cnt;
}

int main(){
    string s;
    cin>>s;
    int ans = optimal(s);
    cout<<ans<<endl;
    return 0;
}