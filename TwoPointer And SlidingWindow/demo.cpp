#include<bits/stdc++.h>
using namespace std;

int brute(string s, int k){
    int n = s.length();
    int ans = 0;
    for(int i=0;i<n;i++){
        vector<int> hash(26,0);
        int maxi = 0;
        for(int j=i;j<n;j++){
            hash[s[j] - 'A']++;
            maxi = max(maxi,hash[s[j] - 'A']);
            int changes = j-i+1;
            if(changes - maxi <= k){
                ans = max(ans,j-i+1);
            }
            else{
                break;
            }
        }
    }
    return ans;
}

int better(string s, int k){
    int n = s.length();
    int l = 0;
    int r = 0;
    int hash[26] = {0};
    int maxlen = 0;
    int maxfreq = 0;
    while(r < n){
        hash[s[r] - 'A']++;
        maxfreq = max(maxfreq,hash[s[r] - 'A']);
        while(((r - l + 1) - maxfreq) > k){
            hash[s[l] - 'A']--;
            maxfreq = 0;
            for(int i=0;i<26;i++){
                maxfreq = max(maxfreq,hash[i]);
            }
            l++;
        }
        if((r-l+1) - maxfreq <= k){
            maxlen = max(maxlen, r - l + 1);
        }
        r++;
    }
    return maxlen;
}

int optimal(string s, int k){
    int n = s.length();
    int l = 0;
    int r = 0;
    int hash[26] = {0};
    int maxlen = 0;
    int maxfreq = 0;
    while(r < n){
        hash[s[r] - 'A']++;
        maxfreq = max(maxfreq,hash[s[r] - 'A']);
        if(((r - l + 1) - maxfreq) > k){
            hash[s[l] - 'A']--;
            l++;
        }
        if((r-l+1) - maxfreq <= k){
            maxlen = max(maxlen, r - l + 1);
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
    int ans = optimal(s,k);
    cout<<ans<<endl;
    return 0;
}