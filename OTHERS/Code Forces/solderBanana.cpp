#include<bits/stdc++.h>
using namespace std;

int finding(int k, int n, int w){
    int sum = 0;
    for(int i=1;i<=w;i++){
        sum += (i * k);
    }
    if(sum - n <= 0) return 0;
    return sum - n;
}

int main(){
    int k, n, w;
    cin>>k>>n>>w;
    cout<<finding(k, n, w)<<endl;
    return 0;
}