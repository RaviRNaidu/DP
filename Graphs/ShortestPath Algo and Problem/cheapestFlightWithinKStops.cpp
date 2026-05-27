#include<bits/stdc++.h>
using namespace std;


//SC -> O(n) + o(n) + graph
//TC -> o(e) because we are not using priorty queue
int solution(vector<vector<int>> &flights, int n, int s, int d, int k){
    vector<pair<int,int>> adj[n];
    for(int i=0;i<n;i++){
        auto it = flights[i];
        adj[it[0]].push_back({it[1],it[2]});
    }

    vector<int> dis(n,1e9);
    dis[s] = 0;
    queue<pair<int,pair<int,int>>> q;
    // stops, {cost, node}
    q.push({0,{0,s}});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int stops = it.first;
        int cost = it.second.first;
        int node = it.second.second;

        if(stops > k) continue;

        for(auto i : adj[node]){
            int adjNode = i.first;
            int expence = i.second;
            if(expence + cost < dis[adjNode] && stops <= k){
                dis[adjNode] = expence + cost;
                q.push({stops + 1, {dis[adjNode],adjNode}});
            }
        }
    }

    if(dis[d] == 1e9) return -1;
    return dis[d];
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int> (3));
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>arr[i][j];
        }
    }
    int src, des, k;
    cin >> src >> des >> k;
    int ans = solution(arr, n, src, des, k);
    cout<<ans<<endl;
    return 0;
}