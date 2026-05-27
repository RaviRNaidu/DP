#include<bits/stdc++.h>
using namespace std;

//TC -> O(N^2) + log(256)  SC -> O(256)
int brute(string s, int k){
    int n = s.length();
    int maxlen = 0;
    for(int i=0;i<n;i++){
        set<char> st;
        for(int j=i;j<n;j++){
            st.insert(s[j]);
            if(st.size() > k){
                break;
            }
            else{
                int len = j - i + 1;
                maxlen =  max(maxlen, len);
            }
        }
    }
    return maxlen;
}

//TC -> O(2N) + log(256)   SC -> O(256)
int better(string s, int k){
    int n = s.length();
    int l = 0;
    int r = 0;
    int maxlen = 0;
    unordered_map<char, int> mpp;
    while(r < n){
        mpp[s[r]]++;
        if(mpp.size() > k){
            while(mpp.size() > k){
                mpp[s[l]]--;
                if(mpp[s[l]] == 0){
                    mpp.erase(s[l]);
                }
                l++;
            }
        }
        if(mpp.size() <= k){
            int len = r - l + 1;
            maxlen = max(maxlen, len);
        }
        r++;
    }
    return maxlen;
}

//TC -> O(N) + log(256)   SC -> O(256)
int optimal(string s, int k){
    int n = s.length();
    int l = 0;
    int r = 0;
    int maxlen = 0;
    unordered_map<char, int> mpp;
    while(r < n){
        mpp[s[r]]++;
        if(mpp.size() > k){
            mpp[s[l]]--;
            if(mpp[s[l]] == 0){
                mpp.erase(s[l]);
            }
            l++;
        }
        if(mpp.size() <= k){
            int len = r - l + 1;
            maxlen = max(maxlen, len);
        }
        r++;
    }
    return maxlen;
}

int main(){
    string s;
    cin>>s;
    int k;
    cin>>k;
    int ans = optimal(s, k);
    cout<<ans<<endl;
    return 0;
}