#include<bits/stdc++.h>
using namespace std;

//TC -> O(N * M)
//SC -> O(N * M) + O(N + M)
string tabulation(string s1, string s2){
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

    for(int i=0;i<n;i++){
        dp[i][0] = 0; 
    }
    for(int i=0;i<m;i++){
        dp[0][i] = 0; 
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }


    //TC -> O(N + M)
    string ans = "";
    int size = dp[n][m];
    for(int i=0;i<size;i++){
        ans += '$';
    }
    int index = size - 1;

    int i = n;
    int j = m;
    while(i > 0 && j > 0){
        if(s1[i-1] == s2[j-1]){
            ans[index] = s1[i-1];
            index--;
            i--;
            j--;
         }
         else if(dp[i-1][j] > dp[i][j-1]){
            i--;
         }
         else{
            j--;
         }
    }
    return ans;
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    string ans = tabulation(s1, s2);
    cout<<ans<<endl;
    return 0;
}