#include<bits/stdc++.h>
using namespace std;

class disjointSet{

    public:
    vector<int> parent, size;
    bool checkVailidity(int nrow, int ncol, int n, int m){
        return nrow >= 0 && nrow < n && ncol >= 0 && ncol < m;
    }
    disjointSet(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }

    int findUPar(int node){
        if(parent[node] == node){
            return node;
        }

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v){
        int up_u = findUPar(u);
        int up_v = findUPar(v);
        if(up_u == up_v) return;
        if(size[up_u] < size[up_v]){
            parent[up_u] = up_v;
            size[up_v] += size[up_u];
        }
        else{
            parent[up_v] = up_u;
            size[up_u] += size[up_v];
        }
    }
};


int maxConnection(int n, int m, vector<vector<int>> &grid){
    int ans = 0;
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};
    disjointSet ds(n*m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 0) continue; 
            int nodeVal = ((i * m) + j);
            for(int k=0;k<4;k++){
                int nrow = i + drow[k];
                int ncol = j + dcol[k];

                if(ds.checkVailidity(nrow, ncol, n, m)){
                    if(grid[nrow][ncol] == 1){
                        int nodeNo = ((nrow * m) + ncol);
                        ds.unionBySize(nodeVal, nodeNo);
                    }
                }
            }
        }
    }
    //step 2
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 1) continue; 
            set<int> st;
            for(int k=0;k<4;k++){
                int nrow = i + drow[k];
                int ncol = j + dcol[k];

                if(ds.checkVailidity(nrow, ncol, n, m)){
                    if(grid[nrow][ncol] == 1){
                        int nodeNo = ((nrow * m) + ncol);
                        st.insert(ds.findUPar(nodeNo));
                    }
                }
            }
            int sum = 1;
            for(auto it : st){
                sum += ds.size[it];
            }
            ans = max(ans, sum);
        }
    }
    for(int i=0;i<n*m;i++){
        ans = max(ans,ds.size[ds.findUPar(i)]);
    }
    return ans;
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> arr(n, vector<int> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    int ans = maxConnection(n, m ,arr);
    cout<<ans<<endl;
    return 0;
}