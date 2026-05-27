#include<bits/stdc++.h>
using namespace std;

//TC -> O(2N?) + O(V + E)
//SC -> O(2N)
bool solution(int v, vector<int> arr[]){
    vector<int> inDegree(v,0);
    for(int i=0;i<v;i++){
        for(auto it : arr[i]){
            inDegree[it]++;
        }
    }

    queue<int> q;
    for(int i=0;i<v;i++){
        if(inDegree[i] == 0){
            q.push(i);
        }
    }

    int cnt = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cnt++;
        for(auto it : arr[node]){
            inDegree[it]--;
            if(inDegree[it] == 0) q.push(it);
        }
    }

    if(cnt == v) return false;
    return true;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> arr[n+1];
    for(int i=0;i<m;i++){
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v);
    }

    bool ans = solution(n , arr);
    if(ans) cout<<"1"<<endl;
    else cout<<"0"<<endl;
    return 0;
}