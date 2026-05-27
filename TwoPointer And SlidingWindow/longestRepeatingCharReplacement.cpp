#include<bits/stdc++.h>
using namespace std;

//TC -> O(N*N) SC -> O(26)
int brute(string s, int k){
    int n = s.length();
    int ans = 0;
    int maxF = 0;
    for(int i=0;i<n;i++){
        int hash[26] = {0};
        for(int j=i;j<n;j++){
            hash[s[j] - 'A']++;
            maxF = max(maxF,hash[s[j] - 'A']);
            int changes = (j - i + 1) - maxF;
            if(changes <= k){
                ans = max(ans, j - i + 1);
            }
            else{
                break;
            }
        }
    }
    return ans;
}

int main(){
    string s;
    cin>>s;
    int k;
    cin>>k;
    int ans = brute(s,k);
    cout<<ans<<endl;
    return 0;
}