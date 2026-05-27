#include<bits/stdc++.h>
using namespace std;

//TC -> O(2 ^ N*M)
//SC -> O(N-1 * M-1)
int recursion(int r, int c, vector<vector<int>> &arr){
    if(r == 0 && c == 0){
        return arr[r][c];
    }

    if(r < 0 || c < 0) return 1e9;

    int up = arr[r][c] + recursion(r-1,c, arr);
    int left = arr[r][c] + recursion(r, c-1, arr);

    return min(up, left);
}

//TC -> O(N * M)
//SC -> O(N-1 * M-1) + O(N * M)
int memoization(int r, int c, vector<vector<int>> &arr, vector<vector<int>> &dp){
    if(r == 0 && c == 0){
        return dp[r][c] = arr[r][c];
    }

    if(r < 0 || c < 0) return 1e9;

    if(dp[r][c] != -1) return dp[r][c];

    int up = arr[r][c] + memoization(r-1,c, arr, dp);
    int left = arr[r][c] + memoization(r, c-1, arr, dp);

    return dp[r][c] = min(up, left);
}

//TC -> O(N * M)
//SC -> O(N * M)
int tabulation(int r, int c, vector<vector<int>> &arr, vector<vector<int>> &dp){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(i == 0 && j == 0) dp[0][0] = arr[0][0];
            else{
                int up = 1e9;
                int left = 1e9;
                if(j > 0) left = arr[i][j] + dp[i][j-1];
                if(i > 0) up = arr[i][j] + dp[i-1][j];
                dp[i][j] = min(left, up);
            }
        }
    }
    return dp[r-1][c-1];
}

//TC -> O(N * M)
//SC -> O(2M)
int spaceOptimization(int r, int c, vector<vector<int>> &arr){
    vector<int> prev(c, 1e9);
    for(int i=0;i<r;i++){
        vector<int> temp(c, 1e9);
        for(int j=0;j<c;j++){
            if(i == 0 && j == 0) temp[j] = arr[i][j];
            else{
                int up = 1e9;
                int left = 1e9;
                if(i > 0) up = prev[j] + arr[i][j];
                if(j > 0) left = temp[j-1] + arr[i][j];
                temp[j] = min(up,left);
            }
        }
        prev = temp;
    }
    return prev[c-1];
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