#include<bits/stdc++.h>
using namespace std;

bool solution(int n, vector<pair<int, int>> &arr){
    vector<int> adj[n];
    for(int i=0;i<arr.size();i++){
        int u = arr[i].first;
        int v = arr[i].second;

        adj[u].push_back(v);
    }

    vector<int> inDegree(n,0);
    for(int i=0;i<n;i++){
        for(auto it : adj[i]){
            inDegree[it]++;
        }
    }

    queue<int> q;
    for(int i=0;i<n;i++){
        if(inDegree[i] == 0){
            q.push(i);
        }
    }

    int cnt = 0;
    while(!q.size()){
        int node = q.front();
        q.pop();
        cnt++;
        for(auto it : adj[node]){
            inDegree[it]--;
            if(inDegree[it] == 0) q.push(it);
        }
    }

    if(cnt == n) return true;
    return false;
}

int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<pair<int,int>> arr(m);
    for(int i=0;i<m;i++){
        int u, v;
        cin>> u >> v;
        arr.push_back({u,v});
    }

    bool ans = solution(n, arr);
    cout<<ans<<endl;
    return 0;
}