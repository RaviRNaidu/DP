#include <bits/stdc++.h>
using namespace std;


//tc --> o(log base 2 n)
int loop(vector<int> &arr, int n, int target){
    int low = 0;
    int high = n-1;
    int ans = n;
    while(low <= high){
        int mid = (low + high) / 2;
        //maybe an answer
        if(arr[mid] >= target){
            ans = mid;
            //look for smaller index 
            high = mid - 1;
        }
        else {
            low = mid + 1;//look for right side
        }
    }
    return ans;
}

//theres a simpler single line code and that is
// int lb = lower_bound(arr.begin(),arr.end(), x/target) - arr.begin();     this is for vector
// int lb = lower_bound(arr, arr + n, x/target) - arr;     this is for array
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int target;
    cin>>target;
    cout<<loop(arr,n,target);
    return 0;
}