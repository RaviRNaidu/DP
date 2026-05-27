#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    int hash[13]={0};//here i am storing 0 inside the array at the beginning
    for(int i=0;i<n;i++){
        hash[arr[i]] += 1;//which ever index it is, i am simply adding 1 to it
    }


    int q;
    cin>>q;
    while(q--){
        int number;
        cin>>number;
        //fetching
        cout<<hash[number]<<endl;
    }
    return 0;
}