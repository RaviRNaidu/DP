#include <bits/stdc++.h>
using namespace std;

//THIS IS FOR UNIQUE ELEMENTS
//tc --> o(log base2 n)
int findingUNIQUE(vector<int> &arr, int n){
    int low = 0;
    int high = n-1;
    int ans = INT_MAX;
    while(low <= high){
        int mid = (low + high) / 2;
        //if the search place is already sorted 
        //arr[low] will always be my smaller in that search space
        if(arr[low] <= arr[high]){
            ans = min(ans, arr[low]);
            break;
        }

        if(arr[low] <= arr[mid]){
            ans = min(ans, arr[low]);
            low = mid + 1;
        }
        else{
            ans = min(ans, arr[mid]);
            high = mid - 1;
        }
    }
    return ans;
}


//THIS IS FOR UNIQUE ELEMENTS
//tc --> o(log base2 n)
int findingREPEATING(vector<int> &arr, int n){
    int low = 0;
    int high = n-1;
    int ans = INT_MAX;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[low] == arr[mid] && arr[mid] == arr[high]){
            ans = min(ans, arr[mid]);
            low += 1;
            high -= 1;
            continue;
        }

        if(arr[low] <= arr[mid]){
            ans = min(ans, arr[low]);
            low = mid + 1;
        }
        else{
            ans = min(ans, arr[mid]);
            high = mid - 1;
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<findingREPEATING(arr, n);
    return 0;
}