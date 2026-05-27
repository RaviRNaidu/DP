#include<bits/stdc++.h>
using namespace std;

bool bfss(int start, vector<int> arr[],vector<int> &visited){
    queue<pair<int,int>> q;
    q.push({start, -1});
    visited[start] = 1;
    while(!q.empty()){
        int indx = q.front().first;
        int parent = q.front().second;
        q.pop();
        for(auto it : arr[indx]){
            if(it != parent && visited[it]){
                return true;
            }
            else if(it != parent){
                visited[it] = 1;
                q.push({it,indx});
            }
        }
    }
    return false;
}


//STRIVER
//TC -> o(v) + o(n + 2e)
//SC -> o(n) + o(n) 
bool bfs(int start, vector<int> arr[],vector<int> &visited){
    queue<pair<int,int>> q;
    q.push({start, -1});
    visited[start] = 1;
    while(!q.empty()){
        int indx = q.front().first;
        int parent = q.front().second;
        q.pop();
        for(auto it : arr[indx]){
            if(!visited[it]){
                visited[it] = 1;
                q.push({it,indx});
            }
            else if(it != parent){
                return true;
            }
        }
    }
    return false;
}

bool detecting(int v, vector<int> arr[]){
    vector<int> visited(v+1,0);
    for(int i=1;i<=v;i++){
        if(!visited[i]){
            if(bfs(i,arr,visited)){
                return true;
            }
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