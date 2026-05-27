#include<bits/stdc++.h>
using namespace std;

//TC -> O(3N)    SC -> O(2N)
int brute(vector<int> &arr, int n){
    vector<int> left(n);
    vector<int> right(n);
    left[0] = 1; right[n-1] = 1;
    for(int i=1;i<n;i++){
        if(arr[i] > arr[i-1]){
            left[i] = left[i-1]+1;
        }
        else{
            left[i] = 1;
        }
    }

    for(int i=n-2;i>=0;i--){
        if(arr[i] > arr[i+1]){
            right[i] = right[i+1]+1;
        }
        else{
            right[i] = 1;
        }
    }

    int sum = 0;
    for(int i=0;i<n;i++){
        sum += max(left[i], right[i]);
    }
    return sum;
}

//TC -> O(2N)    SC -> O(N)
//ME
int better(vector<int> &arr, int n){
    vector<int> left(n);
    left[0] = 1;
    for(int i=1;i<n;i++){
        if(arr[i] > arr[i-1]){
            left[i] = left[i-1]+1;
        }
        else{
            left[i] = 1;
        }
    }

    int sum = left[n-1];
    for(int i=n-2;i>=0;i--){
        if(arr[i] > arr[i+1]){
            left[i] = max(left[i],left[i+1]+1);
        }
        sum += left[i];
    }

    return sum;
}

//TC -> O(2N)    SC -> O(N)
//striver
int better1(vector<int> &arr, int n){
    vector<int> left(n);
    left[0] = 1;
    for(int i=1;i<n;i++){
        if(arr[i] > arr[i-1]){
            left[i] = left[i-1]+1;
        }
        else{
            left[i] = 1;
        }
    }

    int sum = max(1,left[n-1]);
    int curr = 1;
    int right = 1;
    for(int i=n-2;i>=0;i--){
        if(arr[i] > arr[i+1]){
            curr = right+1;
        }
        else{
            curr = 1;
        }
        right = curr;
        sum += max(left[i],curr);
    }

    return sum;
}

//TC -> O(N)    SC -> O(1)
int optimal(vector<int> &arr, int n){
    int sum = 1; int i = 1;
    while(i < n){
        if(arr[i] == arr[i-1]){
            sum += 1;
            i++;
            continue;
        }
        int peak = 0;
        while(i < n && arr[i] > arr[i-1]){
            peak += 1;
            sum += peak;
            i++;
        }
        int down = 0;
        while(i < n && arr[i] < arr[i-1]){
            down += 1;
            sum += down;
            i++;
        }
        if(down > peak){
            sum += (down - peak);
        }
    }
    return sum;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans = optimal(arr,n);
    cout<<ans<<endl;
    return 0;
}