#include<bits/stdc++.h>
using namespace std;

//ME
vector<int> solution(int v, vector<int> arr[]){
    vector<int> adj[v];
    for(int i=0;i<v;i++){
        for(auto it : arr[i]){
            adj[it].push_back(i);
        }
    }

    vector<int> inDegree(v,0);
    for(int i=0;i<v;i++){
        for(auto it : adj[i]){
            inDegree[it]++;
        }
    }

    queue<int> q;
    for(int i=0;i<v;i++){
        if(inDegree[i] == 0){
            q.push(i);
        }
    }

    vector<int> ans;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for(auto it : adj[node]){
            inDegree[it]--;
            if(inDegree[it] == 0) q.push(it);
        }
    }

    sort(ans.begin(),ans.end());
    return ans;
}

//striver
vector<int> solution(int v, vector<int> arr[]){
    vector<int> adj[v];
    vector<int> inDegree(v,0);
    for(int i=0;i<v;i++){
        for(auto it : arr[i]){
            adj[it].push_back(i);
            inDegree[i]++;
        }
    }

    queue<int> q;
    for(int i=0;i<v;i++){
        if(inDegree[i] == 0){
            q.push(i);
        }
    }

    vector<int> ans;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for(auto it : adj[node]){
            inDegree[it]--;
            if(inDegree[it] == 0) q.push(it);
        }
    }

    sort(ans.begin(),ans.end());
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