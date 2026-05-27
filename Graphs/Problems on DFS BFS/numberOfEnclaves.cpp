#include<bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<int>> &arr, vector<vector<int>> &visit){
    visit[row][col] = 1;
    int n = arr.size();
    int m = arr[0].size();
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};

    for(int i=0;i<4;i++){
        int nrow = row + drow[i];
        int ncol = col + dcol[i];

        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visit[nrow][ncol] && arr[nrow][ncol] == 1){
            dfs(nrow,ncol,arr,visit);
        }
    }
}

void bfs(int row, int col, vector<vector<int>> &arr, vector<vector<int>> &visit){
    visit[row][col] = 1;
    int n = arr.size();
    int m = arr[0].size();
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};

    queue<pair<int,int>> q;
    q.push({row, col});
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nrow = r + drow[i];
            int ncol = c + dcol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visit[nrow][ncol] && arr[nrow][ncol] == 1){
                q.push({nrow,ncol});
                visit[nrow][ncol] = 1;
            }
        }
    }
}

//TC -> O(N) + O(M) + O(N*M*4) + O(N*M)
//SC -> O(N* M) + O(N * M)
int solution(vector<vector<int>> &arr, int n, int m){
    vector<vector<int>> visit(n, vector<int> (m, 0));
    for(int i=0;i<n;i++){
        if(arr[i][0] == 1 && !visit[i][0]){
            bfs(i,0,arr,visit);
        }

        if(arr[i][m-1] == 1 && !visit[i][m-1]){
            bfs(i,m-1,arr,visit);
        }
    }

    for(int j=0;j<m;j++){
        if(arr[0][j] == 1 && !visit[0][j]){
            bfs(0,j,arr,visit);
        }

        if(arr[n-1][j] == 1 && !visit[n-1][j]){
            bfs(n-1,j,arr,visit);
        }
    }

    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] == 1 && visit[i][j] == 0){
                ans += 1;
            }
        }
    }

    return ans;
}

int striver(vector<vector<int>> &arr, int n, int m){
    vector<vector<int>> visit(n, vector<int> (m, 0));
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++){
        if(arr[i][0] == 1 && !visit[i][0]){
            q.push({i, 0});
            visit[i][0] = 1;
        }

        if(arr[i][m-1] == 1 && !visit[i][m-1]){
            q.push({i, m-1});
            visit[i][m-1] = 1;
        }
    }

    for(int j=0;j<m;j++){
        if(arr[0][j] == 1 && !visit[0][j]){
            q.push({0, j});
            visit[0][j] = 1;
        }

        if(arr[n-1][j] == 1 && !visit[n-1][j]){
            q.push({n-1, j});
            visit[n-1][j] = 1;
        }
    }

    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};

    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nrow = r + drow[i];
            int ncol = c + dcol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visit[nrow][ncol] && arr[nrow][ncol] == 1){
                q.push({nrow,ncol});
                visit[nrow][ncol] = 1;
            }
        }
    }

    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] == 1 && visit[i][j] == 0){
                ans += 1;
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

    int ans = solution(mat, n, m);
    cout<<ans<<endl;
    return 0;
}