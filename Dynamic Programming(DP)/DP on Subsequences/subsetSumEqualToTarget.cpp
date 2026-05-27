#include<bits/stdc++.h>
using namespace std;

//TC -> O(2^N)
//SC -> O(N)
bool recursion(int i, int target, vector<int> &arr){
    if(target == 0) return true;
    if(i == 0) return (arr[i] == target);

    bool NotTake = recursion(i-1, target, arr);
    bool take = false;
    if(target >= arr[i]){
        take = recursion(i-1, target - arr[i], arr);
    }

    return (NotTake || take);
}

//TC -> O(N * TARGET)
//SC -> O(N) + O(N*TARGET)
bool memoization(int i, int target, vector<int> &arr, vector<vector<int>> &dp){
    if(target == 0) return dp[i][target] = 1;
    if(i == 0){
        if(arr[i] == target) return dp[i][target] = 1;
        else return dp[i][target] = 0;
    }

    if(dp[i][target] != -1) return dp[i][target];

    bool NotTake = memoization(i-1, target, arr, dp);
    bool take = false;
    if(target >= arr[i]){
        take = memoization(i-1, target - arr[i], arr, dp);
    }

    return dp[i][target] = (NotTake || take);
}

//TC -> O(target * n) + o(n)
//SC -> O(N * TARGET + 1) 
bool tabulation(int i, int target, vector<int> &arr){
    int n = arr.size();
    //WHENEVER THE TARGET IS 0 WE RETURN TRUE 
    vector<vector<bool>> dp(n, vector<bool> (target+1,false));
    for(int i=0;i<n;i++){
        dp[i][0] = true;
    }

    //AT INDEX 0 ONLY IF THE TARGET IS SAME AS THE VAL PRESENT IN THE INDX 0 THEN WE RETURN TRUE
    dp[0][arr[0]] = true;

    for(int i=1;i<n;i++){
        for(int t=1;t<=target;t++){
            bool NotTake = dp[i-1][t];
            bool take = false;
            if(t >= arr[i]){
                take = dp[i-1][t - arr[i]];
            }
            dp[i][t] = (NotTake || take);
        }
    }

    return dp[n-1][target];
}


//TC -> O(N * TARGET)
//SC -> O(2 target)
int spaceOptimization(int i, int target, vector<int> &arr){
    int n = arr.size();
    
    vector<bool> prev(target+1, 0);

    prev[0] = true;
    prev[arr[0]] = true;

    for(int i=1;i<n;i++){
        vector<bool> curr(target+1, 0);
        curr[0] = true;
        for(int t=1;t<=target;t++){
            bool NotTake = prev[t];
            bool take = false;
            if(t >= arr[i]){
                take = prev[t - arr[i]];
            }
            curr[t] = (NotTake || take);
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
    cout<<ans<<endl;
    cout<<memoization(n-1, target, arr, dp)<<endl;
    // cout<<tabulation(dp, arr, n-1)<<endl;
    // cout<<spaceOptimization(arr, n-1)<<endl;
    return 0;
} 