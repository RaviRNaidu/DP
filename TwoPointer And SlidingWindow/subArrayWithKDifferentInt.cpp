#include<bits/stdc++.h>
using namespace std;

int brute(vector<int> &arr, int n, int k){
    set<int> st;
    int ans = 0;
    for(int i=0;i<n;i++){
        st.clear();
        for(int j=i;j<n;j++){
            st.insert(arr[j]);
            if(st.size() > k){
                break;
            }
            if(st.size() == k){
                ans++;
            }
        }
    }
    return ans;
}

int finding(vector<int> &arr, int n, int k){
    if(k < 0) return 0;
    int cnt = 0;
    int l = 0; int r = 0;
    unordered_map<int, int> mpp;
    while(r < n){
        mpp[arr[r]]++;
        while(mpp.size() > k){
            mpp[arr[l]]--;
            if(mpp[arr[l]] == 0){
                mpp.erase(arr[l]);
            }
            l++;
        }
        cnt += r-l+1;
        r++;
    }
    return cnt;
}

int optimal(vector<int> &arr, int n, int k){
    return finding(arr,n,k) - finding(arr,n,k-1);
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
    int ans = optimal(arr,n,k);
    cout<<ans<<endl;
    return 0;
}