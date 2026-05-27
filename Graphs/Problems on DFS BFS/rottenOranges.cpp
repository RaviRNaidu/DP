#include<bits/stdc++.h>
using namespace std;

int timeTaken(vector<vector<int>> &grid, int n, int m){
    queue<pair<int,pair<int, int>>> q;
    int delRow[] = {-1, 0, +1, 0};
    int delCol[] = {0, +1, 0, -1};
    int ans = 0;
    vector<vector<int>> visited(n,vector<int> (m,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j] == 2){
                q.push({0,{i,j}});
                visited[i][j] = 2;
            }
        }
    }

    while(!q.empty()){
        int time = q.front().first;
        ans = max(ans, time);
        int row = q.front().second.first;
        int col = q.front().second.second;
        q.pop();

        for(int i=0;i<4;i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && nrow < m && grid[nrow][ncol] == 1 && visited[nrow][ncol] != 2){
                visited[nrow][ncol] = 2;
                q.push({time + 1, {nrow,ncol}});
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 1 && visited[i][j] != 2){
                return -1;
            }
        }
    }
    return ans;
}

//TC -> O(N*M) + O(N * M * 4)
//SC -> O(N *M) + (N * M)
int timeTakenOptima(vector<vector<int>> &grid, int n, int m){
    queue<pair<int,pair<int, int>>> q;
    int delRow[] = {-1, 0, +1, 0};
    int delCol[] = {0, +1, 0, -1};
    int ans = 0;
    int freshOrange = 0;
    vector<vector<int>> visited(n,vector<int> (m,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j] == 2){
                q.push({0,{i,j}});
                visited[i][j] = 2;
            }
            if(grid[i][j] == 1){
                freshOrange++;
            }
        }
    }

    int rotten = 0;
    while(!q.empty()){
        int time = q.front().first;
        ans = max(ans, time);
        int row = q.front().second.first;
        int col = q.front().second.second;
        q.pop();

        for(int i=0;i<4;i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && nrow < m && grid[nrow][ncol] == 1 && visited[nrow][ncol] != 2){
                visited[nrow][ncol] = 2;
                q.push({time + 1, {nrow,ncol}});
                rotten++;
            }
        }
    }

    if(freshOrange != rotten) return -1;
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
    int ans = timeTaken(land, n, m);
    cout<<ans<<endl;
    return 0;
}