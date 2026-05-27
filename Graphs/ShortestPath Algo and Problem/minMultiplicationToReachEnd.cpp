#include<bits/stdc++.h>
using namespace std;


int solution(vector<int> &arr, int n, int src, int end){
    int mod = 1000000;
    vector<int> dis(99999,1e9);
    dis[src] = 0;
    queue<pair<int, int>> q;
    q.push({0, src});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int steps = it.first;
        int num = it.second;

        for(int i=0;i<n;i++){
            int newNum = (num * arr[i]) % mod;
            if(steps + 1 < dis[newNum]){
                dis[newNum] = steps + 1;
                if(newNum == end) return steps + 1;
                q.push({steps + 1, newNum});
            }
        }
    }
    return -1;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int src, end;
    cin >> src >> end;
    int ans = solution(arr, n, src, end);
    cout<<ans<<endl;
    return 0;
}