#include<bits/stdc++.h>
using namespace std;

void insertion(int arr[], int n){
    for(int i=0; i<=n-1;i++){
        int j=i;
        while(j>0 && arr[j]<arr[j-1])
        {
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;

            j--;
        }
    }
}

void recursiveInsertion(int arr[], int n, int i){
    if(i==n) return;
    int j=i;
    while(j>0 && arr[j]<arr[j-1]){
        int temp = arr[j-1];
        arr[j-1] = arr[j];
        arr[j] = temp;
        j--;
    }
    recursiveInsertion(arr, n, i+1);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    recursiveInsertion(arr,n,0);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}