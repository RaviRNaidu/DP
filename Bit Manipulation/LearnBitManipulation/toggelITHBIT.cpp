#include<bits/stdc++.h>
using namespace std;

//using left shift
void toggel(int n, int i){
    int ans = (n ^ (1<<i));
    cout<<"after toggel: "<<ans;
}

int main(){
    int n, i;
    cin>>n;
    cout<<"enter the bit number: ";
    cin>>i;
    cout<<"before toggel : "<<n<<endl;
    toggel(n,i);
    return 0;
}