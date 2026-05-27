#include<bits/stdc++.h>
using namespace std;

long long pascallDigit(int r, int c){
    long long ans = 1;
    for(int i=0;i<c;i++){
        ans = ans * (r - i);
        ans = ans / (i + 1);
    }
    return ans;
}

void pascallRow(int n){
    int ans = 1;
    cout<<ans<<" ";
    for(int i=1;i<n;i++){
        ans = ans * (n - i);
        ans = ans / (i);
        cout<<ans<<" ";
    }
}

vector<int> pascallRow1(int n){
    vector<int> temp;
    long long ans = 1;
    temp.push_back(ans);
    for(int i=0;i<n;i++){
        ans = ans * (n - i);
        ans = ans / (i);
        temp.push_back(ans);
    }
    return temp;
}

vector<vector<int>> pascalTriangle(int n){
    vector<vector<int>> finalans;
    for(int i=1;i<=n;i++){
        finalans.push_back(pascallRow1(i));
    }
    return finalans;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> ans = pascalTriangle(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<ans[i].size();j++){  //make sure u give ans[i].size() instead of n
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}