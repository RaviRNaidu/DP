#include<bits/stdc++.h>
using namespace std;

//TC -> O(E + LOG V)
//SC -> O(N + N + N) + GRAPH
int solution(vector<vector<int>> &arr, int n){
    vector<pair<int,int>> adj[n];
    for(auto it : arr){
        adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});
    }
    vector<int> dis(n,1e9);
    vector<int> path(n,0);
    dis[0] = 0;
    path[0] = 1;
    int mod = (int)(1e9 + 7);
    priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> q;
    // dist, node
    q.push({0,0});
    while(!q.empty()){
        int time = q.top().first;
        int node = q.top().second;
        q.pop();

        for(auto it : adj[node]){
            int adjNode = it.first;
            int adjW = it.second;

            if(time + adjW < dis[adjNode]){
                dis[adjNode] = time + adjW;
                q.push({dis[adjNode], adjNode});
                path[adjNode] = path[node];
            }
            else if(time + adjW == dis[adjNode]){
                path[adjNode] = (path[adjNode] + path[node]) % mod;
            }
        }
    }
    
    return dis[n - 1] % mod;
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
    int ans = solution(arr, n);
    cout<<ans<<endl;
    return 0;
}