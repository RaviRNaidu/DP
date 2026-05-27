#include<bits/stdc++.h>
using namespace std;

//BRUTE TC -> O(dividend / divisior)
int divide(int dividend, int divisior){
    int ans = 0;
    int sum = 0;
    while((sum+divisior) <= dividend){
        sum += divisior;
        ans++;
    }
    return ans;
}

int better(int dividend, int divisior){
    if(dividend == divisior){
        return 1;
    }

    bool sign = true;
    if(dividend < 0 && divisior > 0){
        sign = false;
    }
    else if(dividend >= 0 && divisior < 0){
        sign = false;
    }
    
    int n = abs(dividend);
    int d = abs(divisior);
    int ans = 0;
    while(n >= d){
        int pow = 0;
        while(n >= (d<<(pow+1))){
            pow++;
        }
        ans = ans + (1<<pow);
        n = n - (d<<(pow));
    }
    if(ans >= (1<<31) && (sign == true)) {
        return INT_MAX;
    }
    if(ans >= (1<<31) && !sign){
        return INT_MIN;
    }
    return sign ? ans : -1 * ans;
}

int main(){
    int dividend, divisior;
    cin>>dividend;
    cin>>divisior;
    int ans = divide(dividend,divisior);
    cout<<ans;
}