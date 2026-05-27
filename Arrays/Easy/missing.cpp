#include<bits/stdc++.h>
using namespace std;

//brute                   tc = o(n1*n2)
int missing(int arr[], int n){
    for(int i=1;i<=n;i++){
        int flag = 0; //it will be 0 for each iteration
        for(int j=0;j<n-1;j++){
            if(arr[j] == i){
                flag = 1;
                break;
            }
        }
        if(flag == 0 ) return i;
    }
}

//better                    tc = o(2n)         sc = o(n)
int better(int arr[], int n){
    int hash[n+1] = {0};
    for(int i=0;i<n;i++){
        hash[arr[i]] = 1;
    }

    for(int i=1;i<n+1;i++){
        if(hash[i] == 0){
            return i;
        }
    }
}

//optimal 1                      tc = o(n) sc = o(1) this is not better than the xor because this might take more space to sum up the natural numbers
int sum(int arr[], int n){
    int sum = n*(n+1)/2;
    int sl = 0;
    for(int i=0;i<n-1;i++){
        sl += arr[i];
    }

    return sum - sl;
}

//better 2 using xor                   tc = o(2n)
int xorbetter(int arr[], int n){
    int xor1 = 0, xor2 = 0;
    for(int i=1;i<=n;i++){
        xor1 = xor1 ^ i;
    }

    for(int i=0;i<n-1;i++){
        xor2 = xor2 ^ arr[i];
    }

    return xor1 ^ xor2;
}


//optimal2                          tc = o(n) sc = o(1)   
int zorr(int arr[], int n){
    int xor1, xor2;
    for(int i=0;i<n-1;i++){
        xor1 = xor1 ^ arr[i];
        xor2 = xor2 ^ (i+1);
    }
    xor2 = xor2 ^ n;

    return xor1 ^ xor2;
}

int main(){
    int n;
    cin>>n;
    int arr[n-1];
    for(int i=0;i<n-1;i++){
        cin>>arr[i];
    }
    int ans = xorbetter(arr, n);
    cout<<ans;
    return 0;
}