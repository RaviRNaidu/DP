#include<bits/stdc++.h>
using namespace std;

//TC -> O(N * M)
//SC -> O(N * M)
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

    int lenght = dp[n][m];
    string ans = "";
    for(int i=0;i<lenght;i++){
        ans += '$';
    }
    int index = lenght - 1;

    int i = n; int j = m;
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
    string s1;
    cin >> s1;
    int n = s1.size();
    string s2 = s1;
    reverse(s2.begin(), s2.end());
    vector<vector<int>> dp(n + 1, vector<int> (n + 1,-1));
    cout<<tabulation(s1, s2)<<endl;
    return 0;
}