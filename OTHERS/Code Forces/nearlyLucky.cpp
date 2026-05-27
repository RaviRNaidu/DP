#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin>>n;

    long long lucky = 0;
    while(n > 0){
        long long rem = n % 10;
        if(rem == 4 || rem == 7) lucky++;
        n = n / 10;
    }

    if(lucky == 4 || lucky == 7) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}