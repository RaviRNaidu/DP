#include<bits/stdc++.h>
using namespace std;

int recursion(int day, int prev, vector<vector<int>> &arr){
    if(day == 0){
        int maxi = 0;
        for(int i=0;i<3;i++){
            if(i != prev){
                maxi = max(maxi, arr[day][i]);
            }
        }
        return maxi;
    }

    int sum = 0;
    for(int i=0;i<3;i++){
        if(i != prev){
            int points = arr[day][i] + recursion(day - 1, i, arr);
            sum = max(sum, points);
        }
    }

    return sum;
}

//TC -> O(N * 3 * 4)
//SC -> O(N * 4) + O(N)
int memoization(int day, int prev, vector<vector<int>> &arr, vector<vector<int>> &dp){
    if(day == 0){
        int maxi = 0;
        for(int i=0;i<3;i++){
            if(i != prev){
                maxi = max(maxi, arr[day][i]);
            }
        }
        return dp[day][prev] = maxi;
    }

    if(dp[day][prev] != -1) return dp[day][prev];

    int sum = 0;
    for(int i=0;i<3;i++){
        if(i != prev){
            int points = arr[day][i] + memoization(day - 1, i, arr, dp);
            sum = max(sum, points);
        }
    }

    return dp[day][prev] = sum;
}

//TC -> O(N * 3 * 4)
//SC -> O(N * 4)
int tabulation(int finalDay, vector<vector<int>> &arr, vector<vector<int>> &dp){
    for(int i=0;i<4;i++){
        int maxi = 0;
        for(int j=0;j<3;j++){
            if(j != i){
                maxi = max(maxi, arr[0][j]);
            }
        }
        dp[0][i] = maxi;
    }

    for(int day=1;day<=finalDay;day++){
        for(int last=0;last<4;last++){
            int maxi = 0;
            for(int task=0;task<3;task++){
                if(task != last){
                    int points = arr[day][task] + dp[day-1][task];
                    maxi = max(maxi, points);
                }
            }
            dp[day][last] = maxi;
        }
    }

    return dp[finalDay][3];
}

//TC -> O(N * 4 * 3)
//SC -> O(4 + 4)
int spaceOptimization(int finalDay, vector<vector<int>> &arr){
    vector<int> prev(4);
    prev[0] = max(arr[0][1], arr[0][2]);
    prev[1] = max(arr[0][0], arr[0][2]);
    prev[2] = max(arr[0][0], arr[0][1]);
    prev[3] = max(arr[0][0], max(arr[0][1], arr[0][2]));

    for(int day=1;day<=finalDay;day++){
        vector<int> temp(4);
        for(int last=0;last<4;last++){
            int maxi = 0;
            for(int task=0;task<3;task++){
                if(task != last){
                    int points = arr[day][task] + prev[task];
                    maxi = max(maxi, points);
                }
            }
            temp[last] = maxi;
        }
        prev = temp;
    }

    return prev[3];
}


int ninjaTraining(vector<vector<int>> &arr, int n){
    vector<vector<int>> dp(n , vector<int> (4, -1));
    cout<<memoization(n-1, 3, arr, dp)<<endl;
    cout<<tabulation(n-1, arr, dp)<<endl;
    cout<<spaceOptimization(n-1, arr)<<endl;
    return recursion(n-1, 3, arr);
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> arr(n, vector<int> (3));
    for(int i=0;i<n;i++){
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
    }
    int ans = ninjaTraining(arr, n);
    cout<<ans<<endl;
    return 0;
}