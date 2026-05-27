#include <bits/stdc++.h>
using namespace std;

//tc --> o(n*m)
int brute(vector<vector<int>> &arr, int n, int m){
    int maxcnt = -1;
    int index = -1;
    for(int i=0;i<n;i++){
        int cnt = 0;
        for(int j=0;j<m;j++){
            cnt += arr[i][j];
        }
        if(cnt > maxcnt){
            maxcnt = cnt;
            index = i;
        }
    }
    return index;
}

//tc --> o(n * log base2 m)
int optimal(vector<vector<int>> &arr, int n, int m){
    int finalans = INT_MIN;
    int index = -1;
    for(int i=0;i<n;i++){
        int ans = 0;
        int low = 0;
        int high = m-1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(arr[i][mid] >= 1){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        ans = m - low;
        if(ans > finalans){
            finalans = ans;
            index = i;
        }
    }
    return index;
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
    cout<<optimal(arr, n, m)<<endl;
    return 0;
}