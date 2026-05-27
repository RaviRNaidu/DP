#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int> &vis, stack<int> &st){
    vis[node] = 1;
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it, adj, vis, st);
        }
    }
    st.push(node);
}

void dfs3(int node, vector<int> adjT[], vector<int> &vis){
    vis[node] = 1;
    for(auto it : adjT[node]){
        if(!vis[it]){
            dfs3(it, adjT, vis);
        }
    }
}


//TC -> O(3 * (V + E))
//SC -> O(2V + E + V)
int kosaraju(int v, vector<int> adj[]){
    //step 1
    //TC -> O(V + E), SC -> O(2V)
    vector<int> vis(v,0);
    stack<int> st;
    for(int i=0;i<v;i++){
        if(!vis[i]){
            dfs(i,adj,vis,st);
        }
    }

    //step 2
    //reverse the graph
    //TC -> V + E, SC -> O(V + E)
    vector<int> adjT[v];
    for(int i=0;i<v;i++){
        //to reuse
        vis[i] = 0;
        for(auto it : adj[i]){
            //i -> it
            //it -> i
            adjT[it].push_back(i);
        }
    }

    //step 3
    //TC -> O(V + E)
    int scc = 0;
    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(!vis[node]){
            scc++;
            dfs3(node, adjT, vis);
        }
    }

    return scc;
}

int main(){
    int n, m;
    cin>> n >> m;
    vector<int> adj[n];
    for(int i=0;i<m;i++){
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    int ans = kosaraju(n, adj);
    cout<<ans<<endl;
    // vector<int> ans = kosaraju(n , adj);
    // for(int i=0;i<ans.size();i++){
    //     cout<<ans[i]<<" ";
    // }
    return 0;
}