#include<bits/stdc++.h>
using namespace std;

void traversal(int node, vector<int> &ans, vector<int> &visited, vector<int> arr[]){
    visited[node] = 1;
    ans.push_back(node);
    for(auto it : arr[node]){
        if(!visited[it]){
            traversal(it,ans, visited, arr);
        }
    }
}

// DONE BY ME
vector<int> dfs(int v, vector<int> arr[]){
    vector<int> ans;
    vector<int> visited(v,0);
    visited[0] = 1;
    ans.push_back(0);
    for(auto it : arr[0]){
        if(!visited[it]){
            traversal(it, ans, visited, arr);
        }
    }
    return ans;
}


//STRIVER
//TC -> O(3N) inlcuding recursive stack space
//SC -> O(n) + O(2E)
class solution{
    private:
    void traversal(int node, vector<int> &ans, vector<int> &visited, vector<int> arr[]){
        visited[node] = 1;
        ans.push_back(node);
        for(auto it : arr[node]){
            if(!visited[it]){
                traversal(it,ans, visited, arr);
            }
        }
    }

    public:
    vector<int> dfs(int v, vector<int> arr[]){
        vector<int> ans;
        vector<int> visited(v,0);
        int start = 0;
        traversal(start, ans, visited, arr);
        return ans;
    }
};

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
    vector<int> ans = dfs(n , adj);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}