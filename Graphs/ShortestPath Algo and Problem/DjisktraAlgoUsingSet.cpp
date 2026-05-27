#include<bits/stdc++.h>
using namespace std;

vector<int> solution(int v, vector<vector<int>> adj[], int source){
    set<pair<int, int>> st;
    vector<int> dist(v);
    for(int i=0;i<v;i++) dist[i] = 1e9;

    dist[source] = 0;
    st.insert({0,source});
    
    while(!st.empty()){
        auto it = *(st.begin());
        int node = it.second;
        int wt = it.first;
        st.erase(it);

        for(auto it : adj[node]){
            int adjNode = it[0];
            int dis = it[1];
            if(wt + dis < dist[adjNode]){
                if(dist[adjNode] != 1e9){
                    st.erase({dist[adjNode], adjNode});
                }

                dist[adjNode] = wt + dis;
                st.insert({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
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