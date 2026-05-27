#include<bits/stdc++.h>
using namespace std;

void mark_row(vector<vector<int>> &arr, int i, int m){
    for(int j=0;j<m;j++){
        if(arr[i][j] != 0){
            arr[i][j] = -1;
        }
    }
}
void mark_column(vector<vector<int>> &arr, int j, int n){
    for(int i=0;i<n;i++){
        if(arr[i][j] != 0){
            arr[i][j] = -1;
        }
    }
}
vector<vector<int>> brute(vector<vector<int>> &arr, int n, int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] == 0){
                mark_row(arr, i, m);
                mark_column(arr,j,n);
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] == -1){
                arr[i][j] = 0;
            }
        }
    }
    return arr;
}

vector<vector<int>> better(vector<vector<int>> &arr, int n, int m){
    int row[n] = {0};
    int col[m] = {0};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] == 0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(row[i] || col[j] == 1){
                arr[i][j] = 0;
            }
        }
    }
    return arr;
}

vector<vector<int>> optimall(vector<vector<int>> &arr, int n, int m){
    int col = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] == 0){
                arr[i][0] = 0;
                if(j != 0){
                    arr[0][j];
                }
                else{
                    col = 0;
                }
            }
        }
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(arr[i][0] == 0 || arr[0][j] == 0){
                arr[i][j] = 0;
            }
        }
    }

    for(int j=0;j<m;j++){
        if(arr[0][0] == 0){
            arr[0][j] = 0;
        }
    }

    for(int i=0;i<n;i++){
        if(col == 0){
            arr[i][0] = 0;
        }
    }
    return arr;
}












//spiralll
void spirall(vector<vector<int>> &arr, int n, int m){
    int left = 0;
    int right = m-1;
    int up = 0;
    int down = n-1;
    while(left <= right && up <= down){
        //left to right
        for(int i=left;i<=right;i++){
            cout<<arr[up][i]<<" ";
        }
        up++;
        //from up to down
        for(int i=up;i<=down;i++){
            cout<<arr[i][right]<<" ";
        }
        right--;
        //from right to left
        if(up <= down){
            for(int i=right;i>=left;i--){
                cout<<arr[down][i]<<" ";
            }
        }
        down--;
        //from down to up
        if(left <= right){
            for(int i=down;i>=up;i--){
                cout<<arr[i][left]<<" ";
            }
        }
        left++;
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
    spirall(arr, n, m);
    // vector<vector<int>> ans = optimall(arr, n, m);
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<ans[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return 0;
}