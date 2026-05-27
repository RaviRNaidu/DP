#include<bits/stdc++.h>
using namespace std;

int minLength(vector<int>& nums, int k) {
    set<int> st;
    int n = nums.size();
    for(int i=0;i<n;i++){
        st.insert(nums[i]);
    }

    int ans = 0;
    int sum = 0;
    while(sum < k){
        for(auto it = st.rbegin(); it != st.rend(); ++it){
            sum += *it;
            ans = ans + 1;
        }
    }

    if(sum < k) return -1;

    return ans;
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
    int ans = minLength(arr, k);
    cout<<ans<<endl;
    return 0;
}