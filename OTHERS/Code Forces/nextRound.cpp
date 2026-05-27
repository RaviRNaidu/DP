#include<bits/stdc++.h>
using namespace std;

int fun(int n, int k, vector<int> &arr){
    int ans = 0;
    int score = arr[k - 1];
    for(int i=0;i<n;i++){
        if(arr[i] >= score && arr[i] > 0){
            ans++;
        }
    }
    return ans;
}

int main(){
    int n, k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans = fun(n, k, arr);
    cout<<ans<<endl;
    return 0;
}