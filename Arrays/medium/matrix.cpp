#include<bits/stdc++.h>
using namespace std;

vector<int> linear(vector<vector<int>> &arr, int n, int m, int key){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] == key){
                return {i,j};
            }
        }
    }
    return {-1,-1};
}

int maxxx(vector<vector<int>> &arr, int n, int m){
    int maxi = INT_MIN;
    for(int j=0;j<n;j++){
        int sum = 0;
        for(int i=0;i<m;i++){
            sum += arr[i][j] ;
        }
        maxi = max(maxi, sum);
    }
    return maxi;
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
    int ans = maxxx(arr, n, m);
    cout<<ans<<endl;
    return 0;
}


// int main(){
//     int n,m;
//     cin>>n;
//     cin>>m;
//     vector<vector<int>> arr(n,vector<int>(m)); 
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cin>>arr[i][j];
//         }
//     }
//     int key;
//     cin>>key;
//     vector<int> ans = linear(arr, n, m, key);
//     for(int i=0;i<ans.size();i++){
//         cout<<ans[i]<<" ";
//     }
//     return 0;
// }