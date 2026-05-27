#include<bits/stdc++.h>
using namespace std;

//TC -> O(2^n * 2^m) EXPONENTIALLL
//SC -> O(N + M)
int recursion(int index1, int index2, string s1, string s2){
    if(index1 < 0 || index2 < 0) return 0;

    if(s1[index1] == s2[index2]){
        return 1 + recursion(index1 - 1, index2 -1, s1, s2);
    }

    return max(recursion(index1 - 1, index2, s1, s2) , recursion(index1, index2 - 1, s1, s2));
}

//TC -> O(N * M)
//SC -> O(N * M) + O(N + M)
int memoization(int index1, int index2, string s1, string s2, vector<vector<int>> &dp){
    if(index1 < 0 || index2 < 0) return 0;

    if(dp[index1][index2] != -1) return dp[index1][index2];

    if(s1[index1] == s2[index2]){
        return dp[index1][index2] = 1 + memoization(index1 - 1, index2 -1, s1, s2, dp);
    }

    return dp[index1][index2] = max(memoization(index1 - 1, index2, s1, s2, dp) , memoization(index1, index2 - 1, s1, s2, dp));
}



//SHIFING OF INDEXEX!!!!!!!!!!
//TC -> O(2^n * 2^m) EXPONENTIALLL
//SC -> O(N + M)
int recursionS(int index1, int index2, string s1, string s2){
    if(index1 == 0 || index2 == 0) return 0;

    if(s1[index1 - 1] == s2[index2 - 1]){
        return 1 + recursionS(index1 - 1, index2 -1, s1, s2);
    }

    return max(recursionS(index1 - 1, index2, s1, s2) , recursionS(index1, index2 - 1, s1, s2));
}

//TC -> O(N * M)
//SC -> O(N * M) + O(N + M)
int memoizationS(int index1, int index2, string s1, string s2, vector<vector<int>> &dp){
    if(index1 == 0 || index2 == 0) return 0;

    if(dp[index1][index2] != -1) return dp[index1][index2];

    if(s1[index1 - 1] == s2[index2 - 1]){
        return dp[index1][index2] = 1 + memoizationS(index1 - 1, index2 -1, s1, s2, dp);
    }

    return dp[index1][index2] = max(memoizationS(index1 - 1, index2, s1, s2, dp) , memoizationS(index1, index2 - 1, s1, s2, dp));
}


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

    return dp[n][m];
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

    for(int i=1;i<=n;i++){
        vector<int> curr(m+1, 0);
        for(int j=1;j<=m;j++){
            if(s1[i-1] == s2[j-1]){
                curr[j] = 1 + prev[j-1];
            }
            else{
                curr[j] = max(prev[j], curr[j-1]);
            }
        }
        prev = curr;
    }

    return prev[m];
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int> (m + 1,-1));
    int ans = recursionS(n, m, s1, s2);
    cout<<memoizationS(n, m, s1, s2, dp)<<endl;
    cout<<tabulation(s1, s2)<<endl;
    cout<<ans<<endl;
    return 0;
}