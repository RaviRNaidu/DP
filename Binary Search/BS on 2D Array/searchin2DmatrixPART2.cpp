#include <bits/stdc++.h>
using namespace std;

int binary(vector<int> &arr, int target){
    int n = arr.size();
    int low = 0;
    int high = n-1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] == target){
            return mid;
        } 
        else if(arr[mid] > target){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return -1;
}

//tc --> o(n * log base2 m) sc -->o(1)
vector<int> better(vector<vector<int>> &arr, int n, int m, int target){
    for(int i=0;i<n;i++){
        int index = binary(arr[i], target);
        if(index != -1){
            return {i,index};
        }
    }
    return{-1,-1};
}

//tc --> o(log base2 n+m) sc --> o(1)
bool optimal(vector<vector<int>> &arr, int n, int m, int target){
    int row = 0;
    int col = m-1;
    while(row < n && col >= 0){
        if(arr[row][col] == target){
            return true;
        }
        else if(arr[row][col] > target){
            col --;
        }
        else {
            row ++;
        }
    }
    return false;
}

int main(){
    int n,m;
    cin>>n;
    cin>>m;
    vector<vector<int>> arr(n,vector<int>(m)); 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    int target;
    cin>>target;
    vector<int> ans= better(arr, n, m,target);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}