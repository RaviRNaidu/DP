#include<bits/stdc++.h>
using namespace std;

//TC -> O(2^N)
//SC -> O(N)
int recursion(int i, int maxWt, vector<int> &wt, vector<int> &val){
    if(i == 0){
        if(wt[i] <= maxWt) return val[i];
        else return 0;
    }

    int NotPick = recursion(i-1, maxWt, wt, val);
    int pick = INT_MIN;
    if(maxWt >= wt[i]){
        pick = val[i] + recursion(i-1, maxWt - wt[i], wt, val);
    }

    return max(NotPick, pick);
}

//TC -> O(N*W)
//SC -> O(N*W) + O(N)
int memoization(int i, int maxWt, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp){
    if(i == 0){
        if(wt[i] <= maxWt) return dp[i][maxWt] = val[i];
        else return dp[i][maxWt] = 0;
    }

    if(dp[i][maxWt] != -1) return dp[i][maxWt];

    int NotPick = memoization(i-1, maxWt, wt, val, dp);
    int pick = INT_MIN;
    if(maxWt >= wt[i]){
        pick = val[i] + memoization(i-1, maxWt - wt[i], wt, val, dp);
    }

    return dp[i][maxWt] = max(NotPick, pick);
}


//TC -> O(N*W)
//SC -> O(N*W)
int tabulation(int maxWt, vector<int> &wt, vector<int> &val, int n){
    vector<vector<int>> dp(n, vector<int> (maxWt+1,0));
    for(int i=wt[0];i<=maxWt;i++){
        dp[0][i] = val[0];
    }

    for(int i=1;i<n;i++){
        for(int w=0;w<=maxWt;w++){
            int notTake = dp[i-1][w];
            int take = INT_MIN;
            if(wt[i] <= w){
                take = val[i] + dp[i-1][w - wt[i]];
            }

            dp[i][w] = max(take, notTake);
        }
    }

    return dp[n-1][maxWt];
}


//TC -> O(N*W)
//SC -> O(2*W)
int spaceOptimization(int maxWt, vector<int> &wt, vector<int> &val, int n){
    vector<int> prev(maxWt+1, 0);
    for(int i=wt[0];i<=maxWt;i++){
        prev[i] = val[0];
    }

    for(int i=1;i<n;i++){
        vector<int> curr(maxWt+1, 0);
        for(int w=0;w<=maxWt;w++){
            int notTake = prev[w];
            int take = 0;
            if(wt[i] <= w){
                take = val[i] + prev[w - wt[i]];
            }

            curr[w] = max(take, notTake);
        }
        prev = curr;
    }

    return prev[maxWt];
}

//TC -> O(N*W)
//SC -> O(W)
int spaceOptimization2(int maxWt, vector<int> &wt, vector<int> &val, int n){
    vector<int> prev(maxWt+1, 0);
    for(int i=wt[0];i<=maxWt;i++){
        prev[i] = val[0];
    }

    for(int i=1;i<n;i++){
        //here we will try to fill from right to left cuz in order to convert to 1D
        //this is done cuz the ans for curr depends on the prev ie w - wt[i] index. and since they will be at the first we try to 
        //fill the vals from the end
        for(int w=maxWt;w>=0;w--){
            int notTake = prev[w];
            int take = 0;
            if(wt[i] <= w){
                take = val[i] + prev[w - wt[i]];
            }

            prev[w] = max(take, notTake);
        }
    }

    return prev[maxWt];
}

int main(){
    int n;
    cin>>n;
    vector<int> wt(n);
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }
    vector<int> val(n);
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    int maxWt;
    cin>>maxWt;
    vector<vector<int>> dp(n, vector<int> (maxWt+1, -1));
    int ans = recursion(n-1,maxWt, wt, val);
    cout<<memoization(n-1,maxWt, wt, val, dp)<<endl;
    cout<<tabulation(maxWt, wt, val, n)<<endl;
    cout<<spaceOptimization(maxWt, wt, val, n)<<endl;
    cout<<ans<<endl;
    return 0;
} 