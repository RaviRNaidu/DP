#include<bits/stdc++.h>
using namespace std;

int solution(int n, int m, vector<vector<int>> &arr, int threshold){
    vector<vector<int>> dist(n, vector<int> (n, 1e9));
    for(auto it : arr){
        dist[it[0]][it[1]] = it[2];
        dist[it[1]][it[0]] = it[2];
    }
    for(int i=0;i<n;i++){
        dist[i][i] = 0; 
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][k] == 1e9 || dist[k][j] == 1e9) continue;
                dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]);
            }
        }
    }
    int cntCity = n;
    int city = -1;
    for(int i=0;i<n;i++){
        int cnt = 0;
        for(int j=0;j<n;j++){
            if(dist[i][j] <= threshold) cnt++;
        }
        if(cnt <= cntCity){
            cntCity = cnt;
            city = i;
        }
    }
    return city;
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> arr(n, vector<int> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    int t;
    cin>>t;
    int ans = solution(n, m, arr, t);
    cout<<ans<<endl;
    return 0;
}