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

vector<vector<string>> accountMerge(vector<vector<string>> &account){
    int n = account.size();
    disjointSet ds(n);

    unordered_map<string,int> mpp;
    for(int i=0;i<n;i++){
        for(int j=1;i<account[i].size();i++){
            string mail = account[i][j];
            if(mpp.find(mail) != mpp.end()){
                ds.unionBySize(mpp[mail],i);
            }
            else{
                mpp[mail] = i;
            }
        }
    }

    vector<string> mergedMail[n];
    for(auto it : mpp){
        string mail = it.first;
        int node = ds.findUPar(it.second);
        mergedMail[node].push_back(mail);
    }

    vector<vector<string>> ans;

    for(int i=0;i<n;i++){
        if(mergedMail[i].size() == 0) continue;
        sort(mergedMail[i].begin(), mergedMail[i].end());
        vector<string> temp;
        temp.push_back(account[i][0]);
        for(auto it : mergedMail[i]){
            temp.push_back(it);
        }
        ans.push_back(temp);
    }
    return ans;
}