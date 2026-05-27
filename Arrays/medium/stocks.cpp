#include<bits/stdc++.h>
using namespace std;

int besttime(int arr[], int n){
    int profit = 0;
    int mini = arr[0];
    for(int i=1;i<n;i++){
        int cost = arr[i] - mini;
        profit = max(profit, cost);
        mini = min(mini, arr[i]);
    }
    return profit;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans = besttime(arr, n);
    cout<<ans;
    return 0;
}