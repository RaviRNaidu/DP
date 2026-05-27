#include<bits/stdc++.h>
using namespace std;

//TC -> O(N * TARGET) + O(2N)
//SC -> O(N * TARGET) 
void tabulation(int k, vector<int> &arr, vector<vector<bool>> &dp){
    int n = arr.size();
    for(int i=0;i<n;i++){
        dp[i][0] = true;
    }
    if(arr[0] <= k) dp[0][arr[0]] = true;

    for(int i=1;i<n;i++){
        for(int target=1;target<=k;target++){
            bool notTake = dp[i-1][target];
            bool take = false;
            if(arr[i] <= target){
                take = dp[i-1][target - arr[i]];
            }
            dp[i][target] = (notTake || take);
        }
    }
}


//TC -> O(N * TARGET) + O(2N)
//SC -> O(2 * TARGET)
int solution(vector<int> &arr, int n){
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += arr[i];
    }

    //at the begining i am doing it for 0th index
    vector<bool> prev(sum+1, false);
    prev[0] = true;
    prev[arr[0]] = true;

    for(int i=1;i<n;i++){
        vector<bool> curr(sum+1, false);
        curr[0] = true;
        for(int target=1;target<=sum;target++){
            bool notTake = prev[target];
            bool take = false;
            if(arr[i] <= target){
                take = prev[target - arr[i]];
            }
            curr[target] = (notTake || take);
        }
        prev = curr;
    }

    int ans = 1e9;
    for(int i=0;i<=sum/2;i++){
        if(prev[i]){
            int s1 = i;
            int s2 = sum - s1;
            ans = min(ans, abs(s1 - s2));
        }
    }

    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int ans = solution(arr, n);
    cout<<ans<<endl;
    return 0;
}