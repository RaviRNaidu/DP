#include<bits/stdc++.h>
using namespace std;


// DONE BY NAIDUU 
int brute(vector<int> &arr, int n, int k){
    int result = 0;
    int sum = 0;
    for(int i=0;i<k;i++){
        sum += arr[i];
    }
    result = sum;

    int r = n-1;
    int l = k-1;
    while(r >= n-k){
        sum -= arr[l];
        l--;
        sum += arr[r];
        result = max(result, sum);
        r--;
    }
    return result;
}

//DONE BY STRIVER
//TC -> O(2K)   SC -> 0(1)
int striver(vector<int> &arr, int n, int k){
    int lsum = 0;
    int rsum = 0;
    int maxsum = 0;
    for(int i=0;i<k;i++){
        lsum += arr[i];
    }

    maxsum = lsum;
    int rightIndex = n-1;
    for(int i=k-1;i>=0;i--){
        lsum -= arr[i];
        rsum += arr[rightIndex];
        rightIndex--;
        maxsum = max(maxsum, (lsum+rsum));
    }

    return maxsum;
}

int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans = striver(arr, n, k);
    cout<<ans<<endl;
    return 0;
}