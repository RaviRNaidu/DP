#include<bits/stdc++.h>
using namespace std;

//U CAN ALSO COMBINE BOTH INTO ONE
//TC -> O(4 alpha)
class DisjointSet{
    vector<int> parent, rank;

    public:
    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }

    int findUPar(int node){
        if(parent[node] == node){
            return node;
        }

        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v){
        int u_up = findUPar(u);
        int v_up = findUPar(v);
        if(u_up == v_up) return;

        if(rank[u_up] > rank[v_up]){
            parent[v_up] = u_up;
        }
        else if(rank[u_up] < rank[v_up]){
            parent[u_up] = v_up;
        }
        else{
            parent[v_up] = u_up;
            rank[u_up]++;
        }
    }
};

//TC -> O(4 alpha)
class disjointSetBySize{
    vector<int> parent, size;
    public:
    disjointSetBySize(int n){
        parent.resize(n+1);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
        size.resize(n+1,1);
    }

    int findUPar(int node){
        if(node == parent[node]){
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

int main(){
    disjointSetBySize ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    //check if 3 and 7 are same component or not
    if(ds.findUPar(3) == ds.findUPar(7)){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    ds.unionBySize(3, 7);
    if(ds.findUPar(3) == ds.findUPar(7)){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}