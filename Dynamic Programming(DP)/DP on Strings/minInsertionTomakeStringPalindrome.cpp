#include<bits/stdc++.h>
using namespace std;

int tabulation(string s1, string s2){
    int n = s1.length();
    vector<vector<int>> dp(n+1, vector<int> (n+1,0));

    for(int i=0;i<n;i++){
        dp[0][i] = 0;
        dp[i][0] = 0;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[n][n]; 
}


int spaceOptimization(string s1, string s2){
    int n = s1.length();
    vector<int> prev(n+1, 0);

    for(int i=0;i<n;i++){
        prev[i] = 0;
    }

    for(int i=1;i<=n;i++){
        vector<int> curr(n+1, 0);
        for(int j=1;j<=n;j++){
            if(s1[i-1] == s2[j-1]){
                curr[j] = 1 + prev[j-1];
            }
            else{
                curr[j] = max(prev[j], curr[j-1]);
            }
        }
        prev = curr;
    }

    return prev[n]; 
}

int main(){
    string s1;
    cin>>s1;
    string s2 = s1;
    reverse(s2.begin(), s2.end());
    int LPS = spaceOptimization(s1, s2);
    int n = s1.length();
    int ans = n - LPS;
    cout<<ans<<endl;
    return 0;
}