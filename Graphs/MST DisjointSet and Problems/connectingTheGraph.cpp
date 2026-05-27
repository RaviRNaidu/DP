#include<bits/stdc++.h>
using namespace std;

class disjointSet{
    //o(2n)
    public:
    vector<int> parent, size;
    disjointSet(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }

    int findUPar(int node){
        if(parent[node] == node){
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v){
        int up_u = findUPar(u);
        int up_v = findUPar(v);

        if(up_u == up_v) return;

        if(size[up_u] < size[up_v]){
            parent[up_u] = up_v;
            size[up_v] += size[up_u];
        }
        else{
            parent[up_v] = up_u;
            size[up_u] += size[up_v];
        }
    }
};


//TC -> O(M + N) 
//SC -> O(2N)
int solution(int n, int m, vector<vector<int>> &arr){
    disjointSet ds(n);
    int extra = 0;
    for(int i=0;i<m;i++){
        int u = arr[i][0];
        int v = arr[i][1];
        if(ds.findUPar(u) == ds.findUPar(v)){   
            extra++;
        }
        ds.unionBySize(u, v);
    }

    int component = 0;
    for(int i=0;i<n;i++){
        if(ds.parent[i] == i){
            component++;
        }
    }
    if(component - 1 > extra) return -1;
    return component - 1;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr;
    for(int i=0;i<m;i++){
        int u, v;
        cin >> u >> v;
        arr.push_back({u,v});
    }

    int ans = solution(n , m, arr);
    cout<<ans<<endl;
    return 0;
}