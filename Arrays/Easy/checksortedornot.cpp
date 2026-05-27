#include<bits/stdc++.h>
using namespace std;

bool check(int arr[], int n){
    for(int j=0;j<=n-2;j++){
        if(arr[j]<=arr[j+1]){
            
        }
        else return false;
    }
    return true;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=check(arr, n);
    cout<<ans;
    return 0;
}