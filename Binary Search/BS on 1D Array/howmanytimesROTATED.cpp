#include <bits/stdc++.h>
using namespace std;

//for unique
int countrotated(vector<int> &arr, int n){
    int low = 0;
    int high = n-1;
    int index = -1;
    int ans = INT_MAX;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[low] <= arr[high]){
            if(arr[low] < ans){
                index = low;
                ans = arr[low];
            }
            break;
        }
        if(arr[low] <= arr[mid]){
            if(arr[low] < ans){
                index = low;
                ans = arr[low];
            }
            low = mid + 1;
        }
        else{
            high = mid - 1;
            if(arr[mid] < ans){
                index = mid;
                ans = arr[mid];
            }
        }
    }
    return index;
}

//for repetative
int countrotatedRepetative(vector<int> &arr, int n){
    int low = 0;
    int high = n-1;
    int index = -1;
    int ans = INT_MAX;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[low] == arr[mid] && arr[mid] == arr[high]){
            if(arr[low] < ans){
                index = low;
                ans = arr[low];
            }
            low++;
            high--;
            continue;
        }
        //left side is sorted
        if(arr[low] <= arr[mid]){
            if(arr[low] < ans){
                index = low;
                ans = arr[low];
            }
            low = mid + 1;
        }
        //right side is sorted
        else{
            high = mid - 1;
            if(arr[mid] < ans){
                index = mid;
                ans = arr[mid];
            }
        }
    }
    return index;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<countrotatedRepetative(arr, n);
    return 0;
}