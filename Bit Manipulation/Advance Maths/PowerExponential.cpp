#include<bits/stdc++.h>
using namespace std;

// TC -> O(LOG BASE 2 N)
//SC -> O(1)
int optimal(int x, int n){
    int ans = 1;
    while(n > 0){
        if(n % 2 == 1){
            ans = ans * x;
            n = n - 1;
        }
        else{
            x = x * x;
            n = n / 2;
        }
    }
    return ans;
}

//for negative numbers
int optimalFornegative(int x, int n){
    int m = n;
    int ans = 1;
    while(n > 0){
        if(n % 2 == 1){
            ans = ans * x;
            n = n - 1;
        }
        else{
            x = x * x;
            n = n / 2;
        }
    }
    if(m < 0){
        ans = 1 / ans;
    }
    return ans;
}

//for double 
int optimalFornegative(double x, int n){
    int m = n;
    double ans = 1;
    while(n > 0){
        if(n % 2 == 1){
            ans = ans * x;
            n = n - 1;
        }
        else{
            x = x * x;
            n = n / 2;
        }
    }
    if(m < 0){
        ans = 1.0 / ans;
    }
    return ans;
}

//TC -> O(N)
int brute(int x, int n){
    int ans = 1;
    for(int i=1;i<=n;i++){
        ans = ans*x;
    }
    return ans;
}

int main(){
    int n, x;
    cin>>x;
    cin>>n;
    int ans = optimal(x,n);
    cout<<ans;
    return 0;
}