#include <bits/stdc++.h>
using namespace std;

// me
int dayzz(vector<int> &arr, int num){
    int n = arr.size();
    int ans = 0; long long sum = 0;
    for(int i=0;i<n;i++){
        sum += arr[i];
        if(sum > num){
            ans += 1;
            sum = arr[i];
        }
    }
    if(sum != 0){
        ans += 1;
    }
    return ans;
}

//tc -->o((sum - maxi + 1)*n)  sc -->o(1)
int brute(vector<int> &arr, int n, int days){
    int mini = INT_MIN;
    int maxi = 0;
    for(int i=0;i<n;i++){
        mini = max(mini, arr[i]);
        maxi += arr[i];
    }

    for(int i=mini;i<=maxi;i++){
        int val = dayzz(arr, i);
        if(val <= days){
            return i;
        }
    }
    return -1;
}


//striver
int dayz(vector<int> &arr, int num){
    int n = arr.size();
    int days = 1; int load = 0;
    for(int i=0;i<n;i++){
        if(load + arr[i] > num){
            days += 1;
            load = arr[i];
        }
        else{
            load += arr[i];
        }
    }
    return days;
}

//tc -->o(log base2 (sum - maxi + 1)*n)  sc -->o(1)
int optimal(vector<int> &arr, int n, int days){
    int mini = INT_MIN;
    int maxi = 0;
    for(int i=0;i<n;i++){
        mini = max(mini, arr[i]);
        maxi += arr[i];
    }

    int low = mini;
    int high = maxi;
    while(low <= high){
        int mid = (low + high) / 2;
        int reqDays = dayz(arr, mid);
        if(reqDays <= days){
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
    int days; 
    cin>>days;
    cout<<brute(arr, n, days);
    return 0;
}