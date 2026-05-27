#include<bits/stdc++.h>
using namespace std;

//TC -> O(n)    SC -> O(1)
//BRUTEE
int XORinRange(int l, int r){
    int ans = 0;
    for(int i=l;i<=r;i++){
        ans = ans ^ i;
    }
    return ans;
}

//OPTIMAL
//finding 1 to n
int optimal(int n){
    if(n % 4 == 1){
        return 1;
    }
    else if (n % 4 == 2){
        return n+1;
    }
    else if(n % 4 == 3){
        return 0;
    }
    else{
        return n;
    }
}

//optimal for l to r
int optimalForLtoR(int l, int r){
    int ans = optimal(l - 1) ^ optimal(r);
    return ans;
}

int main(){
    int l,r;
    cin>>l;
    cin>>r;
    int ans = optimalForLtoR(l,r);
    cout<<ans;
    return 0;
}