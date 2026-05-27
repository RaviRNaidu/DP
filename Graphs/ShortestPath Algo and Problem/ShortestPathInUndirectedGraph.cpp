#include<bits/stdc++.h>
using namespace std;

vector<int> solution(int n, int m, vector<vector<int>> &edges, int s){
    vector<int> adj[n];
    for(int i=0;i<m;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist(n + 1);
    for(int i=0;i<=n;i++){
        dist[i] = 1e9;
    }

    dist[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int node = q.front();

        for(auto it : adj[node]){
            if(dist[node] + 1 < dist[it]){
                dist[it] = dist[node] + 1;
                q.push(it);
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

    int s;
    cin >> s;

    vector<int> ans = solution(n, m , arr, s);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}