#include<bits/stdc++.h>
using namespace std;


//using left shift
void setting(int n, int i){
    int ans = (n | (1<<i));
    cout<<"after setting: "<<ans;
}

int main(){
    int n, i;
    cin>>n;
    cout<<"enter the bit number: ";
    cin>>i;
    cout<<"before setting : "<<n<<endl;
    setting(n,i);
    return 0;
}