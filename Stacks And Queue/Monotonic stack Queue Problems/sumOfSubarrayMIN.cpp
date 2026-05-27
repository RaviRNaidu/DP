#include<bits/stdc++.h>
using namespace std;

//TC -> O(N^2)  sc->o(1)
int brute(vector<int> &arr, int n){
    int sum = 0;
    int mod = (int) (1e9 + 7);
    for(int i=0;i<n;i++){
        int mini = arr[i];
        for(int j=i;j<n;j++){
            mini = min(mini, arr[j]);
            sum += mini % mod;
        }
    }
    return sum;
}

//TC -> O(2N)   SC -> O(2N)
vector<int> findingNSE(vector<int> &arr){
    stack<int> st;
    int n = arr.size();
    vector<int> nse(n);
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }
        if(st.empty()){
            nse[i] = n;
        }
        else{
            nse[i] = st.top();
        }
        st.push(i);
    }
    return nse;
}

//TC -> O(2N)   SC -> O(2N)
vector<int> findingPSE(vector<int> &arr){
    stack<int> st;
    int n = arr.size();
    vector<int> pse(n);
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()] > arr[i]){
            st.pop();
        }
        if(st.empty()){
            pse[i] = -1;
        }
        else{
            pse[i] = st.top();
        }
        st.push(i);
    }
    return pse;
}

//TC -> O(N)+O(2N)+O(2N) = O(5N)       SC -> O(2N)+O(2N) = O(4N)
int optimal(vector<int> &arr, int n){
    vector<int> pse = findingPSE(arr);
    vector<int> nse = findingNSE(arr);
    
    int total = 0;
    int mod = (int)(1e9+7);
    for(int i=0;i<n;i++){
        int left = i - pse[i];
        int right = nse[i] - i;
        total = (total + (left*right*(1ll)*arr[i]) % mod) % mod;
    }
    return total;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans = optimal(arr, n);
    cout<<ans<<endl;
    return 0;
}