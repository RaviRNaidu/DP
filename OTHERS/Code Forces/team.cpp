#include<bits/stdc++.h>
using namespace std;

int totalAnsSolved(vector<vector<int>> &arr, int n){
    int ans = 0;
    for(int i=0;i<n;i++){
        int cnt = 0;
        for(int j=0;j<3;j++){
            if(arr[i][j] == 1){
                cnt++;
            }
        }
        if(cnt >= 2){
            ans++;
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> questions(n,vector<int>(3));
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>questions[i][j];
        }
    }
    int ans = totalAnsSolved(questions, n);
    cout<<ans<<endl;
    return 0;
}