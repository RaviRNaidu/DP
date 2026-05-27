#include <bits/stdc++.h>
using namespace std;

//me  tc --> o(max-min+1 * n)
int brute(vector<int> &arr, int n, int m, int k){
    if((m*k) > n){
        return -1;
    }
    int mini = INT_MAX;
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }

    for(int i=mini;i<=maxi;i++){
        int cnt = 0; int possible = 0;
        for(int j=0;j<n;j++){
            if(arr[j] <= i){
                cnt += 1;
            }
            else if(arr[j] > i){
                cnt = 0;
            }
            if(cnt >= k){
                possible += 1;
                cnt = 0;
            }
        }
        if(possible >= m){
            return i;
        }
    }
    return -1;
}

int checking(vector<int> &arr, int day, int m, int k){
    int n = arr.size();
    int cnt = 0; int possible = 0;
    for(int j=0;j<n;j++){
        if(arr[j] <= day){
            cnt += 1;
        }
        else {
            possible += (cnt / k);
            cnt = 0;
        }
    }
    possible += (cnt / k);
    if(possible >= m){
        return 1;
    }
    else return 0;
}

// tc --> o(log base2 (min - max + 1) * n)  sc --> o(1)
int optimal(vector<int> &arr, int n, int m, int k){
    if((m*k) > n){
        return -1;
    }
    int mini = INT_MAX;
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }

    int low = mini;
    int high = maxi;
    while(low <= high){
        int mid = (low + high) / 2;
        int ans = checking(arr, mid, m, k);
        if(ans == 1){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return low;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int m; // no of boque
    cin>>m;
    int k;
    cin>>k; // no of adjacent flowers 
    cout<<optimal(arr, n, m, k);
    return 0;
}