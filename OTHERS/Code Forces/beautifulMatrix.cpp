#include<bits/stdc++.h>
using namespace std;

int finding(vector<vector<int>> &matrix){
    int row = -1;
    int col = -1;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(matrix[i][j] == 1){
                row = i;
                col = j;
            }
        }
    }

    int ans = 0;
    while(row != 2){
        if(row < 2){
            row++;
            ans++;
        }
        else{
            row--;
            ans++;
        }
    }

    while(col != 2){
        if(col < 2){
            col++;
            ans++;
        }
        else{
            col--;
            ans++;
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> matrix(5, vector<int> (5));
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin>>matrix[i][j];
        }
    }

    int ans = finding(matrix);
    cout<<ans<<endl;
    return 0;
}