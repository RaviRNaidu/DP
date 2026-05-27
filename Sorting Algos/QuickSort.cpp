#include<bits/stdc++.h>
using namespace std;

int partiation(vector<int> &arr, int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i<j){
        while(arr[i]<= pivot && i<=high-1){
            i++;
        } 
        while(arr[j]> pivot && j>=low+1){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[low],arr[j]);
    return j;
}

void QuickSort(vector<int> &arr,int low, int high){
    if(low < high) {
        int pIndex=partiation(arr, low, high);
        QuickSort(arr, low, pIndex-1);
        QuickSort(arr, pIndex+1, high);
    }

}

int partitionDecending(vector<int> &arr, int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i<j){
        while(arr[i]>=pivot && i <= high-1){
            i++;
        }

        while(arr[j]<pivot && j >= low+1){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[low],arr[j]);
    return j;
}

void QuickSortDecending(vector<int> &arr, int low, int high){
    if(low < high){
        int pIndex=partitionDecending(arr, low, high);
        QuickSortDecending(arr, low, pIndex-1);
        QuickSortDecending(arr, pIndex+1,high);
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    QuickSortDecending(arr, 0, n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}