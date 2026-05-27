#include<bits/stdc++.h>
using namespace std;

//TC -> O(N^2)  SC -> O(1)
int brute(vector<int> &arr, int n, vector<int> &dep, int m){
    int maxCnt = 0;
    for(int i=0;i<n;i++){
        int cnt = 1;
        for(int j=i+1;j<n;j++){
            if(){
                cnt++;
            }
            maxCnt = max(maxCnt, cnt);
        }
    }
    return maxCnt;
}

//TC -> O(N LOG N + N LOG N + 2N) or 2(N LOG N + N)    SC -> O(1)
int striver(vector<int> &arr, int n, vector<int> &dep, int m){
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    int i = 0;
    int j = 0;
    int cnt = 0; int maxCnt = 0;
    while(i < n){
        if(arr[i] <= dep[j]){
            cnt++;
            i++;
        }
        else{
            cnt--;
            j++;
        }
        maxCnt = max(maxCnt, cnt);
    }
    return maxCnt;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int m;
    cin>>m;
    vector<int> dep(m);
    for(int i=0;i<m;i++){
        cin>>dep[i];
    }
    int ans = striver(arr,n,dep,m);
    cout<<ans<<endl;
    return 0;
}