#include<bits/stdc++.h>
using namespace std;

int consecutive(int arr[], int n){
    int maxi = 0;
    int counter = 0;
    for(int i=0;i<n;i++){
        if(arr[i] == 1){
            counter ++;
            maxi = max(maxi,counter);
        }
        else {
            counter = 0;
        }
    }
    return maxi;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans = consecutive(arr, n);
    cout<<ans;
    return 0;
}