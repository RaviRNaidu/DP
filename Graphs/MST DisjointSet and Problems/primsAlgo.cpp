#include<bits/stdc++.h>
using namespace std;

//TC -> O(E log E) + (E log E)
//SC -> O(E + N)
vector<vector<int>> solution(int v, vector<vector<int>> adj[]){
    vector<vector<int>> MST;
    int sum = 0;
    priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    vector<int> vis(v,0);
    pq.push({0,{0,-1}});
    // E
    while(!pq.empty()){
        // log E (for popping from the queue)
        auto it = pq.top();
        pq.pop();
        int wt = it.first;
        int node = it.second.first;
        int parent = it.second.second;

        if(vis[node] == 1) continue;
        
        vis[node] = 1;
        sum += wt;
        MST.push_back({parent, node});
        //E log E (log e for pushing into the pq)
        for(auto i : adj[node]){
            int adjNode = i[0];
            int adjWt = i[1];
            if(!vis[adjNode]){
                pq.push({adjWt,{adjNode,node}});
            }
        }
    }
    cout<<"sum is : "<<sum<<endl;
    return MST;
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

    vector<vector<int>> ans = solution(n , arr);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}
