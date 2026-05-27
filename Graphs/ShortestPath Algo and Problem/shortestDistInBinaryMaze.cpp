#include<bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> &grid, pair<int,int> src, pair<int,int> des){
    int n = grid.size();
    int m = grid[0].size();
    int drow[] = {-1,0,1,0};
    int dcol[] = {0,1,0,-1};
    vector<vector<int>> dist(n, vector<int> (m,1e9));
    dist[src.first][src.second] = 0;
    queue<pair<int, pair<int,int>>> q;
    q.push({0,{src.first,src.second}});
    while(!q.empty()){
        auto it = q.front();
        int row = it.second.first;
        int col = it.second.second;
        int dis = it.first;
        q.pop();

        // if((des.first == row) && (des.second == col)){
        //     return dis;
        // }

        for(int i=0;i<4;i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m &&
             grid[nrow][ncol] && (dis + 1 < dist[nrow][ncol])){
                dist[nrow][ncol] = dis + 1;
                if((des.first == nrow) && (des.second == ncol)){
                    return dist[nrow][ncol];
                }
                q.push({dist[nrow][ncol], {nrow,ncol}});
             }
        }
    }
    return -1;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    int ans = solution(arr, {0,1}, {2,2});
    cout<<ans<<endl;
    return 0;
}