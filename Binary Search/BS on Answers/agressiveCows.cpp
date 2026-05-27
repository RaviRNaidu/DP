#include <bits/stdc++.h>
using namespace std;

//tc --> O(n log n) + o(max - min * n)   sc --> o(1)
bool check(vector<int> &arr, int distance, int cows){
    int cowcnt = 1;
    int last = arr[0];
    for(int i=1;i<arr.size();i++){
        if(arr[i] - last >= distance){
            cowcnt += 1;
            last = arr[i];
        }
        if(cowcnt >= cows){
            return true;
        }
    }
    return false;
}

int brute(vector<int> &arr, int n, int cows){
    sort(arr.begin(),arr.end());
    int limit = arr[n-1] - arr[0];
    for(int i=1;i<=limit;i++){
        if(check(arr, i, cows) == true){
            continue;
        }
        else{
            return i - 1;
        }
    }
    return limit; //dummy
}

// tc --> o(n log n) + o(log base2 (max - min) * n)
int optimal(vector<int> &arr, int n, int cows){
    sort(arr.begin(),arr.end());
    int low = 1;
    int high = arr[n-1] - arr[0];
    while(low <= high){
        int mid = (low + high) / 2;
        if(check(arr, mid, cows) == false){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return high;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int cows; 
    cin>>cows;
    cout<<brute(arr, n, cows);
    return 0;
}