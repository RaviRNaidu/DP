#include <bits/stdc++.h>
using namespace std;

int rotatedd(vector<int> &arr, int n, int target){
    int low = 0;
    int high = n-1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] == target){
            return mid;
        }
        //left side is sorted
        if(arr[low] <= arr[mid]){
            if(arr[low] <= target && target <= arr[mid]){
                high = mid -1;
            }
            else{
                low = mid + 1;
            }
        }
        //right side is sorted
        else{
            if(arr[mid] <= target && target <= arr[high]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }
    return -1;
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
    int ans = rotatedd(arr, n, target);
    cout<<ans;
    return 0;
}