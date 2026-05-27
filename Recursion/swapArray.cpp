#include<bits/stdc++.h>
using namespace std;
//creating an ARRAY
// int main(){
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     for(int i=0;i<n;i++)cout<<arr[i]<<" ";
// }

//main code starts from here

void reverseArray(int i, int arr[], int n){
    if(i>=n/2) return;
    swap(arr[i],arr[n-i-1]);
    reverseArray(i+1,arr,n);
}

void twopointers(int i,int arr[],int r){
    if(i>r) return;
    swap(arr[i],arr[r]);
    twopointers(i+1,arr,r-1);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    twopointers(0,arr,n-1);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}