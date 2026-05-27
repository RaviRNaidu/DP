#include<bits/stdc++.h>
using namespace std;

//TC -> its EXPONENTIALLL
//SC -> O(length)
int recursion(int i, int length, vector<int> &arr){
    if(i == 0){
        //i added this thinking it might go below 0 but STRIVER DIDNT
        // if(length < 0) return INT_MIN;
        return length * arr[i];
    }

    int NotTake = recursion(i-1, length, arr);
    int take = INT_MIN;
    if(i + 1 <= length){
        take = arr[i] + recursion(i, length - (i+1), arr);
    }

    return max(NotTake, take);
}


//TC -> O(N * L)
//SC -> O(N * L) + O(N)
int memoization(int i, int length, vector<int> &arr, vector<vector<int>> &dp){
    if(i == 0){
        //i added this thinking it might go below 0 but STRIVER DIDNT
        // if(length < 0) return INT_MIN;
        return dp[i][length] = length * arr[i];
    }

    if(dp[i][length] != -1) return dp[i][length];

    int NotTake = memoization(i-1, length, arr, dp);
    int take = INT_MIN;
    if(i + 1 <= length){
        take = arr[i] + memoization(i, length - (i+1), arr, dp);
    }

    return dp[i][length] = max(NotTake, take);
}

//TC -> O(N * L)
//SC -> O(N * L)
int tabulation(int length, vector<int> &arr, int n){
    vector<vector<int>> dp(n, vector<int> (length+1));

    for(int l=0;l<=length;l++){
        dp[0][l] = l * arr[0];
    }

    for(int i=1;i<n;i++){
        for(int l=0;l<=length;l++){
            int notTake = dp[i-1][l];
            int take = INT_MIN;
            int rodLength = i+1;
            if(rodLength <= l){
                take = arr[i] + dp[i][l - rodLength];
            }

            dp[i][l] = max(notTake, take);
        }
    }

    return dp[n-1][length];
}

//TC -> O(N * L)
//SC -> O(2 * L)
int spaceOptimization(int length, vector<int> &arr, int n){
    vector<int> prev(length+1, 0);

    for(int l=0;l<=length;l++){
        prev[l] = l * arr[0];
    }

    for(int i=1;i<n;i++){
        vector<int> curr(length+1, 0);
        for(int l=0;l<=length;l++){
            int notTake = prev[l];
            int take = INT_MIN;
            int rodLength = i+1;
            if(rodLength <= l){
                take = arr[i] + curr[l - rodLength];
            }

            curr[l] = max(notTake, take);
        }
        prev = curr;
    }

    return prev[length];
}

//TC -> O(N*L)
//SC -> O(L)
int spaceOptimization2(int length, vector<int> &arr, int n){
    vector<int> prev(length+1, 0);

    for(int l=0;l<=length;l++){
        prev[l] = l * arr[0];
    }

    for(int i=1;i<n;i++){
        for(int l=0;l<=length;l++){
            int notTake = prev[l];
            int take = INT_MIN;
            int rodLength = i+1;
            if(rodLength <= l){
                take = arr[i] + prev[l - rodLength];
            }

            prev[l] = max(notTake, take);
        }
    }

    return prev[length];
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int length;
    cin>>length;
    
    vector<vector<int>> dp(n, vector<int> (length+1, -1));
    int ans = recursion(n-1, length, arr);
    cout<<memoization(n-1, length, arr, dp)<<endl;
    cout<<tabulation(length, arr, n)<<endl;
    cout<<spaceOptimization(length, arr, n)<<endl;
    cout<<spaceOptimization2(length, arr, n)<<endl;
    cout<<ans<<endl;
    return 0;
} 