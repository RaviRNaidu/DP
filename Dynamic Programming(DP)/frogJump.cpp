#include<bits/stdc++.h>
using namespace std;

//this is the recursion code
int recursion(vector<int> &arr, int n){
    if(n == 0) return 0;
    int right = INT_MAX;
    int left = recursion(arr, n-1) + abs(arr[n] - arr[n-1]);
    if(n > 1) right = recursion(arr, n-2) + abs(arr[n] - arr[n-2]);
    return min(left, right);
}


//TC -> O(N)
//SC -> O(N) + O(N)
int memoization(vector<int> &dp, vector<int> &arr, int indx){
    //step 1 -> array creation
    if(indx == 0) return dp[indx] = 0;
    
    int left = INT_MAX , right = INT_MAX;
    //step 3 -> checking for precomputation
    if(dp[indx] != -1) return dp[indx];

    left = memoization(dp, arr, indx - 1) + abs(arr[indx] - arr[indx - 1]);
    if(indx > 1) right = memoization(dp, arr, indx - 2) + abs(arr[indx] - arr[indx - 2]);

    //step 2 -> storing in dp
    return dp[indx] = min(left, right);
}

//TC -> O(N)    SC -> O(N)
int tabulation(vector<int> &dp, vector<int> &arr, int indx){
    dp[0] = 0;

    for(int i=1;i<=indx;i++){
        int left = dp[i-1] + abs(arr[i] - arr[i-1]);
        int right = INT_MAX;
        if(i > 1) right = dp[i-2] + abs(arr[i] - arr[i-2]);
        dp[i] = min(left, right);
    }

    return dp[indx];
}

//TC -> O(N)    SC -> O(1)
int spaceOptimization(vector<int> &arr, int indx){
    int prev = 0;
    int prev2 = -1;
    for(int i=1;i<=indx;i++){

        int left = prev + abs(arr[i] - arr[i-1]);
        int right = INT_MAX;
        if(i > 1) right = prev2 + abs(arr[i] - arr[i-2]);

        int curi = min(left, right);
        prev2 = prev;
        prev = curi;
    }

    return prev;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> dp(n,-1);
    int ans = recursion(arr, n-1);
    cout<<ans<<endl;
    cout<<memoization(dp, arr, n-1)<<endl;
    cout<<tabulation(dp, arr, n-1)<<endl;
    cout<<spaceOptimization(arr, n-1)<<endl;
    return 0;
} 