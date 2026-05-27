#include<bits/stdc++.h>
using namespace std;

void bubble(int arr[], int n){
    for(int i=n-1;i>=0;i--){
        int swap=0;
        for(int j=0;j<i;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
                swap += 1;
            }
        }
        if(swap == 0)// time complexity will be o(n)
        break;
    }
}

void bubbleRecursion(int arr[], int n){
    int swap = 0;
    if(n==1) {
        return;
    }
    else {
        for(int j=0;j<=n-2;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
                swap += 1;
            }
        }
    }
    if(swap==0) return;
    bubbleRecursion(arr, n-1);

}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    bubbleRecursion(arr,n);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}