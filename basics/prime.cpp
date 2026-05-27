#include<bits/stdc++.h>
using namespace std;

void prime(int n){
    int counter=0;
    for(int i=1;i*i<=n;i++){
        if(n%i==0)
        {
            counter=counter+1;
            if((n/i)!=i){
                counter=counter+1;
            }
        }
    }
    if(counter==2)
    {
        cout<<"True";
    }
    else cout<<"False";
}

int main(){
    int n;
    cin>>n;
    prime(n);
    return 0;
}