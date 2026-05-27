#include <bits/stdc++.h>
using namespace std;

//tc --> o(n)  sc --> o(1)
int brute(vector<int> &arr, int n){
    if(n == 1) return arr[0];
    for(int i=0;i<n;i++){
        if(i == 0){
            if(arr[i] != arr[i+1]){
                return arr[i];
            }
        }
        else if(i == n-1){
            if(arr[i] != arr[i-1]){
                return arr[i];
            }
        }
        else{
            if(arr[i] != arr[i+1] && arr[i] != arr[i-1]){
                return arr[i];
            }
        }
    }
    return -1;
}


//striver
int optimalBINARY(vector<int> &arr, int n){
    if(n == 1) return arr[0];
    if(arr[0] != arr[1]) return arr[0];
    if(arr[n-1] != arr[n-2]) return arr[n-1];
    int low = 1;
    int high = n-2;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1]){
            return arr[mid];
        }
        //we are on the left side 
        if( (mid % 2 == 1 && arr[mid] == arr[mid - 1] )|| (mid % 2 == 0 && arr[mid] == arr[mid + 1]) ){
            low = mid + 1;
        }
        //we are on the right side
        else{
            high = mid - 1;
        }
    }
    return -1;
}

//me 
int optimalBINARYME(vector<int> &arr, int n){
    if(n == 1) return arr[0];
    if(arr[0] != arr[1]) return arr[0];
    if(arr[n-1] != arr[n-2]) return arr[n-1];
    int low = 1;
    int high = n-2;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1]){
            return arr[mid];
        }
        if(arr[mid] == arr[mid - 1]){
            if(mid % 2 == 0){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        else{
            if(mid % 2 == 0){
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
    cout<<optimalBINARYME(arr, n);
    return 0;
}