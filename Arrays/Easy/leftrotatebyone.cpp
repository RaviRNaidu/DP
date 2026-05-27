#include<bits/stdc++.h>
using namespace std;

void rotate(int arr[], int n){
    int dup = arr[0];
    for(int i=0;i<n;i++){
        arr[i] = arr[i+1];//this might throw an error cuz we wl be accessing the index which does not exist
    }
    arr[n-1] = dup;
}

//this is wronggggggggggggg
int rotateS(int arr[], int n, int k){
    int r = 0;
    while(r<=k){
        int temp = arr[0];
        for(int i=1;i<n;i++){
            arr[i-1] = arr[i];
        }
        arr[n-1] = temp;
        r++;
    }
}

//brute force
int rotatentimes(int arr[], int n, int k){
    k = k % n;
    int temp[k];
    for(int i=0;i<k;i++){
        temp[i] = arr[i];
    }

    for(int i=k;i<n;i++){
        arr[i-k] = arr[i];
    }

    for(int i=n-k;i<n;i++){
        arr[i] = temp[i - (n-k)];
    }
}

//optimall
int optimal(int arr[], int n, int k){
    k = k % n;
    reverse(arr, arr+k);
    reverse(arr+k, arr+n);
    reverse(arr, arr+n);
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
    optimal(arr, n, k);
    for(int j=0;j<n;j++){
        cout<<arr[j]<<" ";
    }
    return 0;
}