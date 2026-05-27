#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> arr[], vector<int> &vis, stack<int> &st){
    vis[node] = 1;
    for(auto it : arr[node]){
        if(!vis[it]){
            dfs(it, arr, vis, st);
        }
    }
    st.push(node);
}


//SC -> O(2N)
//TC -> O(N) + O(V + E)
vector<int> solution(int v, vector<int> arr[]){
    vector<int> vis(v,0);
    stack<int> st;
    for(int i=0;i<v;i++){
        if(!vis[i]){
            dfs(i, arr, vis, st);
        }
    }

    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
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