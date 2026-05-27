#include<bits/stdc++.h>
using namespace std;

//SC -> O(N) + o(N)
//TC -> o(n) + O(N + 2E)
bool dfs(int node, int parent, vector<int> arr[], vector<int> &visited){
    visited[node] = 1;
    for(auto it : arr[node]){
        if(!visited[it]){
            if(dfs(it,node,arr,visited)) return true;
        }
        else if(it != parent){
            return true;
        }
    }
    return false;
}

bool detecting(int v, vector<int> arr[]){
    vector<int> visited(v+1,0);
    for(int i=1;i<=v;i++){
        if(!visited[i]){
            if(dfs(i,-1,arr,visited) == true) return true;
        }
    }
    return false;
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
    bool ans = detecting(n , adj);
    if(ans) cout<<"1"<<endl;
    else cout<<"0"<<endl;
    return 0;
}