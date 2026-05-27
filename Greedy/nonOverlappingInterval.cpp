// #include<bits/stdc++.h>
// using namespace std;

// bool comp(arr, Data b){
//     return (a.end < b.end);
// }

// //TC -> O(2N + N LOG N) SC -> O(3*N) + O(N)if u want to return the order
// int solution(vector<vector<int>> &arr,int n, int m){
//     sort(arr, arr+n, comp);
//     int cnt = 0;
//     int endTime = 0;
//     for(int i=0;i<n;i++){
//         if(arr[i][0] > endTime){
//             cnt++;
//             endTime = arr[i][1];
//         }
//     }
//     return n-cnt;
// }

// int main(){
//     int n;
//     cin>>n;
//     int m;
//     cin>>m;
//     vector<vector<int>> arr(n,vector<int>(m));
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cin>>arr[i][j];
//         }
//     }
//     int ans = solution(arr,n,m);
//     cout<<ans<<endl;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

class Solution {
public: 
    // Function to find the minimum number of intervals to remove to make all intervals non-overlapping
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // Sort intervals based on their end time (greedy strategy)
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a[1] < b[1];
        });

        // Count of intervals to remove
        int count = 0;

        // Store end time of the last non-overlapping interval
        int prevEnd = intervals[0][1];

        // Iterate through intervals starting from the second
        for (int i = 1; i < intervals.size(); i++) {

            // If current interval starts before the last accepted interval ends
            if (intervals[i][0] < prevEnd) {
                // Overlapping interval, increase removal count
                count++;
            } else {
                // No overlap, update the end of last accepted interval
                prevEnd = intervals[i][1];
            }
        }

        // Return minimum intervals to remove
        return count;
    }
};
// Driver Code
int main() {
    Solution sol;

    // Example input intervals
    vector<vector<int>> intervals = {{1, 3}, {2, 4}, {3, 5}, {1, 2}};

    // Call the function and print result
    cout << "Minimum number of intervals to remove: " << sol.eraseOverlapIntervals(intervals) << endl;
    return 0;
}
