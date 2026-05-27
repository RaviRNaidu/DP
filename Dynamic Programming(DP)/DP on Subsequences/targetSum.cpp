#include<bits/stdc++.h>
using namespace std;

int recursion(int i, int target, vector<int> &arr){
    if(i == 0){
        if(target - arr[i] == 0) return 1;
        else if(target + arr[i] == 0) return 1;
        else return 0;
    }

    int pos = recursion(i-1, target - arr[i], arr);
    int neg = recursion(i-1, target + arr[i], arr);

    return pos + neg;
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
    // vector<vector<int>> dp(n, vector<int> (target+1,-1));
    int ans = recursion(n-1, target, arr);
    // cout<<memoization(n-1, target, arr, dp)<<endl;
    // cout<<tabulation(target, arr, n)<<endl;
    // cout<<spaceOptimization(target, arr, n)<<endl;
    cout<<ans<<endl;
    return 0;
} 