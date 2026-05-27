#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> &arr, int n){
    vector<vector<int>> ans;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        int start = arr[i][0];
        int last = arr[i][1];
        if(!ans.empty() && ans.back()[1] >= last){
            continue;
        }
        for(int j=i+1;j<n;j++){
            if(arr[j][0] <= last){
                last = max(last,arr[j][1]);
            }
            else{
                break;
            }
        }
        ans.push_back({start,last});
    }
    return ans;
}

vector<vector<int>> solution2(vector<vector<int>> &arr, int n){
    vector<vector<int>> ans;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        if(!ans.empty() && arr[i][0] <= ans.back()[1]){
            ans.back()[1] = max(ans.back()[1],arr[i][1]);
        }
        else{
            ans.push_back(arr[i]);
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> arr(n,vector<int>(2));
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            cin>>arr[i][j];
        }
    }
    vector<vector<int>> ans = solution2(arr,n);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<2;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}