#include<bits/stdc++.h>
using namespace std;

vector<int> solution(int v, vector<vector<int>> adj[], int st){
    priority_queue<pair<int,int>> pq;
    vector<int> dis(v);
    for(int i=0;i<v;i++) dis[i] = 1e9;
    dis[st] = 0;
    pq.push({st,0});

    while(!pq.empty()){
        int node = pq.top().first;
        int wt = pq.top().second;
        pq.pop();

        for(auto it : adj[node]){
            int nNode = it[0];
            int nWt = it[1];
            if(wt + nWt < dis[nNode]){
                dis[nNode] = wt + nWt;
                pq.push({nNode, dis[nNode]});
            }
        }
    }
    return dis;
}


//TC -> E LOG V 
//E IS TOTAL NUM OF EDGES 
// V IS THE NUMBER OF NODES
vector<int> striver(int v, vector<vector<int>> adj[], int st){
    priority_queue<pair<int,int>,vector<pair<int,int>> , greater<pair<int,int>>> pq;
    vector<int> dis(v);
    for(int i=0;i<v;i++) dis[i] = 1e9;
    dis[st] = 0;
    pq.push({st,0});

    while(!pq.empty()){
        int node = pq.top().first;
        int wt = pq.top().second;
        pq.pop();

        for(auto it : adj[node]){
            int nNode = it[0];
            int nWt = it[1];
            if(wt + nWt < dis[nNode]){
                dis[nNode] = wt + nWt;
                pq.push({nNode, dis[nNode]});
            }
        }
    }
    return dis;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr[n];
    for(int i=0;i<m;i++){
        int u, v, w;
        cin >> u >> v >> w;
        arr[u].push_back({v,w});
        arr[v].push_back({u,w});
    }
    int st;
    cin >> st;

    vector<int> ans = solution(n , arr, st);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}