#include<bits/stdc++.h>
using namespace std;

    long long maximumScore(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSum(n);
        vector<int> suffixMin(n);

        prefixSum[0] = nums[0];
        for(int i=1;i<n;i++){
            prefixSum[i] = prefixSum[i-1]+nums[i];
        }

        suffixMin[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffixMin[i] = min(suffixMin[i+1],nums[i]);
        }

        long long ans = INT_MIN;
        for(int i=0;i<n-1;i++){
            long long sum = prefixSum[i] - suffixMin[i+1];
            
            if(sum > ans){
                ans = sum;
            }
        }

        return ans;
    }


    int main(){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        long long ans = maximumScore(arr);
        cout<<ans<<endl;
        return 0;
    }