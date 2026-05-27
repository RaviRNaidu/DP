#include<bits/stdc++.h>
using namespace std;


//using left shift
void clearing(int n, int i){
    int ans = (n & ~ (1<<i));
    cout<<"after clearing: "<<ans;
}

int main(){
    int n, i;
    cin>>n;
    cout<<"enter the bit number: ";
    cin>>i;
    cout<<"before clearing : "<<n<<endl;
    clearing(n,i);
    return 0;
}