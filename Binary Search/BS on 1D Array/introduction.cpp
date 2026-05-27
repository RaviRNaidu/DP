#include <bits/stdc++.h>
using namespace std;

//tc --> o(log base 2 n)
//if n is 32. 32 = 2^5 similarly 64 = 2^6
//for this example it is
//(log base2 32)
//log base2 2^5
// 5 * log base2 * 2
// 5 * 1
//5 steps
int split(vector<int> &arr, int low, int high, int target){
    if(low > high) return -1;
    int mid = (low + high) / 2;
    if(arr[mid] == target){
        return mid;
    }
    else if(target > arr[mid]){
        return split(arr, mid + 1, high, target);
    }
    else{
        return split(arr, low, mid - 1, target);
    }
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
    cout<<split(arr,0,n-1,target);
    return 0;
}