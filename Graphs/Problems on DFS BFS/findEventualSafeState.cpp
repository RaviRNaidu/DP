#include<bits/stdc++.h>
using namespace std;

//TC -> O(2N) + O(V + E)
//SC -> O(3N) + O(N)R
bool dfs(int node, vector<int> &vis, vector<int> &pathVis, vector<int> &safeNode, vector<int> arr[]){
    vis[node] = 1;
    pathVis[node] = 1;
    safeNode[node] = 0;
    
    for(auto it : arr[node]){
        if(!vis[it]){
            if(dfs(it,vis,pathVis,safeNode,arr) == true){
                safeNode[node] = 0;
                return true;
            }
        }
        else if(pathVis[it]){
            safeNode[node] = 0;
            return true;
        }
    }

    safeNode[node] = 1;
    pathVis[node] = 0;
    return false;
}

vector<int> solution(int v, vector<int> arr[]){
    vector<int> vis(v,0);
    vector<int> pathVis(v, 0);
    vector<int> safeNode(v,0);
    vector<int> ans;
    for(int i=0;i<v;i++){
        if(!vis[i]){
            dfs(i,vis,pathVis,safeNode,arr);
        }
    }

    for(int i=0;i<v;i++){
        if(safeNode[i] == 1){
            ans.push_back(i);
        }
    }
    return ans;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> arr[n];
    for(int i=0;i<m;i++){
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v);
    }

    vector<int> ans = solution(n , arr);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}