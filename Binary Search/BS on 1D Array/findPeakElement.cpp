#include <bits/stdc++.h>
using namespace std;

//tc --> o(n) sc --> o(1)
int brutePeak(vector<int> &arr, int n){
    for(int i=0;i<n;i++){
        if(i == 0){
            if(arr[i] > arr[i+1]) return arr[i];
        }
        else if(i == n-1){
            if(arr[i] > arr[i-1]) return arr[i];
        }
        else{
            if(arr[i] > arr[i+1] && arr[i] > arr[i-1]){
                return arr[i];
            }
        }
    }
    return 0;
}

// same but using single if statement DONE BY STRIVER
int brutePeakSTRIVER(vector<int> &arr, int n){
    for(int i=0;i<n;i++){
        if((i == 0 || arr[i - 1] < arr[i]) && (i == n-1 || arr[i] > arr[i+1])){
            return i;
        }
    }
    return 0;
}

// tc --> o(log base2 n) sc --> o(1)
int optimalBINARY(vector<int> &arr, int n){
    if(n == 1) return n;
    if(arr[0] > arr[1]) return 1;
    if(arr[n-1] > arr[n-2]) return n-1;
    int low = 1;
    int high = n-2;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]){
            return mid;
        }
        else if(arr[mid] > arr[mid - 1]){
            low = mid + 1;
        }
        else{
            high = mid - 1;
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
    cout<<optimalBINARY(arr, n);
    return 0;
}