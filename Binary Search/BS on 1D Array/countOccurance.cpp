#include <bits/stdc++.h>
using namespace std;

int first(vector<int> &arr, int n, int target){
    int low = 0;
    int high = n-1;
    int first = -1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] == target){
            first = mid;
            high = mid - 1;
        }
        else if(arr[mid] < target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return first;
}

int second(vector<int> &arr, int n, int target){
    int low = 0;
    int high = n-1;
    int last = -1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] == target){
            last = mid;
            low = mid + 1;;
        }
        else if(arr[mid] > target){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return last;
}

int binaryy(vector<int> &arr, int n, int target){
    pair<int, int> ans;
    ans.first = first(arr, n, target);
    ans.second = second(arr, n, target);
    if(ans.first == -1){
        return 0;
    }
    else{
        return {ans.second - ans.first + 1};
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int target;
    cin>>target;
    int ans = binaryy(arr, n, target);
    cout<<ans;
    return 0;
}