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
int spaceOptimization(vector<int> &arr, int index){
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

// we will use the same logic that we used for maxSumSubSequence but since we should not consider or take both last and first values
// we call the same function for the arr excluding the first and then again we call the same function excluding the last
// then we return max cuz we are sure that the ans is there btw those two 
int houseRobber(vector<int> &arr, int n){
    if(n == 0) return arr[0];

    vector<int> temp1;
    vector<int> temp2;

    for(int i=0;i<n;i++){
        if(i != 0) temp1.push_back(arr[i]);
        if(i != n-1) temp2.push_back(arr[i]);
    }

    return max(spaceOptimization(temp1, temp1.size() - 1),spaceOptimization(temp2, temp2.size() - 1));
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> dp(n, -1);
    int ans = houseRobber(arr, n);
    cout<<ans<<endl;
    return 0;
} 