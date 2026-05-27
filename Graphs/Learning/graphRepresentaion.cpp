#include<bits/stdc++.h>
using namespace std;

//UNDIRECTED GRAPH REPRESENTED IN ADJACENCY MATRIX
//n -> nodes    m -> edges
//tc -> o(n^2)
int main(){
    int n, m;
    cin>> n >> m;
    //GRAPH IS STORED HERE!!
    int adj[n+1][n+1];
    for(int i=0;i<m;i++){
        int u, v;
        cin>> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    return 0;
}


//SC -> O(2E)
//storing in a list!!
//UNDIRECTED GRAPH
int main(){
    int n , m;
    cin>> n >> m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u, v;
        cin>> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return 0;
}


//SC -> O(E)
//storing in a list!!
//DIRECTED GRAPH
int main(){
    int n , m;
    cin>> n >> m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u, v;
        // u ---> v
        cin>> u >> v;
        adj[u].push_back(v);
    }
    return 0;
}












//WEIGHTED GRAPH!!!
int main(){
    int n, m;
    cin>> n >> m;
    //GRAPH IS STORED HERE!!
    int adj[n+1][m+1];
    for(int i=0;i<m;i++){
        int u, v;
        cin>> u >> v;
        adj[u][v] = 0;
        adj[v][u] = 0;
    }
    return 0;
}