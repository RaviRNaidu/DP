#include <bits/stdc++.h>
using namespace std;

//tc --> o(n*m)  sc --> o(1)
bool brute(vector<vector<int>> &arr, int n, int m, int target){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] == target){
                return true;
            }
        }
    }
    return false;
}

//tc --> o(n + log base2 m)  sc --> o(1)
bool better(vector<vector<int>> &arr, int n, int m, int target){
    for(int i=0;i<n;i++){
        if(target > arr[i][m-1]){
            continue;
        }
        int low = 0;
        int high = m-1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(arr[i][mid] == target){
                return true;
            }
            else if(arr[i][mid] > target){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
    }
    return false;
}

//tc --> o(log base2 n*m) sc --> o(1)
bool optimal(vector<vector<int>> &arr, int n, int m, int target){
    int low = 0;
    int high = (n*m) - 1;
    while(low <= high){
        int mid = (low + high) / 2;
        int row = mid / m; // this is used to identify the row index in 2D matrix
        int col = mid % m; // this is used to identify the col index in 2D matrix
        if(arr[mid/m][mid%m] == target){     // if u want replace them by row n col
            return true;
        }
        else if(arr[mid/m][mid%m] > target){
            high = mid - 1;
        }
        else{
            low = mid + 1;
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
    cout<<optimal(arr, n, m,target)<<endl;
    return 0;
}