#include<bits/stdc++.h>
using namespace std;
//brute
int brute(int arr[], int n){
    int maxSum = 0;
    for(int i=0;i<n;i++){
        int sum =0;
        for(int j=i;j<n;j++){
            sum = sum + arr[j];
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
}

//optimal
int kadane(int arr[], int n){
    int maxSum = INT_MIN;
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += arr[i];
    
        if(sum > maxSum){
            maxSum = sum;
        }
        
        if(sum < 0){
            sum = 0;
        }
    }
    return maxSum;
}

//if u want to return the index
int kadaneindex(int arr[], int n){
    int maxSum = INT_MIN;
    int sum = 0;
    int start = 0;
    int ansStart = -1; int ansEnd = -1;
    for(int i=0;i<n;i++){
        if (sum == 0){
            start = i;  //starting point of the subarray
        }

        sum += arr[i];
    
        if(sum > maxSum){
            maxSum = sum;
            ansStart = start; ansEnd = i; //start will be start and end will be i
        }
        
        if(sum < 0){
            sum = 0;
        }
    }
    return maxSum;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans = kadane(arr, n);
    cout<<ans;
    return 0;
}