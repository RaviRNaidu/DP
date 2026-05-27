#include<bits/stdc++.h>
using namespace std;

//TC -> O(2 ^ N*M)
//SC -> O(N-1 * M-1)
int recursion(int n, int m){
    if(n == 0 && m == 0){
        return 1;
    }
    if(n < 0 || m < 0){
        return 0;
    }

    int left = recursion(n, m-1);
    int right = recursion(n-1, m);

    return left + right;
}


//TC -> O(N * M)
//SC -> O(N-1 * M-1) + O(N * M)
int memoization(int n, int m, vector<vector<int>> &dp){
    if(n == 0 && m == 0){
        return dp[n][m] = 1;
    }
    if(n < 0 || m < 0) return 0;

    if(dp[n][m] != -1) return dp[n][m];

    int left = memoization(n, m - 1, dp);
    int right = memoization(n-1, m, dp);

    return dp[n][m] = left + right;
}


//TC -> O(N * M)
//SC -> O(N * M)
int tabulation(int n, int m, vector<vector<int>> &dp){
    dp[0][0] = 1;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i == 0 && j == 0) {
                dp[i][j] = 1;
            }
            else{
                int up = 0;
                int left = 0;
                if(i > 0){
                    up = dp[i-1][j];
                }
                if(j > 0){
                    left = dp[i][j-1];
                }
                dp[i][j] = left + up;
            }
        }
    }

    return dp[n-1][m-1];
}

//TC -> O(N * M)
//SC -> O(2M)
int spaceOptimization(int n, int m){
    vector<int> dp(m,0);

    for(int i=0;i<n;i++){
        vector<int> temp(m,0);
        for(int j=0;j<m;j++){
            if(i == 0 && j == 0) temp[j] = 1;
            else{
                int sum = dp[j];
                if(j > 0){
                    sum += temp[j-1];
                }
                temp[j] = sum;
            }
        }
        dp = temp;
    }
    return dp[m-1];
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> dp(n, vector<int> (m, -1));
    int ans = recursion(n-1, m-1);
    cout<<memoization(n-1, m-1, dp)<<endl;
    cout<<tabulation(n, m, dp)<<endl;
    cout<<spaceOptimization(n, m)<<endl;
    cout<<ans<<endl;
}