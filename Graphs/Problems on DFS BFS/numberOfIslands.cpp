#include<bits/stdc++.h>
using namespace std;

void bfs(int row, int col, vector<vector<int>> &visited, vector<vector<int>> &land){
    visited[row][col] = 1;
    queue<pair<int, int>> q;
    q.push({row,col});
    int n = land.size();
    int m = land[0].size();
    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        for(int rowDel=-1;rowDel<=1;rowDel++){
            for(int colDel=-1;colDel <= 1;colDel++){
                int newRow = i + rowDel;
                int newCol = j + colDel;
                
                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && land[newRow][newCol] == 1 && !visited[newRow][newCol]){
                    visited[newRow][newCol] = 1;
                    q.push({newRow,newCol});
                }
            }
        }
    }
}


void dfs(int row, int col, vector<vector<int>> &visited, vector<vector<int>> &land){
    visited[row][col] = 1;
    int n = land.size();
    int m = land[0].size();
    for(int rowDel = -1; rowDel <= 1; rowDel++){
        for(int colDel = -1;colDel <= 1; colDel++){
            int nRow = row + rowDel;
            int ncol = col + colDel;
            if(nRow >= 0 && nRow < n && ncol >= 0 && ncol < m && land[nRow][ncol] == 1 && !visited[nRow][ncol]){
                dfs(nRow,ncol,visited,land);
            }
        }
    }
}


//TC -> N*M * 9 for all neighbours
//SC -> N*M to store the grid + o(n*m) for queue 
int countingNumOfIslands(vector<vector<int>>&land, int n, int m){
    int ans = 0;
    vector<vector<int>> visited(n, vector<int> (m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(land[i][j] == 1 && !visited[i][j]){
                ans++;
                dfs(i,j,visited,land);
            }
        }
    }
    return ans;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> land(n,vector<int> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>land[i][j];
        }
    }

    int ans = countingNumOfIslands(land, n, m);
    cout<<ans<<endl;
    return 0;
}