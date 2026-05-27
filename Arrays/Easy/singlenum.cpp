#include<bits/stdc++.h>
using namespace std;

//brute
int single(int arr[], int n){
    for(int i=0;i<n;i++){
        int cnt = 0;
        for(int j=0;j<n;j++){
            if(arr[i] == arr[j]){
                cnt ++;
            }
        }
        if(cnt != 2) return arr[i];
    }
}

//better
int hashingg(int arr[], int n){
    map<int, int> mpp;
    for(int i=0;i<n;i++){
        mpp[arr[i]] ++;
    }

    for(auto it:mpp){
        if(it.second == 1){
            return it.first;
        }
    }
}

int optimall(int arr[], int n){
    int xor1 = 0;
    for(int i=0;i<n;i++){
        xor1 = xor1 ^ arr[i];
    }

    return xor1;
}


int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans = optimall(arr, n);
    cout<<ans;
    return 0;
}