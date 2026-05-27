#include<bits/stdc++.h>
using namespace std;


//TC -> O(N) + O(N + 2E)
//SC -> O(N) + O(N)
bool checkDFS(int node, int col, vector<int> arr[], vector<int> &color){
    color[node] = col;

    for(auto it : arr[node]){
        if(color[it] == -1){
            if(checkDFS(it,!color[node],arr,color) == false){
                return false;
            }
        }
        else if(color[node] == color[it]){
            return false;
        }
    }
    return true;
}


bool bipertiteOrNot(int v, vector<int> arr[]){
    vector<int> vis(v + 1,-1);

    for(int i=0;i<v;i++){
        if(vis[i] == -1){
            if(checkDFS(i,0,arr,vis) == false){
                return false;
            }
        }
    }

    return true;
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
    bool ans = bipertiteOrNot(n , adj);
    if(ans) cout<<"1"<<endl;
    else cout<<"0"<<endl;
    return 0;
}