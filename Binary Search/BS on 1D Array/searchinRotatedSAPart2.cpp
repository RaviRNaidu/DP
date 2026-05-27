#include <bits/stdc++.h>
using namespace std;

//tc --> o(log base2 n) on average case but o(n/2) on worst case cuz u will be trimming the array if the second condition is true
bool rotated2 (vector<int> &arr, int n, int target){
    int low = 0;
    int high = n-1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] == target){
            return true;
        }
        if(arr[mid] == arr[low] && arr[mid] == arr[high]){
            low = low + 1;
            high = high - 1;
            continue;
        }
        if(arr[low] <= arr[mid] ){
            if(arr[low] <= target && target <= arr[mid]){
                high = mid -1;
            }
            else{
                low = mid + 1;
            }
        }
        else{
            if(arr[mid] <= target && target <= arr[high]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }
    return false;
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
    cout<<rotated2(arr, n, target);
    return 0;
}