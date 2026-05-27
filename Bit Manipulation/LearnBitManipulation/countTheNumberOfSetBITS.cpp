#include<bits/stdc++.h>
using namespace std;

//NOTE : THE LAST BIT OF AN ODD NUMBER WILL ALWAYS BE ONE 
//Right shift by one is same as dividing it by 2
int countingUsingBITSTUFF(int n){
    int cnt = 0;
    while(n > 0){
        cnt += (n & 1);
        n = n>>1;
    }
    return cnt;
}

int counting(int n){
    int cnt = 0;
    while(n > 0){
        if(n % 2 == 1){
            cnt++;
        }
        n /= 2;
    }
    return cnt;
}

//or theres one more way of doing this, that is changing the last set bit and keeping a count
//TC -> o(no of sets)
int countingUsingMagic(int n){
    int cnt = 0;
    while(n != 0){
        n = n & (n-1);
        cnt++;
    }
    return cnt;
}

int main(){
    int n;
    cin>>n;
    int ans = countingUsingMagic(n);
    cout<<"NO of Set bits are: "<<ans<<endl;
    return 0;
}