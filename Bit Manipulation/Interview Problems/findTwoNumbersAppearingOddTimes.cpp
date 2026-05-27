#include<bits/stdc++.h>
using namespace std;

pair<int,int> finding(vector<int> &arr, int n){
    int xorr = 0;
    for(int i=0;i<n;i++){
        xorr = xorr ^ arr[i];
    }
    
    int rightmost = (xorr & (xorr - 1)) ^ xorr;
    int b1 = 0;
    int b2 = 0;
    for(int i=0;i<n;i++){
        if((arr[i] & rightmost)){
            b1 = b1 ^ arr[i];
        }
        else{
            b2 = b2 ^ arr[i];
        }
    }
    return {b1,b2};
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    pair<int,int> ans = finding(arr,n);
    cout<<ans.first<<" "<<ans.second<<endl;
    return 0;
}