#include<bits/stdc++.h>
using namespace std;

//THIS IS MEMOIZATION
//TC -> O(N)    SC -> O(N) + O(N) for recursion
int fibo(int n, vector<int> &dp){
    if(n <= 1) return n;

    if(dp[n] != -1) return dp[n];

    return dp[n] = fibo(n-1, dp) + fibo(n-2, dp);
}

//TABULATION
//TC -> O(N) SC -> O(N) NO RECURSION SPACE
int tabu(int n){
    vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = 1;

    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

// TC -> O(N) SC -> O(1)
//SPACE OPTIMIZATION!!
int spaceOptimaization(int n){
    int prev2 = 0;
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
    cout<<fibo(n, dp)<<endl;
    cout<<tabu(n)<<endl;
    cout<<spaceOptimaization(n)<<endl;
    return 0;
} 