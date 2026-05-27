#include <bits/stdc++.h>
using namespace std;

int sum(vector<int> &arr, int num, int limit){
    int n = arr.size();
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += ceil((double)arr[i] / (double)num);
    }
    return sum;
}

//tc --> 0( maxi * n)  sc --> o(1)
int brute(vector<int> &arr, int n, int limit){
    if(limit > n) return -1;
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        maxi = max(maxi, arr[i]);
    }

    for(int i=1;i<=maxi;i++){
        int val = sum(arr, i, limit);
        if(val <= limit){
            return i;
        }
    }
    return -1;
}

//tc --> 0( log base2 maxi * n)  sc --> o(1)
int optimal(vector<int> &arr, int n, int limit){
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        maxi = max(maxi, arr[i]);
    }

    int low = 1;
    int high = maxi;
    while(low <= high){
        int mid = (low + high) / 2;
        int val = sum(arr, mid, limit);
        if(val <= limit){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return low;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int limit; 
    cin>>limit;
    cout<<optimal(arr, n, limit);
    return 0;
}