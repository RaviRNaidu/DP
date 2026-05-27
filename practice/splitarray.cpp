#include <bits/stdc++.h>
using namespace std;

int count(vector<int> arr, int max){
    int ans = 1;
    int sum = 0;
    for(int i=0;i<arr.size();i++){
        if(sum + arr[i] <= max){
            sum += arr[i];
        }
        else{
            ans++;
            sum = arr[i];
        }
    }
    return ans;
}

int brute(vector<int> arr, int n, int k){
    if(k > n) return -1;
    int high = 0;
    int sum = 0;
    for(int i=0;i<n;i++){
        high = max(high,arr[i]);
        sum += arr[i];
    }

    for(int j=high;j<=sum;j++){
        int ans = count(arr,j);
        if(ans == k){
            return j;
        }
    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k; 
    cin>>k;
    cout<<brute(arr, n, k);
    return 0;
}