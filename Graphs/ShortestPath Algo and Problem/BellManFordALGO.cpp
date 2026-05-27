#include<bits/stdc++.h>
using namespace std;


//TC -> V * E
vector<int> solution(vector<vector<int>> &arr, int v, int s){
    vector<int> dis(v,1e9);
    dis[s] = 0;
    //need to perform for n-1 iterations
    for(int i=0;i<v-1;i++){
        for(auto it : arr){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if(dis[u] != 1e9 && wt + dis[u] < dis[v]){
                dis[v] = wt + dis[u];
            }
        }
    }
    
    // this part is used to identify if there exists a negative cycle
    // even in the worst case after n-1 iteration we will have all the shortest path
    //so here if we find a better or shorter path even after n-1 iteration then we can clearly say that there is a negative cycle
    for(auto it : arr){
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if(dis[u] != 1e9 && dis[u] + wt < dis[v]){
            return {-1};
        }
    }
    return dis;
}


int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(m, vector<int> (3));
    for(int i=0;i<m;i++){
        for(int j=0;j<3;j++){
            cin>>arr[i][j];
        }
    }
    int src;
    cin>>src;
    vector<int> ans = solution(arr, n, src);
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}