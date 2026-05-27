#include<bits/stdc++.h>
using namespace std;

class disjointSet{
    vector<int> parent, size;

    public:
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


//TC -> O(K * 4)
//SC -> O(N * M) + O(K) + O(2*N*M)
vector<int> numOfIsland(int n, int m, vector<vector<int>> &operations){
    disjointSet ds(n*m);
    vector<vector<int>> island(n, vector<int> (m,0));
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};
    vector<int> islandzz;
    int sum = 0;
    for(int i=0;i<operations.size();i++){
        int row = operations[i][0];
        int col = operations[i][1];
        if(island[row][col] == 1){
            islandzz.push_back(sum);
            continue;
        }
        island[row][col] = 1;
        sum++;
        int nodeval = ((row * m) + col);
        for(int j=0;j<4;j++){
            int nrow = row + drow[j];
            int ncol = col + dcol[j];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && island[nrow][ncol] == 1){
                int nodeNum = ((nrow * m) + ncol);
                if(ds.findUPar(nodeval) != ds.findUPar(nodeNum)){
                    sum--;
                    ds.unionBySize(nodeNum, nodeval);
                }
            }
        }
        islandzz.push_back(sum);
    }
    return islandzz;
}

int main(){
    int n, m, k;
    cin>>n>>m>>k;
    vector<vector<int>> arr(k, vector<int> (2));
    for(int i=0;i<k;i++){
        cin>>arr[i][0];
        cin>>arr[i][1];
    }

    vector<int> ans = numOfIsland(n, m, arr);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}