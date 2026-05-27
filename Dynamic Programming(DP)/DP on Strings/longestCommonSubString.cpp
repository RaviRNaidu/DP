#include<bits/stdc++.h>
using namespace std;

//TC -> O(N * M)
//SC -> O(N * M)
int tabulation(string s1, string s2){
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

    for(int i=0;i<n;i++){
        dp[i][0] = 0; 
    }
    for(int i=0;i<m;i++){
        dp[0][i] = 0; 
    }

    int maxi = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                maxi = max(maxi, dp[i][j]);
            }
            else{
                dp[i][j] = 0;
            }
        }
    }

    return maxi;
}

//TC -> O(N * M)
//SC -> O(2 * M)
int spaceOptimization(string s1, string s2){
    int n = s1.size();
    int m = s2.size();

    vector<int> prev(m+1, 0);

    for(int i=0;i<=m;i++){
        prev[i] = 0; 
    }
    int lastIndex = -1;
    int maxi = 0;
    for(int i=1;i<=n;i++){
        vector<int> curr(m+1, 0);
        for(int j=1;j<=m;j++){
            if(s1[i-1] == s2[j-1]){
                curr[j] = 1 + prev[j-1];
                if(curr[j] > maxi){
                    maxi = curr[j];
                    lastIndex = i-1;

                }
            }
            else{
                curr[j] = 0;
            }
        }
        prev = curr;
    }
    cout<<s1.substr(lastIndex - maxi + 1, maxi)<<endl;
    return maxi;
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();
    int ans = spaceOptimization(s1, s2);
    cout<<tabulation(s1, s2)<<endl;
    cout<<ans<<endl;
    return 0;
}