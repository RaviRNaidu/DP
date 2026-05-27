#include<bits/stdc++.h>
using namespace std;

int reverse(int n){
    int num = 0;
    while(n != 0){
        num += n%10;
        n = n / 10;
        if(n)num *= 10;
    }
    return num;
}

int main(){
    int n;
    cin>>n;
    int rev = reverse(n);
    cout<<n<<" "<<rev<<endl;
    return 0;
}