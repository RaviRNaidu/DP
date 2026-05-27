#include<bits/stdc++.h>
using namespace std;

//TC -> O(2^N)
//SC -> O(N)
int recursion(int i, int j, vector<vector<int>> &arr){
    if(i == arr.size() - 1){
        return arr[i][j];
    }

    int down = arr[i][j] + recursion(i + 1, j, arr);
    int right = arr[i][j] + recursion(i+1, j+1, arr);

    return min(down, right);
}


//TC -> O(N*N)
//SC -> O(N) + O(N*N)
int memoization(int i, int j, vector<vector<int>> &arr, vector<vector<int>> &dp){
    if(i == arr.size() - 1){
        return dp[i][j] = arr[i][j];
    }

    if(dp[i][j] != -1) return dp[i][j];

    int down = arr[i][j] + memoization(i + 1, j, arr, dp);
    int right = arr[i][j] + memoization(i+1, j+1, arr, dp);

    return dp[i][j] = min(down, right);
}


//TC -> O(N*N)
//SC -> O(N*N)
int tabulation(int r, int c, vector<vector<int>> &arr, vector<vector<int>> &dp){
    int n = arr.size();
    int m = arr[n-1].size();

    for(int i=0;i<m;i++){
        dp[n-1][i] = arr[n-1][i];
    }

    for(int i=n-2;i>=0;i--){
        for(int j=0;j<arr[i].size();j++){
            int down = arr[i][j] + dp[i+1][j];
            int right = arr[i][j] + dp[i+1][j+1];
            dp[i][j] = min(down, right);
        }
    }
    return dp[0][0];
}

//TC -> O(N * N)
//SC -> O(2 * N)
int spaceOptimization(vector<vector<int>> &arr){
    int n = arr.size();
    
    vector<int> dp(n,-1);
    for(int i=0;i<=n;i++){
        dp[i] = arr[n-1][i];
    }

    for(int i=n-2;i>=0;i--){
        vector<int> temp(n,-1);
        for(int j=i;j>=0;j--){
            temp[j] = arr[i][j] + min(dp[j],dp[j+1]);
        }
        dp = temp;
    }
    return dp[0];
}

int main(){
    vector<vector<int>> arr = {{1}, {2,3}, {3,6,7}, {8,9,6,10}};
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int> (n,-1));
    int ans = recursion(0,0, arr);
    cout<<memoization(0,0,arr, dp)<<endl;
    cout<<tabulation(0, 0, arr, dp)<<endl;
    cout<<spaceOptimization(arr)<<endl;
    cout<<ans<<endl;
}