#include <bits/stdc++.h>
using namespace std;

//tc -->o(m * n) / o(m * log n) if u use the square function
long long sqRoot(int i, int n){
    int val = 1;
    for(int j=1;j<=n;j++){
        val = val*i;
    }
    return val;
}
int brute(int n, int m){
    for(int i=1;i<m;i++){
        long long val = sqRoot(i,n);
        if(val == m){
            return i;
        }
        else if(val > m){
            break;
        }
    }
    return -1;
}

//tc --> o(log base2 m * log base2 n) if ur using square function else if u use a for loop 
//like i did here it will be o(log base2 m * n)
long long sqRootOPTIMAL(int i, int n, int m){
    // if val == m return 1
    //if val > m return 2
    //if val < m return 0 
    long long val = 1;
    for(int j=1;j<=n;j++){
        val = val*i;
        if(val > m) return 2;
    }
    if(val == m) return 1;
    return 0;
}

int optimal(int n, int m){
    int low = 1;
    int high = m;
    while(low <= high){
        int mid = (low + high) / 2;
        int val = sqRootOPTIMAL(mid, n, m);
        if(val == 1){
            return mid;
        }
        else if(val > 2){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return -1;
}

int optimal1(int n, int m){
    int low = 1;
    int high = m;
    while(low <= high){
        int mid = (low + high) / 2;
        int val = sqRoot(mid, n);
        if(val == m){
            return mid;
        }
        else if(val > m){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return -1;
}

int main(){
    int n, m;
    cin>>n;
    cin>>m;
    cout<<optimal1(n, m);
    return 0;
}