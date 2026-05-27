#include<bits/stdc++.h>
using namespace std;

//TC -> O(2 ^ N*M)
//SC -> O(N-1 * M-1)
int recursion(int n, int m, vector<vector<int>> &arr){
    if(n == 0 && m == 0) return 1;
    if(n >= 0 && m >= 0 && arr[n][m] == -1) return 0;
    if(n < 0 || m < 0) return 0;

    int left = recursion(n, m-1, arr);
    int right = recursion(n-1, m, arr);

    return left + right;
}

//TC -> O(N * M)
//SC -> O(N-1 * M-1) + O(N * M)
int memoization(int n, int m, vector<vector<int>> &arr, vector<vector<int>> &dp){
    if(n == 0 && m == 0) return dp[n][m] = 1;
    if(n >= 0 && m >= 0 && arr[n][m] == -1) return 0;
    if(n < 0 || m < 0) return 0;

    if(dp[n][m] != -1) return dp[n][m];

    int left = recursion(n, m-1, arr);
    int right = recursion(n-1, m, arr);

    return dp[n][m] = left + right;
}

//TC -> O(N * M)
//SC -> O(N * M)
int tabulation(int n, int m, vector<vector<int>> &arr, vector<vector<int>> &dp){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] == -1) dp[i][j] = 0;
            else if(i == 0 && j == 0) dp[i][j] = 1;
            else{
                int up = 0;
                int left = 0;
                if(i > 0) up = dp[i-1][j];
                if(j > 0) left = dp[i][j-1];

                dp[i][j] = left + up;
            }
        }
    }
    return dp[n-1][m-1];
}

//TC -> O(N * M)
//SC -> O(2M)
int spaceOptimization(int n, int m, vector<vector<int>> &arr){
    vector<int> prev(m, 0);
    for(int i=0;i<n;i++){
        vector<int> curr(m,0);
        for(int j=0;j<m;j++){
            if(arr[i][j] == -1){
                curr[j] = 0;
                continue;
            }
            if(i == 0 && j == 0){
                curr[j] = 1;
                continue;
            }
            int sum = prev[j];
            if(j > 0){
                sum += curr[j-1];
            }

            curr[j] = sum;
        }
        prev = curr;
    }

    return prev[m-1];
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> arr(n, vector<int> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int> (m, -1));
    int ans = recursion(n-1, m-1, arr);
    cout<<memoization(n-1, m-1,arr, dp)<<endl;
    cout<<tabulation(n, m, arr, dp)<<endl;
    cout<<spaceOptimization(n, m, arr)<<endl;
    cout<<ans<<endl;
}