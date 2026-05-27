#include<bits/stdc++.h>
using namespace std;

//SC -> O(3N)
//TC -> O(n) + o(2e) ie total degrees
vector<int> bfs(int v, vector<int> adj[]){
    vector<int> visited(v,0);
    visited[0] = 1;
    queue<int> q;
    q.push(0);
    vector<int> ans;
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        ans.push_back(temp);
        
        for(auto it : adj[temp]){
            if(!visited[it]){
                q.push(it);
                visited[it] = 1;
            }
        }
    }
    return ans;
}

int main(){
    int n, m;
    cin>> n >> m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> ans = bfs(n , adj);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}