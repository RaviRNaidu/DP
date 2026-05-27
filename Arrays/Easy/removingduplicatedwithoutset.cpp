#include<bits/stdc++.h>
using namespace std;
// REMEMBER ARRAY IS SORTED!!!!!!
int removing(int arr[], int n){
    int i = 0;
    for(int j=1;j<n;j++){
        if(arr[i] != arr[j]){
            arr[i+1] = arr[j];
            i++;
        }
    }
    return i+1; //not size but total number which are unique (length of the new array)
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int length = removing(arr, n);
    cout<<"length is: "<<length<<endl;
    for(int p=0;p<length;p++){
        cout<<arr[p]<<" ";
    }
    return 0;
}