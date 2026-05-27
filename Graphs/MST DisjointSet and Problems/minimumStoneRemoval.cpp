#include<bits/stdc++.h>
using namespace std;

class disjointSet{
    vector<int> parent, size;

    public:
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


int maxRemoval(int n, vector<vector<int>> &stones){
    int maxRow = 0;
    int maxCol = 0;
    for(auto it : stones){
        maxRow = max(maxRow, it[0]);
        maxCol = max(maxCol, it[1]);
    }

    // take + 1 for saftey
    disjointSet ds(maxRow + maxCol + 2);

    //used to store all the nodes where stones were present. 
    //this will help us to determine the total components
    //how? we will just call the ultimate parent for each node and if up is him itself then we will increment the cnt  
    unordered_map<int,int> stoneNodes;
    for(auto it : stones){
        int rowNode = it[0];
        int colNode = it[1] + maxRow + 1;
        ds.unionBySize(rowNode, colNode);
        stoneNodes[rowNode] = 1;
        stoneNodes[colNode] = 1;
    }

    int components = 0;
    for(auto it : stoneNodes){
        if(ds.findUPar(it.first) == it.first){
            components++;
        }
    }

    return n - components;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> arr(n, vector<int> (2));
    for(int i=0;i<n;i++){
        cin>>arr[i][0];
        cin>>arr[i][1];
    }

    int ans = maxRemoval(n, arr);
    cout<<ans<<endl;
    return 0;
}