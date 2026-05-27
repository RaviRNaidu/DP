#include<bits/stdc++.h>
using namespace std;

//tc o(n log n + 2n) sc o(n)
vector<vector<int>> brute(vector<vector<int>> &arr,int n){
    vector<vector<int>> ans;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        int start = arr[i][0];
        int end = arr[i][1];
        if(!ans.empty() && end <= ans.back()[1]){
            continue;
        }
        for(int j=i+1;j<n;j++){
            if(arr[j][0] <= end){
                end = max(end, arr[j][1]);
            }
            else{
                break;
            }
        }
        ans.push_back({start,end});
    }
    return ans;
}


//tc o(n log n + n) sc o(n)
vector<vector<int>> optimalll(vector<vector<int>> &arr,int n){
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for(int i=0;i<n;i++){
        if(ans.empty() || arr[i][0] > ans.back()[1]){
            ans.push_back(arr[i]);
        }
        else{
            ans.back()[1] = max(ans.back()[1],arr[i][1]);
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> intervals(n,vector<int>(2));
    for(int i=0;i<n;i++){
        cin>>intervals[i][0]>>intervals[i][1];
    }
    vector<vector<int>> ans = optimalll(intervals, n);
    for(auto it: ans){
        cout<<"["<<it[0]<<","<<it[1]<<"]"<<" ";
    }
    return 0;
}