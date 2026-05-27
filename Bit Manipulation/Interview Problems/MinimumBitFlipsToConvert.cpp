#include<bits/stdc++.h>
using namespace std;

//TC -> log base 2 (a^b)
//SC -> o(1) 
int counting(int a, int b){
    int ans = a ^ b;
    int cnt = 0;
    while(ans > 0){
        if((ans & 1) == 1){
            cnt++;
        }
        ans = ans>>1;
    }
    return cnt;
}

int main(){
    int a,b;
    cin>>a;
    cin>>b;
    int ans = counting(a,b);
    cout<<"NO of bit flips are: "<<ans<<endl;
    return 0;
}