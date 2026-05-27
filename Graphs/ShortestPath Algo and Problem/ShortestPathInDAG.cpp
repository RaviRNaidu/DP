#include<bits/stdc++.h>
using namespace std;

//TC -> o(n + m) + o(n + m)
//sc -> o(4n + )
void dfs(int node, vector<pair<int,int>> adj[], vector<int> &vis, stack<int> &st){
    vis[node] = 1;
    for(auto it : adj[node]){
        if(!vis[it.first]){
            dfs(it.first, adj, vis, st);
        }
    }
    st.push(node);
}

vector<int> solution(int n, int m, vector<vector<int>> &edges){
    vector<pair<int, int>> adj[n];
    for(int i=0;i<m;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        adj[u].push_back({v,w});
    }

    stack<int> st;
    vector<int> vis(n,0);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i, adj, vis, st);
        }
    }

    vector<int> dist(n);
    for(int i=0;i<n;i++) dist[i] = 1e9;
    dist[0] = 0;
    while(!st.empty()){
        int node = st.top();
        st.pop();

        for(auto it : adj[node]){
            int v = it.first;
            int wt = it.second;
            if(dist[v] > (wt + dist[node])){
                dist[v] = wt + dist[node];
            }
        }
    }
    return dist;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(m);
    for(int i=0;i<m;i++){
        int u, v, w;
        cin >> u >> v >> w;
        arr[i].push_back(u);
        arr[i].push_back(v);
        arr[i].push_back(w);
    }

    vector<int> ans = solution(n, m , arr);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}