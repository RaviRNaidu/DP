#include<bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<int>> &arr, vector<vector<int>> &visited, vector<vector<int>> &index, int brow, int bcol){
    visited[row][col] = 1;
    index.push_back({row - brow, col - bcol});
    int n = arr.size();
    int m = arr[0].size();
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};

    for(int i=0;i<4;i++){
        int nrow = row + drow[i];
        int ncol = col + dcol[i];

        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol] && arr[nrow][ncol] == 1){
            dfs(nrow,ncol,arr,visited,index,brow,bcol);
        }
    }
}

//DONE BY ME
int solution(vector<vector<int>> &arr, int n, int m){
    vector<vector<int>> visited(n,vector<int> (m,0));
    set<vector<vector<int>>> st;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j] && arr[i][j] == 1){
                vector<vector<int>> index;
                dfs(i,j,arr,visited, index, i, j);
                st.insert(index);
            }
        }
    }
    return st.size();
}


void dfstriver(int row, int col, vector<vector<int>> &arr, vector<vector<int>> &visited, vector<pair<int,int>> &index, int brow, int bcol){
    visited[row][col] = 1;
    index.push_back({row - brow, col - bcol});
    int n = arr.size();
    int m = arr[0].size();
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};

    for(int i=0;i<4;i++){
        int nrow = row + drow[i];
        int ncol = col + dcol[i];

        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol] && arr[nrow][ncol] == 1){
            dfstriver(nrow,ncol,arr,visited,index,brow,bcol);
        }
    }
}



//TC -> O(N * M) + (N * M * 4)
//SC -> O(N * M) + O(N * M) + o(n * m)
int striver(vector<vector<int>> &arr, int n, int m){
    vector<vector<int>> visited(n,vector<int> (m,0));
    set<vector<pair<int,int>>> st;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j] && arr[i][j] == 1){
                vector<pair<int,int>> index;
                dfstriver(i,j,arr,visited, index, i, j);
                st.insert(index);
            }
        }
    }
    return st.size();
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