#include<bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, vector<int> adj[], vector<int> &vis, int &timer, 
           vector<int> &tin, vector<int> &low, vector<vector<int>> & bridge){
    vis[node] = 1;
    tin[node] = timer;
    low[node] = timer;
    timer++;
    for(auto it : adj[node]){
        if(it == parent) continue;
        if(!vis[it]){
            dfs(it,node,adj,vis,timer,tin,low,bridge);
            low[node] = min(low[node], low[it]);
            if(low[it] > tin[node]){
                bridge.push_back({node, it});
            }
        }
        else{
            low[node] = min(low[node], tin[it]);
        }
    }
}

vector<vector<int>> bridges(int n, vector<vector<int>> &arr){
    vector<int> adj[n];
    for(auto it : arr){
        int u = it[0];
        int v = it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int timer = 1;
    vector<vector<int>> bridge;
    vector<int> vis(n,0);
    vector<int> tin(n);
    vector<int> low(n);

    dfs(0,-1,adj,vis,timer,tin,low,bridge);
    return bridge;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr;
    for(int i=0;i<m;i++){
        int u, v;
        cin >> u >> v;
        arr.push_back({u,v});
    }

    vector<vector<int>> ans = bridges(n , arr);
    for(auto it : ans){
        for(auto i : it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}