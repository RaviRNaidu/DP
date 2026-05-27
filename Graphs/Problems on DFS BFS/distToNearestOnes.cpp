#include<bits/stdc++.h>
using namespace std;

//TC -> O(N * M) + O(N * M * 4)
//SC -> O(N * M) + O(N * M)
vector<vector<int>> distance(vector<vector<int>> &arr, int n, int m){
    vector<vector<int>> ans(n,vector<int> (m, 0));
    queue<pair<int,pair<int, int>>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] == 1){
                ans[i][j] = 0;
                q.push({0,{i,j}});
            }
        }
    }

    int drow[] = {-1, 0 , 1, 0};
    int dcol[] = {0, 1, 0, -1};
    while(!q.empty()){
        int row = q.front().second.first;
        int col = q.front().second.second;
        int dist = q.front().first;
        q.pop();

        for(int i=0;i<4;i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && arr[nrow][ncol] == 0 && ans[nrow][ncol] == 0){
                ans[nrow][ncol] = dist + 1;
                q.push({dist+1,{nrow,ncol}});
            }
        }
    }
    return ans;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n,vector<int> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }

    vector<vector<int>> ans = distance(mat, n, m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}