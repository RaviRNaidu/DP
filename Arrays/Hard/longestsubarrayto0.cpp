#include<bits/stdc++.h>
using namespace std;

int brute(vector<int> &arr, int n){
    int longest = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int sum = 0;
            for(int k=i;k<=j;k++){
                sum += arr[k];
            }
            if(sum == 0){
                longest = max (longest, j - i + 1);
            }
        }
    }
    return longest;
}

int better(vector<int> &arr, int n){
    int longest = 0;
    for(int i=0;i<n;i++){
        int sum = arr[i];
        for(int j=i+1;j<n;j++){
            sum += arr[j];
            if(sum == 0){
                longest = max(longest, j - i + 1); 
            }
        }
    }
    return longest;
}

int optimall(vector<int> &arr, int n){
    map<int,int> mpp;
    int longest = 0;
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += arr[i];
        if(sum == 0){
            longest = i + 1;
        }
        else{
            if(mpp.find(sum) != mpp.end()){
                longest = max(longest, i - mpp[sum]);
            }
            else{
                mpp[sum] = i;
            }
        }
        
    }
    return longest;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans = optimall(arr,n);
    cout<<ans;
    return 0;
}