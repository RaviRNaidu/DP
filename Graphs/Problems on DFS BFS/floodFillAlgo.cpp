#include<bits/stdc++.h>
using namespace std;

//DONE BY ME
void bfs(vector<vector<int>> &land, int iniRow, int iniCol,  vector<vector<int>> &visited, int iniColour, int newCol){
    visited[iniRow][iniCol] = 1;
    land[iniRow][iniCol] = newCol;
    queue<pair<int, int>> q;
    q.push({iniRow,iniCol});
    int n = land.size();
    int m = land[0].size();
    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        land[i][j] = newCol;

        for(int delRow = -1;delRow <= 1;delRow++){
            int nRow = i + delRow;
            if(nRow >= 0 && nRow < n && land[nRow][j] == iniColour && !visited[nRow][j]){
                visited[nRow][j] = 1;
                q.push({nRow,j});
            }
        }

        for(int delCol = -1;delCol <= 1;delCol++){
            int nCol = j + delCol;
            if(nCol >= 0 && nCol < m && land[i][nCol] == iniColour && !visited[i][nCol]){
                visited[i][nCol] = 1;
                q.push({i,nCol});
            }
        }
    }
}

//DONE BY ME
void dfs(vector<vector<int>> &land, int row, int col,  vector<vector<int>> &visited, int iniColour, int newCol){
    visited[row][col] = 1;
    land[row][col] = newCol;
    int n = land.size();
    int m = land[0].size();
    for(int rowDel = -1; rowDel <= 1; rowDel++){
        int nRow = row + rowDel;
        if(nRow >= 0 && nRow < n && land[nRow][col] == iniColour && !visited[nRow][col]){
            dfs(land, nRow, col,visited,iniColour,newCol);
        }
    }

    for(int colDel = -1;colDel <= 1; colDel++){
        int ncol = col + colDel;
        if(ncol >= 0 && ncol < m && land[row][ncol] == iniColour && !visited[row][ncol]){
            dfs(land, row, ncol ,visited,iniColour,newCol);
        }
    }
}


void striverDfs(int row, int col, vector<vector<int>> &image, vector<vector<int>> &ans, 
    int newCol, int iniColour, int delRow[], int delCol[]){
    ans[row][col] = newCol;
    int n = image.size();
    int m = image[0].size();
    //traversal
    for(int i=0;i<4;i++){
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];

        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == iniColour && ans[nrow][ncol] != newCol){
            striverDfs(nrow,ncol,image,ans,newCol,iniColour,delRow,delCol);
        }
    }
}

//TC -> N*M * 9 for all neighbours
//SC -> N*M to store the grid + o(n*m) for queue 
vector<vector<int>> floodFill(vector<vector<int>>&image, int n, int m, int sr, int sc, int newCol){
    vector<vector<int>> ans = image;
    int iniColour = image[sr][sc];
    int delRow[] = {-1 ,0, +1, 0};
    int delCol[] = {0, +1, 0, -1};
    striverDfs(sr, sc, image, ans, newCol, iniColour, delRow, delCol);
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

    vector<vector<int>> ans = floodFill(land, n, m, 2, 0, 3);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}