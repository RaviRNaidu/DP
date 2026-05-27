#include<bits/stdc++.h>
using namespace std;

void bfs(int node, vector<int> &visited, vector<int> arr[]){
    queue<int> q;
    visited[node] = 1;
    q.push(node);
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        for(auto it : arr[temp]){
            if(!visited[it]){
                visited[it] = 1;
                q.push(it);
            }
        }
    }
}

void dfs(int node, vector<int> &visited, vector<int> arr[]){
    visited[node] = 1;
    for(auto it : arr[node]){
        if(!visited[it]){
            dfs(it,visited, arr);
        }
    }
}

//TC -> O(N) + O(V + 2E)
//SC -> O(2N)
int noOfProvinces(int v, vector<int> arr[]){
    vector<int> visited(v, 0);
    int ans = 0;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            ans++;
            bfs(i, visited, arr);
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
    int ans = noOfProvinces(n , adj);
    cout<<ans<<endl;
    return 0;
}