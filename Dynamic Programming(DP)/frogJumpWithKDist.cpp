#include<bits/stdc++.h>
using namespace std;

int recursion(vector<int> &arr, int n, int k){
    if(n == 0) return 0;
    int ans = INT_MAX;

    for(int i=1;i<=k;i++){
        if(n - i >= 0){
            ans = min(ans, recursion(arr, n - i, k) + abs(arr[n] - arr[n - i]));
        }
    }

    return ans;
}

//TC -> O(N * K)
//SC -> O(N) + O(N)
int memoization(vector<int> &dp, vector<int> &arr, int n, int k){
    if(n == 0) return dp[n] = 0;

    int ans = INT_MAX;

    if(dp[n] != -1) return dp[n];

    for(int i=1;i<=k;i++){
        if(n - i >= 0){
            ans = min(ans, recursion(arr, n - i, k) + abs(arr[n] - arr[n - i]));
        }
        else{
            break;
        }
    }

    return dp[n] = ans;
}

//TC -> O(N * K)
//SC -> O(N)
int tabulation(vector<int> &dp, vector<int> &arr, int index, int k){
    dp[0] = 0;

    for(int i=1;i<=index;i++){
        int minSteps = INT_MAX;
        for(int j=1;j<=k;j++){
            if(i - j >= 0){
                minSteps = min(minSteps, abs(dp[i - j] - arr[i]));
            }
            else{
                break;
            }
        }
        dp[i] = minSteps;
    }
    return dp[index];
}

//SPACE OPTIMIZATION CAN BE DONE BUT IN EVEN IN THIS WE NEED TO CARRY K LAST ELEMENTS IN ORDER TO COMPUTE THE ANS
//AT THE WORSE CASE THIS CAN ALSO GO UPTO O(N) SPACE IF K VALUE IS N

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    vector<int> dp(n,-1);
    int ans = recursion(arr, n-1, k);
    cout<<ans<<endl;
    cout<<memoization(dp, arr, n-1, k)<<endl;
    cout<<tabulation(dp, arr, n-1, k)<<endl;
    return 0;
} 