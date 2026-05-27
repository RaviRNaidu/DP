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
        for(int k=0;k<i;k++){
            if(ans[i] == -1 && arr[k] > arr[i]){
                ans[i] = arr[k];
                break;
            }
        }
    }
    return ans;
}

//TC -> O(N^2)  SC -> O(N)
vector<int> better(vector<int> &arr, int n){
    vector<int> ans(n,-1);
    for(int i=0;i<n;i++){
        for(int j=i;j<i+n;j++){
            int index = j % n;
            if(arr[index] > arr[i]){
                ans[i] = arr[index];
                break;
            }
        }
    }

    return ans;
}

//TC -> O(4N)   SC -> O(2N) + O(N)this is needed to return the ans
vector<int> optimal(vector<int> &arr, int n){
    stack<int> st;
    vector<int> ans(n);
    for(int i=(2*n)-1;i>=0;i--){                //TC -> O(2N)
        int index = i % n;
        while(!st.empty() && st.top() <= arr[index]){   //TC -> O(2N) either one of them
            st.pop();
        }
        if(i < n){
            if(st.empty()){
                ans[i] = -1;
            }
            else{
                ans[i] = st.top();
            }
        }
        st.push(arr[index]);        //TC -> O(2N)   either one of them
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

    vector<int> ans = optimal(arr, n);
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}