#include<bits/stdc++.h>
using namespace std;

//TC -> O(N)    SC -> O(1)
int brute(vector<int> &arr, int n){
    int jumps = 0;
    int l = 0; int r = 0;
    while(r < n-1){
        int furtherest = 0;
        for(int i=l;i<=r;i++){
            furtherest = max(furtherest, i+arr[i]);
        }
        l = r+1;
        r = furtherest;
        jumps++;
    }
    return jumps;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans = brute(arr,n);
    cout<<ans<<endl;
    return 0;
}