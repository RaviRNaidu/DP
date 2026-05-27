#include<bits/stdc++.h>
using namespace std;


//TC -> O(E log V)
// n * m * 4 * log(n*m)

//sc -> o(n*m) + pq space
int solution(vector<vector<int>> &arr, int n, int m){
    int drow[] = {-1,0,1,0};
    int dcol[] = {0,1,0,-1};
    vector<vector<int>> minEffort(n,vector<int> (m, 1e9));
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    minEffort[0][0] = 0;
    pq.push({0,{0,0}});
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int maxEff = it.first;
        int row = it.second.first;
        int col = it.second.second;

        if((row == n-1) && (col == m-1)){
            return maxEff;
        }

        for(int i=0;i<4;i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m){
                int newEffort = max(abs(arr[row][col] - arr[nrow][ncol]), maxEff);
                if(newEffort < minEffort[nrow][ncol]){
                    pq.push({newEffort, {nrow,ncol}});
                    minEffort[nrow][ncol] = newEffort;
                }
            }
        }
    }
    return 0;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    int ans = solution(arr, n,m);
    cout<<ans<<endl;
    return 0;
}