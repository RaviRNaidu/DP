#include<bits/stdc++.h>
using namespace std;

//TC -> O(N) + O(N + E) cuz directed
//SC -> O(N) + O(2N)
bool dfs(int start, vector<int> arr[], vector<int> &visited, vector<int> &pathVis){
    visited[start] = 1;
    pathVis[start] = 1;

    for(auto it : arr[start]){
        if(!visited[it]){
            if(dfs(it,arr,visited,pathVis) == true){
                return true;
            }
        }
        else if(pathVis[it]){
            return true;
        }
    }
    pathVis[start] = 0; 
    return false;
}

bool solution(int v, vector<int> arr[]){
    vector<int> visited(v + 1, 0);
    vector<int> pathVis(v + 1, 0);

    for(int i=1;i<=v;i++){
        if(!visited[i]){
            if(dfs(i,arr,visited,pathVis) == true){
                return true;
            }
        }
    }
    return false;
}

//TC -> O(N) + O(N + E) cuz directed
//SC -> O(N) + O(N)
bool dfs1(int start, vector<int> arr[], vector<int> &visited){
    visited[start] = 2;

    for(auto it : arr[start]){
        if(!visited[it]){
            if(dfs1(it,arr,visited) == true){
                return true;
            }
        }
        else if(visited[it] == 2){
            return true;
        }
    }
    visited[start] = 1; 
    return false;
}

bool solution1(int v, vector<int> arr[]){
    vector<int> visited(v + 1, 0);

    for(int i=1;i<=v;i++){
        if(!visited[i]){
            if(dfs1(i,arr,visited) == true){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> arr[n+1];
    for(int i=0;i<m;i++){
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v);
    }

    bool ans = solution1(n , arr);
    if(ans) cout<<"1"<<endl;
    else cout<<"0"<<endl;
    return 0;
}