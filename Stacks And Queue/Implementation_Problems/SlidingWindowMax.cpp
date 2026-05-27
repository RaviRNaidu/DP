#include<bits/stdc++.h>
using namespace std;

//TC -> O(N-K) * O(K)       SC -> O(N-K)
vector<int> brute(vector<int> &arr, int n, int k){
    vector<int> ans;
    for(int i=0;i<=n-k;i++){
        int maxi = arr[i];
        // if(window > n) return ans;
        for(int j=i;j<=(i+k-1);j++){
            maxi = max(maxi,arr[j]);
        }
        ans.push_back(maxi);
    }
    return ans;
}


//TC -> O(N) + O (N)        SC -> O(K) + O(N-K)
vector<int> optimal(vector<int> &arr, int n, int k){
    vector<int> ans;
    deque<int> dq;
    for(int i=0;i<n;i++){
        if(!dq.empty() && dq.front() <= i-k){
            dq.pop_front();
        }
        while(!dq.empty() && arr[dq.back()] <= arr[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        if(i >= k-1){
            ans.push_back(arr[dq.front()]);
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<int> ans = optimal(arr, n, k);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}