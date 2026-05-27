#include <bits/stdc++.h>
using namespace std;

int brute(vector<int> &arr, int n){
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int mini = INT_MAX;
            int maxi = INT_MIN;
            for(int k=i;k<=j;k++){
                mini = min(mini, arr[k]);
                maxi = max(maxi, arr[k]);
            }
            ans += (maxi - mini);
        }
    }
    return ans;
}

//TC -> O(N^2)  SC -> O(1)
int brute2(vector<int> &arr, int n){
    int ans = 0;
    for(int i=0;i<n;i++){
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int j=i;j<n;j++){
            mini = min(mini, arr[j]);
            maxi = max(maxi, arr[j]);
            ans += (maxi - mini);
        }
    }
    return ans;
}









vector<int> findPLE(vector<int> &arr, int n){
    vector<int> ans(n);
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()] < arr[i]){
            st.pop();
        }
        if(st.empty()){
            ans[i] = -1;
        }
        else{
            ans[i] = st.top();
        }
        st.push(i);
    }
    return ans;
}

vector<int> findNLE(vector<int> &arr, int n){
    vector<int> ans(n);
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()] <= arr[i]){
            st.pop();
        }
        if(st.empty()){
            ans[i] = n;
        }
        else{
            ans[i] = st.top();
        }
        st.push(i);
    }
    return ans;
}

vector<int> findPSE(vector<int> &arr, int n){
    vector<int> ans(n);
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()] > arr[i]){
            st.pop();
        }
        if(st.empty()){
            ans[i] = -1;
        }
        else{
            ans[i] = st.top();
        }
        st.push(i);
    }
    return ans;
}

vector<int> findNSE(vector<int> &arr, int n){
    vector<int> ans(n);
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }
        if(st.empty()){
            ans[i] = n;
        }
        else{
            ans[i] = st.top();
        }
        st.push(i);
    }
    return ans;
}

int sumOfSubarrayMIN(vector<int> &arr, int n){
    vector<int> pse = findPSE(arr,n);
    vector<int> nse = findNSE(arr,n);

    int mod = (int)(1e9+7);
    int sum = 0;

    for(int i=0;i<n;i++){
        int Sleft = i - pse[i];
        int Sright = nse[i] - i;
        sum = (sum + (Sleft * Sright * arr[i] * 1LL) % mod) % mod;
    }

    return sum;
}

int sumOfSubarrayMAX(vector<int> &arr, int n){
    vector<int> ple = findPLE(arr,n);
    vector<int> nle = findNLE(arr,n);

    int mod = (int)(1e9+7);
    int sum = 0;

    for(int i=0;i<n;i++){
        int Lleft = i - ple[i];
        int Lright = nle[i] - i;
        sum = (sum + (Lleft * Lright * arr[i] * 1LL) % mod) % mod;
    }

    return sum;
}

//OPTIMALL
int optimal(vector<int> &arr, int n){
    return (sumOfSubarrayMAX(arr, n) - sumOfSubarrayMIN(arr,n));
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans = brute2(arr, n);
    cout<<ans<<endl;
    return 0;
}