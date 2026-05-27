#include <bits/stdc++.h>
using namespace std;

//tc --> o(n+m)  sc --> 0(n+m)
int brute(vector<int> &arr1, int n, vector<int> &arr2, int m, int target){
    vector<int> ans;
    int left = 0;
    int right = 0;
    while(left < n && right < m){
        if(arr1[left] <= arr2[right]){
            ans.push_back(arr1[left]);
            left++;
        }
        else {
            ans.push_back(arr2[right]);
            right++;
        }
    }
    while(left < n){
        ans.push_back(arr1[left]);
        left++;
    }
    while(right < m){
        ans.push_back(arr2[right]);
        right++;
    }
    return (ans[target-1]);
}

//tc --> o(n+m)  sc --> 0(1)
int better(vector<int> &arr1, int n, vector<int> &arr2, int m, int target){
    int left = 0;
    int right = 0;
    int cnt = 0;
    while(left < n && right < m){
        if(arr1[left] <= arr2[right]){
            cnt += 1;
            if(cnt == target){
                return arr1[left];
            }
            left++;
        }
        else {
            cnt += 1;
            if(cnt == target){
                return arr2[right];
            }
            right++;
        }
    }
    while(left < n){
        cnt += 1;
        if(cnt == target){
            return arr1[left];
        }
        left++;
    }
    while(right < m){
       cnt += 1;
        if(cnt == target){
            return arr2[right];
        }
        right++;
    }
    return 0;
}

int optimal(vector<int> &arr1, int n, vector<int> &arr2, int m, int target){
    if(m < n) return optimal(arr2, m, arr1, n, target);
    int low = max(0, target - m);
    int high = min(target, n);
    while(low <= high){
        int mid1 = (low + high) / 2;
        int mid2 = target - mid1;
        int l1 = INT_MIN , l2 = INT_MIN;
        int r1 = INT_MAX , r2 = INT_MAX;
        if(mid1 > 0) l1 = arr1[mid1 - 1];
        if(mid2 > 0) l2 = arr2[mid2 - 1];
        if(mid1 < n) r1 = arr1[mid1];
        if(mid2 < m) r2 = arr2[mid2];
        if(l1 < r2 && l2 < r1){
            return (max(l1,l2));
        }
        else if(l1 > r2){
            high = mid1 - 1;
        }
        else{
            low = mid1 + 1;
        }
    }
    return 0;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr1(n);
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    int m;
    cin>>m;
    vector<int> arr2(m);
    for(int i=0;i<m;i++){
        cin>>arr2[i];
    }
    int k;
    cin>>k;
    cout<<optimal(arr1, n, arr2, m, k);
    return 0;
}