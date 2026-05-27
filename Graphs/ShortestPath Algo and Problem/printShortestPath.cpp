#include<bits/stdc++.h>
using namespace std;

//TC - > O(E log V) + o(v)
//SC -> O(v) + o(2v)
vector<int> solution(int v, vector<vector<int>> adj[], int s, int d){
    vector<int> dist(v,1e9);
    vector<int> src(v, -1);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[s] = 0;
    pq.push({s, 0});

    while(!pq.empty()){
        int node = pq.top().first;
        int dis = pq.top().second;
        pq.pop();
        
        for(auto it : adj[node]){
            int edgWt = it[1];
            int adjNode = it[0];
            if(dis + edgWt < dist[adjNode]){
                dist[adjNode] = dis + edgWt;
                src[adjNode] = node;
                pq.push({adjNode, dist[adjNode]});
            }
        }
    }
    vector<int> ans;
    if(dist[d] == 1e9) return {-1};
    ans.push_back(d);
    int node = d;
    while(node != s){
        ans.push_back(src[node]);
        node = src[node];
    }

    reverse(ans.begin(),ans.end());
    return ans;
}


vector<int> striver(int n, int m, vector<vector<int>> &edge){
    vector<pair<int,int>> adj[n + 1];
    for(auto it : edge){
        int u = it[0];
        int v = it[1];
        int w = it[2];
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<int> dist(n + 1,1e9);
    vector<int> src(n + 1);
    for(int i=1;i<=n;i++) src[i] = i;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[1] = 0;
    pq.push({0,1});

    while(!pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        for(auto it : adj[node]){
            int adjNode = it.first;
            int edgWt = it.second;
            if(dis + edgWt < dist[adjNode]){
                dist[adjNode] = dis + edgWt;
                src[adjNode] = node;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    vector<int> ans;
    if(dist[n] == 1e9) return {-1};
    ans.push_back(n);
    int node = n    ;
    while(node != 1){
        ans.push_back(src[node]);
        node = src[node];
    }

    reverse(ans.begin(),ans.end());
    return ans;
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
    int st, d;
    cin >> st >> d;

    vector<int> ans = solution(n , arr, st, d);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}