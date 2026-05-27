#include<bits/stdc++.h>
using namespace std;

int fun(int n, int m){
    while(m > 0){
        int last = n % 10;
        if(last == 0){
            n = n / 10;
        }
        else{
            n = n - 1;
        }
        m--;
    }
    return n;
}

 int main(){
    int n, m;
    cin >> n >> m;
    int ans = fun(n , m);
    cout<<ans<<endl;
    return 0;
 }