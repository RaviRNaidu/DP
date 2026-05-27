#include<bits/stdc++.h>
using namespace std;

void spiralprinting(vector<vector<int>> &arr, int n, int m){
    int left = 0;
    int bottom = m-1;
    int right = n-1;
    int top = 0;

    while(top <= bottom && left <= right){
        //right
        for(int i = left;i<=right;i++){
            cout<<arr[top][i]<<" ";
        }
        top ++;
        //down
        for(int i=top;i<=bottom;i++){
            cout<<arr[i][right]<<" ";
        }
        right --;
        //left
        if(top <= bottom){
            for(int i=right;i>=left;i--){
                cout<<arr[bottom][i]<<" ";
            }
            bottom --;
        }
        //top
        if(left <= right){
            for(int i=bottom;i>=top;i--){
                cout<<arr[i][left]<<" ";
            }
            left ++;
        }
    }
}

int main(){
    int n,m;
    cin>>n;
    cin>>m;
    vector<vector<int>> arr(n,vector<int>(m)); 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    spiralprinting(arr, n, m);
    return 0;
}