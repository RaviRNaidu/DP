#include<bits/stdc++.h>
using namespace std;

//TC -> EXPONENTIALLL!!!!
//SC -> not O(N) it will be way more ie o(target)
int recursion(int i, int target, vector<int> &arr){
    if(i == 0){
        if(target % arr[i] == 0) return 1;
        else return 0;
    }

    int NotTake = recursion(i-1, target, arr);
    int take = 0;
    if(arr[i] <= target){
        take = recursion(i, target - arr[i], arr);
    }

    return NotTake + take;
}


//TC -> O(N*TARGET)
//SC -> O(N*TARGET) + O(target)
int memoization(int i, int target, vector<int> &arr, vector<vector<int>> &dp){
    if(i == 0){
        if(target % arr[i] == 0) return dp[i][target] = 1;
        else return dp[i][target] = 0;
    }

    if(dp[i][target] != -1) return dp[i][target];

    int NotTake = memoization(i-1, target, arr, dp);
    int take = 0;
    if(arr[i] <= target){
        take = memoization(i, target - arr[i], arr, dp);
    }

    return dp[i][target] = NotTake + take;
}


//TC -> O(N*TARGET)
//SC -> O(N*TARGET)
int tabulation(int target, vector<int> &arr, int n){
    vector<vector<int>> dp(n, vector<int> (target+1,-1));

    for(int t=0;t<=target;t++){
        if(t % arr[0] == 0) dp[0][t] = 1;
    }

    for(int i=1;i<n;i++){
        for(int t=0;t<=target;t++){
            int NotTake = dp[i-1][t];
            int take = 0;
            if(arr[i] <= t) take = dp[i][t - arr[i]];
            dp[i][t] = NotTake + take;
        }
    }

    return dp[n-1][target];
}


//TC -> O(N*TARGET)
//SC -> O(2*TARGET)
int spaceOptimization(int target, vector<int> &arr, int n){
    vector<int> prev(target+1, 0);

    for(int t=0;t<=target;t++){
        if(t % arr[0] == 0) prev[t] = 1;
    }

    for(int i=1;i<n;i++){
        vector<int> curr(target+1, 0);
        for(int t=0;t<=target;t++){
            int NotTake = prev[t];
            int take = 0;
            if(arr[i] <= t) take = curr[t - arr[i]];
            curr[t] = NotTake + take;
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
    vector<vector<int>> dp(n, vector<int> (target+1,-1));
    int ans = recursion(n-1, target, arr);
    cout<<memoization(n-1, target, arr, dp)<<endl;
    cout<<tabulation(target, arr, n)<<endl;
    cout<<spaceOptimization(target, arr, n)<<endl;
    cout<<ans<<endl;
    return 0;
} 