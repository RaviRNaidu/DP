#include<bits/stdc++.h>
using namespace std;

//TC -> O(N)+O(N LOG N)   SC -> O(1)
int brute(vector<int> &arr, int n){
    sort(arr.begin(),arr.end());
    int WaitTime = 0;
    int time = 0;
    for(int i=0;i<n;i++){
        WaitTime += time;
        time += arr[i];  
    }
    return WaitTime / n;
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