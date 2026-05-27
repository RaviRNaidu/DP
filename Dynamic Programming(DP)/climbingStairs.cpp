#include<bits/stdc++.h>
using namespace std;

//RECURSION
int climbing(int n){
    if(n == 1 || n == 0) {
        return 1;
    }
    
    return climbing(n-1) + climbing(n-2);
}

int memo(int n, vector<int> &dp){
    if(n == 1 || n == 0) {
        return 1;
    }

    if(dp[n] != -1) return dp[n];

    return dp[n] = memo(n-1, dp) + memo(n-2, dp);
}

//TABULATION
//TC -> O(N) SC -> O(N) NO RECURSION SPACE
int tabu(int n){
    vector<int> dp(n+1);
    dp[0] = 1;
    dp[1] = 1;

    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

// TC -> O(N) SC -> O(1)
//SPACE OPTIMIZATION!!
int spaceOptimaization(int n){
    int prev2 = 1;
    int prev = 1;
    for(int i=2;i<=n;i++){
        int curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1, -1);
    cout<<climbing(n)<<endl;
    cout<<memo(n,dp)<<endl;
    return 0;
} 