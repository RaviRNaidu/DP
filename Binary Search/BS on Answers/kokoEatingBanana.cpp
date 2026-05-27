#include <bits/stdc++.h>
using namespace std;

int hours(vector<int> &arr, int hourly){
    int n = arr.size();
    int total = 0;
    for(int i=0;i<n;i++){
        total += ceil((double)arr[i] / (double)hourly);  //MAKE SURE THE U GIVE DOUBLE CUZ THE CEIL SHOULD GET A DOUBLE VALUE WHICH INCLUDES DECIMAL.
    }
    return total;
}

//tc --> o(max(arr element) * n)
int brute(vector<int> &arr, int n, int h){
    int maxi = 0;
    for(int i=0;i<n;i++){
        maxi = max(maxi, arr[i]);
    }

    for(int i=1;i<=maxi;i++){
        int totalhr = hours(arr,i);
        if(totalhr <= h){
            return i;
        }
    }
    return -1;
}


//tc --> o(n* log base2 max element)
int optimal(vector<int> &arr, int n, int h){
    int maxEL = INT_MIN;
    for(int i=0;i<n;i++){
        maxEL = max(maxEL, arr[i]);
    }

    int low = 1;
    int high = maxEL;
    while(low <= high){
        int mid = (low + high) / 2;
        int totalhr = hours(arr, mid);
        if(totalhr <= h){
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
    int h;
    cin>>h;
    cout<<optimal(arr, n, h);
    return 0;
}