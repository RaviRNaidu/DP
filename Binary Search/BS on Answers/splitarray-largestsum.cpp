#include <bits/stdc++.h>
using namespace std;

int check(vector<int> &arr, int maxArr){
    int cnt = 1;
    int total = arr[0];
    for(int i=1;i<arr.size();i++){
        if(total + arr[i] <= maxArr){
            total += arr[i];
        }
        else{
            cnt += 1;
            total = arr[i];
        }
    }
    return cnt;
}

//tc --> o(n) + o((sum - maxi + 1) * n)  sc --> o(1)
int brute(vector<int> &arr, int n, int k){
    int maxi = INT_MIN;
    int sum = 0;
    for(int i=0;i<n;i++){
        maxi = max(maxi,arr[i]);
        sum += arr[i];
    }

    for(int i=maxi;i<=sum;i++){
        int cnt = check(arr, i);
        if(cnt == k){
            return i;
        }
    }
    return -1;
}

//tc --> o(log base2 sum-maxi * n) sc --> o(1)
int optimal(vector<int> &arr, int n, int k){
    int maxi = INT_MIN;
    int sum = 0;
    for(int i=0;i<n;i++){
        maxi = max(maxi,arr[i]);
        sum += arr[i];
    }

    int low = maxi;
    int high = sum;
    while(low <= high){
        int mid = (low + high) / 2;
        int cnt = check(arr, mid);
        if(cnt <= k){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return low;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k; 
    cin>>k;
    cout<<optimal(arr, n, k);
    return 0;
}


//its the same code for the painters problem also
class Solution {
    int check(vector<int> &arr, int maxArr, int time){
    int cnt = 1;
    int total = (arr[0]*time);
    for(int i=1;i<arr.size();i++){
        if(total + (arr[i]*time) <= maxArr){
            total += (arr[i]*time);
        }
        else{
            cnt += 1;
            total = (arr[i]*time);
        }
    }
    return cnt;
}
public:
    int paint(int k, int B, vector<int>& arr) {
        int n = arr.size();
        int maxi = INT_MIN;
        int sum = 0;
        for(int i=0;i<n;i++){
            maxi = max(maxi,arr[i]);
            sum += arr[i];
        }

        int low = maxi;
        int high = sum;
        while(low <= high){
            int mid = (low + high) / 2;
            int cnt = check(arr, mid*B, B);
            if(cnt <= k){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low*B;
    }
};