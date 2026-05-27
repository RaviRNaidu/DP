#include<bits/stdc++.h>
using namespace std;

int fun(int n, int m){
    int ans = 0;
    if(n % 2 == 0){
        int rem = n / 2;
        ans = rem * m;
        return ans;
    }
    else{
        int rem = n/2;
        ans = rem * m;
        ans += m /2;
        return ans;
    }
}

int main(){
    int n, m;
    cin>>n>>m;
    int ans = fun(n, m);
    cout<<ans<<endl;
    return 0;
}