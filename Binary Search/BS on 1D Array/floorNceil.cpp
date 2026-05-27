#include <bits/stdc++.h>
using namespace std;

int floor(vector<int> &arr, int n, int target){
    int low = 0;
    int high = n-1;
    int floor = -1;
    while( low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] <= target){
            floor = arr[mid];
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return floor;
}

int ceil(vector<int> &arr, int n, int target){
    int low = 0;
    int high = n-1;
    int ceil = -1;
    while( low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] >= target){
            ceil = arr[mid];
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ceil;
}
        

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int target;
    cin>>target;
    int floorans = floor(arr,n,target);
    int ceilans = ceil(arr,n,target);
    cout<<"Floor of the target is: "<<floorans<<endl<<"Ceil of the target is: "<<ceilans;
    return 0;
}