#include<bits/stdc++.h>
using namespace std;

//tc o(n^3) and sc o(1)
int brute(vector<int> &arr, int n, int target){
    int finalcnt = 0;
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int zorr = 0;
            for(int k=i;k<=j;k++){
                zorr = zorr ^ arr[k];
            }
            if(zorr == target){
                cnt += 1;
            }
        }
        finalcnt = max(finalcnt, cnt);
    }
    return finalcnt;
}

//tc o(n^2) and sc o(1)
int better(vector<int> &arr, int n, int target){
    int finalcnt = 0;
    int cnt = 0;
    for(int i=0;i<n;i++){
        int zorr = 0;
        for(int j=i;j<n;j++){
            zorr = zorr ^ arr[j];
            if(zorr == target){
                cnt += 1;
            }
        }
        finalcnt = max(finalcnt, cnt);
    }
    return finalcnt;
}

//tc o(n) unordered map and o(n log n) for map  and sc o(n)
int optimall(vector<int> &arr, int n,int target){
    map<int,int> mpp;
    int count = 0;
    int zorr = 0;
    mpp[zorr]++;
    for(int i=0;i<n;i++){
        zorr = zorr ^ arr[i];
        int rem = target ^ zorr;
        if(mpp.find(rem) != mpp.end()){
            count = count + mpp[rem];
        }

        mpp[zorr]++;
    }
    return count;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int target;
    cin>>target;
    int ans = optimall(arr,n,target);
    cout<<ans;
    return 0;
}