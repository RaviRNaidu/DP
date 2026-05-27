#include<bits/stdc++.h>
using namespace std;

//done by me
int counter=1;
void print(int n){
    if(counter>n)
    {
        return;
    }
    else{
        cout<<counter<<endl;
        counter++;
        print(n);
    }
}

// int main(){
//     int n;
//     cin>>n;
//     print(n);
//     return 0;
// }

//done by striver

// int cnt=0;
// void print(){
//     if(cnt==3) return;
//     cout<<cnt<<endl;
//     cnt++;
//     print();
// }

// int main(){
//     print();
// }


//print name n times(practice)
// int cnt=1;
// void print(int n){
//     if(cnt>n) return;
//     cout<<"Ravi R Naidu"<<endl;
//     cnt++;
//     print(n);
// }

// int main(){
//     int n;
//     cout<<"enter the number of times you want to print your name: ";
//     cin>>n;
//     print(n);
// }

//backtrack
void backtrack(int i,int n){
    if(i<1) return;
    backtrack(i-1,n);
    cout<<i<<endl;
}

int main(){
    int n;
    cin>>n;
    backtrack(n,n);
}
