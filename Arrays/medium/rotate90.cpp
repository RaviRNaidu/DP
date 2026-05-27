#include<bits/stdc++.h>
using namespace std;

//TC --> O(N^2) SC --> 0(N^2) 
vector<vector<int>> brute(vector<vector<int>> &arr, int n, int m){
    vector<vector<int>> ans(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans[j][n-1-i] = arr[i][j];
        }
    }
    return ans;
}

//optimal  
vector<vector<int>> optimall(vector<vector<int>> &arr, int n, int m){
    //TC --> O(n / 2 * n / 2)
    for(int i=0;i<=n-2;i++){
        for(int j=i+1;j<=n-1;j++){
            swap(arr[i][j],arr[j][i]);
        }
    }

    //reverse
    //o(n * n / 2)
    for(int i=0;i<n;i++){
        reverse(arr[i].begin(),arr[i].end());
    }
    return arr;

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
    vector<vector<int>> ans = optimall(arr, n, m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}