#include<bits/stdc++.h>
using namespace std;

//most optimal approach TC = o(n)
int secondLargest(int arr[],int n){
    int largest = arr[0]; 
    int sLargest = -1; 
    for(int i = 1; i < n; i++){
        if(arr[i] > largest){
            sLargest = largest;
            largest = arr[i];
        }
        else if(arr[i]<largest && arr[i]>sLargest){
            sLargest = arr[i];
        }
    }
    return sLargest;
}




//to find the smallest
int sSmallest(int arr[], int n){
    int smallest = arr[0];
    int sSmallest =  INT_MAX;
    for(int i=1;i<n;i++){
        if(arr[i]<smallest){
            sSmallest = smallest;
            smallest = arr[i];
        }
        else if (arr[i]>smallest && arr[i]< sSmallest){
            sSmallest = arr[i];
        }
    }
    return sSmallest;
}



//better approach TC = o(2n)
int largest(int arr[],int n, int largest){
    for(int i = 0;i<n;i++){
        if(arr[i]>largest){
            largest = arr[i];
        }
    }
    return largest;
}
int secondlargest(int arr[], int n){
    int l = largest(arr, n, arr[0]);
    int sLargest = -1;
    for(int j=0;j<n;j++){
        if(arr[j]>sLargest && arr[j] != l){
            sLargest = arr[j];
        }
    }
    return sLargest;
}





int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int secondlargest = secondLargest(arr, n);
    int secondsmallest = sSmallest(arr, n);
    cout<<"secondlargest is : "<<secondlargest<<endl;
    cout<<"secondsmallest is : "<<sSmallest<<endl;
    return 0;
}