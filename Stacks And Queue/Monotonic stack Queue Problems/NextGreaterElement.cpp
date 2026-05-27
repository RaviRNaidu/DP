#include<bits/stdc++.h>
using namespace std;

//TC -> O(N^2)  SC -> O(N)
vector<int> brute(vector<int> &arr, int n){
    vector<int> ans(n,-1);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j] > arr[i]){
                ans[i] = arr[j];
                break;
            }
        }
    }
    return ans;
}

//OPTIMAL STRIVER
//TC -> O(N) + O(N)     SC -> O(N) + o(n)
vector<int> optimalStriver(vector<int> &arr, int n){
    stack<int> st;
    vector<int> ans(n);
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && st.top() <= arr[i]){
            st.pop();
        }
        if(st.empty()){
            ans[i] = -1;
        }
        else{
            ans[i] = st.top();
        }
        st.push(arr[i]);
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

    vector<int> ans = optimalStriver(arr, n);
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}