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

int solution(int n, vector<vector<int>> adj[]){
    vector<pair<int,pair<int,int>>> arr(n);
    for(int i=0;i<n;i++){
        for(auto it : adj[i]){
            int adjNode = it[0];
            int wt = it[1];
            int node = i;

            arr.push_back({wt,{node, adjNode}});
        }
    }

    sort(arr.begin(),arr.end());
    disjointSet ds(n);
    int sum = 0;
    for(int i=0;i<arr.size();i++){
        int wt = arr[i].first;
        int u = arr[i].second.first;
        int v = arr[i].second.second;
        if(ds.findUPar(u) != ds.findUPar(v)){
            sum += wt;
            ds.unionBySize(u, v);
        }
    }
    return sum;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr[n];
    for(int i=0;i<m;i++){
        int u, v, w;
        cin >> u >> v >> w;
        arr[u].push_back({v,w});
        arr[v].push_back({u,w});
    }

    int ans = solution(n , arr);
    cout<<ans<<endl;
    return 0;
}