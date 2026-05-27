#include<bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, vector<int> &vis, int tin[], int low[], vector<int> adj[], vector<int> &articulate, int &timer){
    vis[node] = 1;
    tin[node] = low[node] = timer;
    timer++;
    int cnt = 0;
    for(auto it : adj[node]){
        if(it == parent) continue;
        if(!vis[it]){
            dfs(it, node, vis, tin, low, adj, articulate, timer);
            low[node] = min(low[node], low[it]);
            if(low[it] >= tin[node] && parent != -1){
                articulate[node] = 1;
            }
            cnt++;
        }
        else{
            low[node] = min(low[node], tin[it]);
        }
    }
    if(cnt > 1 && parent == -1) articulate[node] = 1;
}

vector<int> articulation(int n, vector<vector<int>> &arr){
    vector<int> adj[n];
    for(auto it : arr){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    vector<int> vis(n,0);
    int tin[n];
    int low[n];
    vector<int> mark(n,0);
    int timer = 1;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,-1,vis,tin,low,adj,mark, timer);
        }
    }
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(mark[i]){
            ans.push_back(i);
        }
    }
    if(ans.size() == 0){
        return {-1};
    }
    return ans;
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

    vector<int> ans = articulation(n , arr);
    for(auto it : ans){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}