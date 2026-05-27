#include<bits/stdc++.h>
using namespace std;

void rightrotate(int arr[],int n, int k){
    k = k % n;
    int temp[k];
    for(int i=0;i<k;i++){
        temp[i] = arr[n-k+i];
    }

    for(int i=n-k-1;i>=0;i--){
        arr[i+k] = arr[i];
    }

    for(int i=0;i<k;i++){
        arr[i] = temp[i];
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cout<<"enter how many times u want to rotate: ";
    cin>>k;
    rightrotate(arr, n, k);
    for(int j=0;j<n;j++){
        cout<<arr[j]<<" ";
    }
    return 0;
}