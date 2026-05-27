#include <bits/stdc++.h>
using namespace std;

int brute(vector<int> &arr, int n, int k){
    int num = k;
    for(int i=0;i<n;i++){
        if(arr[i] <= num){
            num++;
        }
        else{
            break;
        }
    }
    return num;
}

//tc --> o(log base2 n)   sc --> o(1)
int optimal(vector<int> &arr, int n, int k){
    int low = 0;
    int high = n-1;
    while(low <= high){
        int mid = (low + high) / 2;
        int missing = arr[mid] - (mid + 1);
        if(missing < k){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return high + 1 + k;    // or low + k
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k; 
    cin>>k;
    cout<<brute(arr, n, k);
    return 0;
}