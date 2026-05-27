#include<bits/stdc++.h>
using namespace std;

//to print n to 1
//me
// void printNto1(int n){
//     if(n==0) return;
//     cout<<n<<endl;
//     n--;
//     printNto1(n);
// }

// int main(){
//     int n;
//     cin>>n;
//     printNto1(n);
// }

//striver
void print(int i, int n){
    if(i<1) return;
    cout<<i<<endl;
    print(i-1,n);
}

int main(){
    int n;
    cin>>n;
    print(n,n);
}