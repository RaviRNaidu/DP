#include<bits/stdc++.h>
using namespace std;

//TC -> 2 ^ n
//SC -> n
int recursion(vector<int> &arr, int index){
    if(index == 0) return arr[index];
    if(index < 0) return 0;

    //if u pick this index then this will be added to the sum and u cant pick the adj index so we call for index - 2
    int pick = arr[index] + recursion(arr, index - 2);

    //if u dont pick the curr index then we can pick the adj index ie index - 1 
    int notPick = 0 + recursion(arr, index - 1);

    //return maximum of both
    return max(pick, notPick);
}

//TC -> O(N)
//SC -> O(N) + O(N)
int memoization(vector<int> &arr, vector<int> &dp, int index){
    if(index == 0) return dp[index] = arr[index];
    if(index < 0) return 0;

    if(dp[index] != -1) return dp[index];

    int pick = arr[index] + memoization(arr, dp, index - 2);

    int notPick = 0 + memoization(arr, dp, index - 1);

    return dp[index] = max(pick, notPick);
}

//TC -> O(N)
//SC -> O(N)
int tabulation(vector<int> &arr, vector<int> &dp, int index){
    dp[0] = arr[0];

    for(int i=1;i<=index;i++){
        int pick = INT_MIN;
        if(i - 2 >= 0) pick = arr[i] + dp[i - 2];
        int notpick = 0 + dp[i-1];

        dp[i] = max(pick, notpick);
    }

    return dp[index];
}


// TC -> O(N)
// SC -> O(1)
int spaceOptimization(vector<int> &arr, vector<int> &dp, int index){
    int prev = arr[0];
    int prev2 = 0;

    for(int i=1;i<=index;i++){
        int left = arr[i];
        if(i > 1) left += prev2;
        int right = 0 + prev;

        int sum = max(left, right);

        //make sure to update the prev2 before prev
        prev2 = prev;
        prev = sum;
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
    vector<int> dp(n, -1);
    int ans = recursion(arr, n-1);
    cout<<ans<<endl;
    cout<<memoization(arr, dp, n-1)<<endl;
    cout<<tabulation(arr, dp, n-1)<<endl;
    cout<<spaceOptimization(arr, dp, n-1)<<endl;
    return 0;
} 