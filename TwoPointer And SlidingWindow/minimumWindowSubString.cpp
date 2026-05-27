#include<bits/stdc++.h>
using namespace std;

//TC -> O(N^2)    SC -> O(256)
string brute(string s, string t){
    int n = s.length();
    int m = t.length();
    int minLeng = INT_MAX;
    int stIndex = -1;
    for(int i=0;i<n;i++){
        int hash[256] = {0};
        int cnt = 0;
        for(int j=0;j<m;j++){
            hash[t[j]]++;
        }
        for(int k=i;k<n;k++){
            if(hash[s[k]] > 0){
                cnt++;
            }
            hash[s[k]]--;
            if(cnt == m){
                if(minLeng > k-i+1){
                    minLeng = k-i+1;
                    stIndex = i;
                    break;
                }
            }
        }
    }
    return s.substr(stIndex,minLeng);
}

string optimal(string s, string t){
    int n = s.length();
    int m = t.length();
    int minLeng = INT_MAX;
    int stIndex = -1;
    int cnt = 0;
    int l = 0; int r = 0;
    int hash[256] = {0};
    for(int i=0;i<m;i++){
        hash[t[i]]++;
    }
    while(r < n){
        if(hash[s[r]] > 0){
            cnt++;
        }
        hash[s[r]]--;
        while(cnt == m){
            if(minLeng > r-l+1){
                minLeng = r-l+1;
                stIndex = l;
            }
            hash[s[l]]++;
            if(hash[s[l]] > 0){
                cnt--;
            }
            l++;
        }
        r++;
    }
    return s.substr(stIndex,minLeng);
}

int main(){
    string s;
    cin>>s;
    string t;
    cin>>t;
    string ans = brute(s,t);
    cout<<ans<<endl;
    return 0;
}