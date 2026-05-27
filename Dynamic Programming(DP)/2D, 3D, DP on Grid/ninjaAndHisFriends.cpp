#include<bits/stdc++.h>
using namespace std;

//TC -> 9^N*M
//SC -> N
int recursion(int i, int j1, int j2, vector<vector<int>> &arr, int n, int m){
    if(j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) return -1e8;
    if(i == n-1){
        if(j1 == j2) return arr[i][j1];
        else return arr[i][j1] + arr[i][j2];
    }

    int maxi = -1e8;
    //THIS IS BECAUSE FOR EACH STATE OF ALEX WE HAVE 3 DIFFERENT STATES OF BOB
    //SO ITS LIKE 3 * 3
    //WE CAN MANNUALLY TRY OUT ALL THE PATHS AND THEN RETURN THE MAX
    //THIS IS WHAT IT MEANS WHEN THEY SAY TRY OUT ALL THE POSSIBLE WAYS IE 3 WAYS FOR EACH STATE OF BOB
    for(int dj1 = -1; dj1 <= 1; dj1++){
        for(int dj2 = -1; dj2 <= 1; dj2++){
            int value = 0;
            if(j1 == j2) {
                value = arr[i][j1];
            }
            else{
                value = arr[i][j1] + arr[i][j2];
            }
            value += recursion(i+1,j1+dj1,j2+dj2, arr, n, m);
            maxi = max (maxi, value); 
        }
    }

    return maxi;
}

//TC -> N*M*M*9
//SC -> N + N*M*M
int memoization(int i, int j1, int j2, vector<vector<int>> &arr, int n, int m, vector<vector<vector<int>>> &dp){
    if(j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) return -1e8;
    if(i == n-1){
        if(j1 == j2) return dp[i][j1][j2] = arr[i][j1];
        else return dp[i][j1][j2] = arr[i][j1] + arr[i][j2];
    }

    if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

    int maxi = -1e8;
    //THIS IS BECAUSE FOR EACH STATE OF ALEX WE HAVE 3 DIFFERENT STATES OF BOB
    //SO ITS LIKE 3 * 3
    //WE CAN MANNUALLY TRY OUT ALL THE PATHS AND THEN RETURN THE MAX
    //THIS IS WHAT IT MEANS WHEN THEY SAY TRY OUT ALL THE POSSIBLE WAYS IE 3 WAYS FOR EACH STATE OF BOB
    for(int dj1 = -1; dj1 <= 1; dj1++){
        for(int dj2 = -1; dj2 <= 1; dj2++){
            int value = 0;
            if(j1 == j2) {
                value = arr[i][j1];
            }
            else{
                value = arr[i][j1] + arr[i][j2];
            }
            value += memoization(i+1,j1+dj1,j2+dj2, arr, n, m, dp);
            maxi = max (maxi, value); 
        }
    }

    return dp[i][j1][j2] = maxi;
}

//TC -> N*M*M*9
//SC -> N * M * M
int tabulation(vector<vector<int>> &arr, int n, int m, vector<vector<vector<int>>> &dp){
    for(int j1=0;j1<m;j1++){
        for(int j2=0;j2<m;j2++){
            if(j1 == j2){
                dp[n-1][j1][j2] = arr[n-1][j1];
            }
            else{
                dp[n-1][j1][j2] = arr[n-1][j1] + arr[n-1][j2];
            }
        }
    }

    for(int i = n-2; i >= 0; i++){
        for(int j1 = 0; j1 < m; j1++){
            for(int j2 = 0; j2 < m; j2++){
                //THESE ARE THE VARIOUS STATES THAT U CAN GENERATE FOR EACH ROW 
                //SO WE JUST COPY THE SAME THING WHICH WE DID IN THE RECURRENCE
                int maxi = -1e8;
                for(int dj1 = -1; dj1 <= 1; dj1++){
                    for(int dj2 = -1; dj2 <= 1; dj2++){
                        int value = 0;
                        if(j1 == j2) {
                            value = arr[i][j1];
                        }
                        else{
                            value = arr[i][j1] + arr[i][j2];
                        }
                        if(j1 + dj1 >= 0 && j1 + dj1 < m && j2 + dj2 >= 0 && j2 + dj2 < m) value += dp[i+1][j1+dj1][j2+dj2];
                        else value = -1e9;
                        maxi = max (maxi, value); 
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }

    return dp[0][0][m-1];
}

//TC -> N*M*M*9
//SC -> 2 * M * M
int spaceOptimization(vector<vector<int>> &arr, int n, int m){
    vector<vector<int>> front(m, vector<int> (m,0));
    for(int j1=0;j1<m;j1++){
        for(int j2=0;j2<m;j2++){
            if(j1 == j2){
                front[j1][j2] = arr[n-1][j1];
            }
            else{
                front[j1][j2] = arr[n-1][j1] + arr[n-1][j2];
            }
        }
    }

    for(int i = n-2; i >= 0; i++){
        vector<vector<int>> curr(m, vector<int> (m,0));
        for(int j1 = 0; j1 < m; j1++){
            for(int j2 = 0; j2 < m; j2++){
                //THESE ARE THE VARIOUS STATES THAT U CAN GENERATE FOR EACH ROW 
                //SO WE JUST COPY THE SAME THING WHICH WE DID IN THE RECURRENCE
                int maxi = -1e8;
                for(int dj1 = -1; dj1 <= 1; dj1++){
                    for(int dj2 = -1; dj2 <= 1; dj2++){
                        int value = 0;
                        if(j1 == j2) {
                            value = arr[i][j1];
                        }
                        else{
                            value = arr[i][j1] + arr[i][j2];
                        }
                        if(j1 + dj1 >= 0 && j1 + dj1 < m && j2 + dj2 >= 0 && j2 + dj2 < m) value += front[j1+dj1][j2+dj2];
                        else value = -1e9;
                        maxi = max (maxi, value); 
                    }
                }
                curr[j1][j2] = maxi;
            }
        }
        front = curr;
    }

    return front[0][m-1];
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> arr(n, vector<int> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    // vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (m,-1)));
    // vector<vector<vector<int>>> dp1(n, vector<vector<int>> (m, vector<int> (m,0)));
    // int ans = recursion(0,0,m-1,arr,n, m);
    // cout<<memoization(0,0,m-1,arr,n, m, dp)<<endl;
    // cout<<tabulation(arr,n,m,dp1)<<endl;
    cout<<spaceOptimization(arr, n, m)<<endl;
    // cout<<ans<<endl;
}