#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> &arr, int n, int m, vector<int> &interval){
    vector<vector<int>> ans;
    int i=0;
    //LEFT PART
    while(i < n && arr[i][1] < interval[0]){
        ans.push_back(arr[i]);
        i++;
    }

    //OVERLAPPING PART
    while(i < n && arr[i][0] <= interval[1]){
        interval[0] = min(interval[0],arr[i][0]);
        interval[1] = max(interval[1],arr[i][1]);
        i++;
    }

    ans.push_back(interval);

    //RIGHT PART
    while(i < n){
        ans.push_back(arr[i]);
        i++;
    }

    return ans;
}

int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<vector<int>> arr(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    vector<int> interval(2);
    for(int i=0;i<2;i++){
        cin>>interval[i];
    }
    vector<vector<int>> ans = solution(arr,n,m,interval);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}