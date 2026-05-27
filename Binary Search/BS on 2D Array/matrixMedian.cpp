#include <bits/stdc++.h>
using namespace std;

//tc --> o(n*m) + o(n*m log(n*m))  sc --> o(n*m)
int brute(vector<vector<int>> &arr, int n, int m){
    vector<int> ans;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans.push_back(arr[i][j]);
        }
    }
    sort(ans.begin(),ans.end());
    return ans[n*m/2];
}


int upper(vector<int> &arr, int target){
    int n = arr.size();
    int low = 0;
    int high = n-1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] <= target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return low;
}

int blackbox(vector<vector<int>> &arr, int x){
    int n = arr.size();
    int cnt = 0;
    for(int i=0;i<n;i++){
        cnt += upper(arr[i], x);
    }
    return cnt;
}
//tc --> o(n) + o(log base2 n*m ) * (n * log base2 m)  sc--> o(1)
int optimal(vector<vector<int>> &arr, int n, int m){
    int low = -1;
    int high = -1;
    for(int i=0;i<n;i++){
        if(arr[i][0] < low){
            low = arr[i][0];
        }
        if(arr[i][m-1] > high){
            high = arr[i][m-1];
        }
    }

    int required = (n*m) / 2;
    while(low <= high){
        int mid = (low + high) / 2;
        int totalOccurance = blackbox(arr, mid);
        if(totalOccurance <= required){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return low;
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
    cout<<brute(arr, n, m);
    return 0;
}