#include<bits/stdc++.h>
using namespace std;

class disjointSet{
    //o(2n)
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

int solution(int n, vector<vector<int>> &arr){
    disjointSet ds(n);
    int ans = 0;
    //o(n^2)
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j] == 1){
                ds.unionBySize(i, j);
            }
        }
    }

    //o(v)
    for(int i=0;i<n;i++){
        if(ds.findUPar(i) == i){
            ans++;
        }
    }

    return ans;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int> (n, 0));
    for(int i=0;i<m;i++){
        int u, v;
        cin >> u >> v;
        arr[u][v] = 1;
        arr[v][u] = 1;
    }

    int ans = solution(n , arr);
    cout<<ans<<endl;
    return 0;
}