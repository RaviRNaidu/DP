#include<bits/stdc++.h>
using namespace std;

//TC -> O(N + N + E) + O(N) + O(N) BUT HE SAID IT IS O(V + E)
//SC -> O(2N)
vector<int> solution(int v, vector<int> arr[]){
    vector<int> inDegree(v,0);
    for(int i=0;i<v;i++){
        for(auto it : arr[i]){
            inDegree[it] += 1;
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
        for(auto it : arr[node]){
            inDegree[it]--;
            if(inDegree[it] == 0) q.push(it);
        }
        ans.push_back(node);
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