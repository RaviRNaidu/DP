#include <bits/stdc++.h>
using namespace std;

int findingindex(vector<vector<int>> &arr, int n, int col){
    int maxi = -1;
    int index = -1;
    for(int i=0;i<n;i++){
        if(arr[i][col] > maxi){
            maxi = arr[i][col];
            index = i;
        }
    }
    return index;
}

vector<int> optimal(vector<vector<int>> &arr, int n, int m){
    int low = 0;
    int high = m-1;
    while(low <= high){
        int mid = (low + high) / 2;
        int rowIndex = findingindex(arr, n, mid);
                // condition       if it is true          if it is false
        int left = mid - 1 >= 0 ? arr[rowIndex][mid - 1] : -1;  //ternary operator. basically if else statement 
        int right = mid + 1 < m ? arr[rowIndex][mid + 1] : -1;
        if(arr[rowIndex][mid] > left && arr[rowIndex][mid] > right){
            return {rowIndex, mid};
        }
        else if(arr[rowIndex][mid] < left){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return{-1, -1};
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
    vector<int> ans= optimal(arr, n, m);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}