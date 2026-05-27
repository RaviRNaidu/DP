#include<bits/stdc++.h>
using namespace std;

//TC -> O(2^N)
//SC -> O(N)
int recursion(int i, int target, vector<int> &arr){
    if(target == 0) return 1;
    if(i == 0){
        if(arr[i] == target) return 1;
        else return 0;
    }

    int NotTake = recursion(i-1, target, arr);
    int take = 0;
    if(arr[i] <= target){
        take = recursion(i-1, target - arr[i], arr);
    }

    return NotTake + take;
}


//TC -> O(N * target)
//SC -> O(N * target) + O(N)
int memoization(int i, int target, vector<int> &arr, vector<vector<int>> &dp){
    if(target == 0) return dp[i][target] = 1;
    if(i == 0){
        if(arr[i] == target) return dp[i][target] = 1;
        else return dp[i][target] = 0;
    }

    if(dp[i][target] != -1) return dp[i][target];

    int NotTake = memoization(i-1, target, arr, dp);
    int take = 0;
    if(arr[i] <= target){
        take = memoization(i-1, target - arr[i], arr, dp);
    }

    return dp[i][target] = NotTake + take;
}

//TC -> O(N * target)
//SC -> O(N * target)
int tabulation(int target, vector<int> &arr){
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int> (target+1, 0));

    for(int i=0;i<n;i++) dp[i][0] = 1;
    if(arr[0] <= target) dp[0][arr[0]] = 1;

    for(int i=1;i<n;i++){
        for(int t=1;t<=target;t++){
            int notPick = dp[i-1][t];
            int pick = 0;
            if(arr[i] <= t){
                pick = dp[i-1][t - arr[i]];
            }
            dp[i][t] = notPick + pick;
        }
    }

    return dp[n-1][target];
}


//TC -> O(N * M)
//SC -> O(2 * target)
int spaceOptimization(int target, vector<int> &arr){
    int n = arr.size();
    vector<int> prev(target+1, 0);
    prev[0] = 1;
    if(arr[0] <= target) prev[arr[0]] = 1;

    for(int i=1;i<n;i++){
        vector<int> curr(target+1, 0);
        curr[0] = 1;
        for(int t=1;t<=target;t++){
            int notPick = prev[t];
            int pick = 0;
            if(arr[i] <= t){
                pick = prev[t - arr[i]];
            }
            curr[t] = notPick + pick;
        }
        prev = curr;
    }

    return prev[target];
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int target;
    cin>>target;
    
    vector<vector<int>> dp(n, vector<int> (target+1, -1));
    int ans = recursion(n-1, target, arr);
    cout<<memoization(n-1, target, arr, dp)<<endl;
    cout<<tabulation(target,arr)<<endl;
    cout<<spaceOptimization(target,arr)<<endl;
    cout<<ans<<endl;
    return 0;
} 