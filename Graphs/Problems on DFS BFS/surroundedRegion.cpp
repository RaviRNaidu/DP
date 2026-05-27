#include<bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<char>> &arr, vector<vector<int>> &visit){
    int n = arr.size();
    int m = arr[0].size();
    visit[row][col] = 1;
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};

    for(int i=0;i<4;i++){
        int nrow = row + drow[i];
        int ncol = col + dcol[i];

        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && arr[nrow][ncol] == 'o' && !visit[nrow][ncol]){
            dfs(nrow,ncol,arr,visit);
        }
    }
}


//TC -> O(N) + O(N) + O(N*M) + O(n*m*4)
//SC -> O(N*M) visited array + O(N*M) recurssion
vector<vector<char>> solution(vector<vector<char>> &arr, int n, int m){
    vector<vector<int>> visit(n,vector<int> (m,0));
    for(int i=0;i<n;i++){
        if(arr[i][0] == 'o' && !visit[i][0]){
            dfs(i,0,arr,visit);
        }
        if(arr[i][m-1] == 'o' && !visit[i][m-1]){
            dfs(i,m-1,arr,visit);
        }
    }

    for(int j=0;j<m;j++){
        if(arr[0][j] == 'o' && !visit[0][j]){
            dfs(0,j,arr,visit);
        }
        if(arr[n-1][j] == 'o' && !visit[n-1][j]){
            dfs(n-1,j,arr,visit);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] == 'o' && visit[i][j] != 1){
                arr[i][j] = 'x';
            }
        }
    }
    return arr;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<char>> mat(n,vector<char> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }

    vector<vector<char>> ans = solution(mat, n, m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}