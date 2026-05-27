#include <bits/stdc++.h>
using namespace std;

int optimall(int arr[], int n, int k){
    map <int, int> mpp;
    mpp[0] = 1;
    int cnt = 0;
    int sum = 0;
    for(int i=0;i<n;i++){
        sum = sum + arr[i];
        int rem = sum - k;
        cnt = cnt + mpp[rem];
        mpp[sum] += 1;
    }
    return cnt;
}


int practice(int arr[], int n, int k){
    map<long,int> mpp;
    mpp[0] = 1;
    int sum = 0;
    int cnt = 0;
    for(int i=0;i<n;i++){
        sum += arr[i];
        int rem = sum - k;
        if(mpp.find(rem) != mpp.end()){
            cnt = cnt + mpp[rem];
        }
        mpp[sum]++;
    }
    return cnt;
}


int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    int ans = optimall(arr, n, k);
    cout<<ans;
    return 0;
}