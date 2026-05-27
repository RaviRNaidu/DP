#include <bits/stdc++.h>
using namespace std;

//tc --> o(n)   sc --> o(1)
int brute(int n){
    int ans = 1;
    for(int i=1;i<n;i++){
        if(i*i <= n){
            ans = i;
        }
        else{
            break;
        }
    }
    return ans;
}

int optimal(int n){
    int ans = 1;
    int low = 1;
    int high = n;
    while(low <= high){
        int mid = (low + high) / 2;
        if(mid*mid <= n){
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return ans;
}

//tc --> o(log base2 n)
int optimalSAME(int n){
    int low = 1;
    int high = n;
    while(low <= high){
        int mid = (low + high) / 2;
        int val = mid * mid;
        if(val <= n){
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return high;
}

int main(){
    int n;
    cin>>n;
    cout<<optimalSAME(n);
    return 0;
}