#include<bits/stdc++.h>
using namespace std;

//brutee or better 
void answer(int arr[], int n){
    int cnt0 = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    for(int i=0;i<n;i++){
        if(arr[i] == 0){
            cnt0 += 1;
        }

        else if(arr[i] == 1){
            cnt1 += 1;
        }

        else{
            cnt2 += 1;
        }
    }

    for(int i=0;i<cnt0;i++){
        arr[i] = 0;
    }

    for(int i=cnt0;i<cnt0+cnt1;i++){
        arr[i] = 1;
    }

    for(int i=cnt0+cnt1;i<n;i++){
        arr[i] = 2;
    }
}


//optimal using DUCH NATIONAL FLAG ALGORITHMMMM 
void algoo(int arr[], int n){
    int low = 0;
    int mid = 0;
    int high = n-1;
    while(mid <= high){
        if(arr[mid] == 0){
            swap(arr[low], arr[mid]);
            mid++;
            low++;
        }

        else if(arr[mid] == 1){
            mid++;
        }

        else{
            swap(arr[high], arr[mid]);
            high--;
        }

    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    algoo(arr, n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}