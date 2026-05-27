#include<bits/stdc++.h>
using namespace std;

//TC -> 3^n + O(M)
//SC -> O(N)
int recursion(int i, int j, vector<vector<int>> &arr){
    int m = arr[0].size();
    if(j < 0 || j >= m) return -1e9;
    if(i == 0) return arr[i][j];

    int up = arr[i][j] + recursion(i-1,j,arr);
    int upL = arr[i][j] + recursion(i-1,j-1,arr);
    int upR = arr[i][j] + recursion(i-1,j+1,arr);

    return max(up,max(upL,upR));
}

//TC -> O(N * M) + O(M)
//SC -> O(N * M) + O(N)
int memoization(int i, int j, vector<vector<int>> &arr, vector<vector<int>> &dp){
    int m = arr[0].size();
    if(j < 0 || j >= m) return -1e9;
    if(i == 0) return dp[i][j] = arr[i][j];

    if(dp[i][j] != -1) return dp[i][j];

    int up = arr[i][j] + memoization(i-1,j,arr, dp);
    int upL = arr[i][j] + memoization(i-1,j-1,arr, dp);
    int upR = arr[i][j] + memoization(i-1,j+1,arr, dp);

    return dp[i][j] = max(up,max(upL,upR));
}

//TC -> O(N * M) + O(M)
//SC -> O(N * M)
int tabulation(vector<vector<int>> &arr, vector<vector<int>> &dp){
    int n = arr.size();
    int m = arr[0].size();
    for(int c=0;c<m;c++){
        dp[0][c] = arr[0][c];
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            int upL = 0;
            int upR = 0;
            int up = arr[i][j] + dp[i-1][j];
            if(j > 0) upL = arr[i][j] + dp[i-1][j-1];
            if(j < m-1) upR = arr[i][j] + dp[i-1][j+1];
            dp[i][j] = max(up,max(upL,upR));
        }
    }

    int ans = 0;
    for(int i=0;i<m;i++){
        ans = max(ans, dp[n-1][i]);
    }
    return ans;
}

//TC -> O(N * M) + O(M)
//SC -> O(2M)
int spaceOptimization(int n, int m, vector<vector<int>> &arr){
    vector<int> prev(m, 0);

    for(int i=0;i<n;i++){
        vector<int> temp(m, 0);
        for(int j=0;j<m;j++){
            int up = arr[i][j];
            int upL = arr[i][j];
            int upR = arr[i][j];
            up += prev[j];
            if(j > 0) upL += prev[j-1];
            if(j < m-1) upR += prev[j+1];
            temp[j] = max(up, max(upL, upR));
        }
        prev = temp;
    }

    int ans = 0;
    for(int i=0;i<m;i++){
        ans = max(ans, prev[i]);
    }
    return ans;
}

int solution(vector<vector<int>> &arr, vector<vector<int>> &dp){
    int n = arr.size();
    int m = arr[0].size();
    int ans = -1e9;
    int memo = -1e9;
    for(int j=0;j<m;j++){
        ans = max(ans, recursion(n-1,j,arr));
        memo = max(memo, memoization(n-1,j,arr,dp));
    }
    cout<<memo<<endl;
    return ans;
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
    int ans = solution(arr, dp);
    // cout<<memoization(n-1, m-1,arr, dp)<<endl;
    cout<<tabulation(arr, dp)<<endl;
    cout<<spaceOptimization(n, m, arr)<<endl;
    cout<<ans<<endl;
}