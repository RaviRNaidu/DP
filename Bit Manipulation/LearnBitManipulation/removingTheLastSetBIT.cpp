#include<bits/stdc++.h>
using namespace std;

//using left shift
void removeLastBit(int n){
    int ans = n & (n-1);
    cout<<"after : "<<ans;
}

int main(){
    int n;
    cin>>n;
    cout<<"before : "<<n<<endl;
    removeLastBit(n);
    return 0;
}