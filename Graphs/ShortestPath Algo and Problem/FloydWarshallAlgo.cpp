#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> solution(vector<vector<int>> &arr){
    int n = arr.size();

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j] == -1){
                arr[i][j] = 1e9;
            }

            if(i == j) arr[i][j] = 0;
        }
    }

    for(int via=0;via<n-1;via++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                arr[i][j] = min(arr[i][j], arr[i][via] + arr[via][j]);
            }
        }
    }

    //to check if negative cycle exists
    for(int i=0;i<n;i++){
        if(arr[i][i] < 0) 
        {
            cout<<"YES"<<endl;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j] == 1e9){
                arr[i][j] = -1;
            }
        }
    }
    return arr;
}


int main(){
    int n;
    cin>>n;
    vector<vector<int>> arr(n, vector<int> (n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    vector<vector<int>> ans = solution(arr);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}