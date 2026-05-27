#include<bits/stdc++.h>
using namespace std;

int finding(vector<int> &arr, int sum){
    int n = arr.size();
    if(sum < 0) return 0;
    int s = 0;
    int cnt = 0;
    int l = 0; int r = 0;
    while(r < n){
        s += arr[r];
        while(s > sum){
            s -= arr[l];
            l++;
        }
        cnt += r - l + 1;
        r++;
    }
    return cnt;
}

int optimal(vector<int> &arr, int sum){
    return finding(arr, sum) - finding(arr,sum-1);
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum;
    cin>>sum;
    int ans = optimal(arr,sum);
    cout<<ans<<endl;
    return 0;
}