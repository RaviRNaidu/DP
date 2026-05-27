#include<bits/stdc++.h>
using namespace std;

void fixing(vector<int> &arr, int n){
    int i = 0;
    int j = n-1;
    while(i < j){
        if(arr[i] % 3 == 0){
            swap(arr[i],arr[j]);
            j--;
        }
        else{
            i++;
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        fixing(arr, n);
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
    }
    return 0;
}